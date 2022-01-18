import glob, nso, os, sys
from colorama import Fore, Style
from capstone import *
from elftools.elf.elffile import ELFFile

def getModule(sym):
    for root, dirs, files in os.walk("map"):
        for file in files:
            if file.endswith(".map"):
                map_path = os.path.join(root, file)
                with open(map_path, "r") as f:
                    lines = f.readlines()


                for line in lines:
                    fmt = line.replace("\n", "")
                    if fmt == sym:
                        # we found where our symbol lives!
                        # we just grab the source module
                        object_path = map_path.replace("map", "build", 1)
                        object_path = object_path.replace(".map", ".o")
                        return object_path
    return ""

if len(sys.argv) < 2:
    print("python check.py [-check-diff] symbol_name")
    sys.exit(1)

sym = sys.argv[2]
printDiff = False

if "-check-diff" in sys.argv:
    printDiff = True

func_sizes = { }
sym_map = { }

with open("data/funcSizes.txt", "r") as f:
    lines = f.readlines()

for line in lines:
    spl = line.split("=")
    func_sizes[spl[0]] = spl[1].replace("\n", "")

with open("data/main.map", "r") as f:
    lines = f.readlines()

for line in lines:
    spl = line.split("=")
    addr = spl[0]
    addr = addr[10:]
    name = spl[1].replace("\n", "")
    sym_map[name] = int(addr, 16)

if sym not in sym_map:
    print("Symbol not found.")
    sys.exit(1)

with open("cttt.nso", "rb") as f:
    nso_file = nso.NSO(f.read())

funcData = nso_file.getFunction(sym_map[sym], int(func_sizes[sym]))
capstone_inst = Cs(CS_ARCH_ARM64, CS_MODE_ARM + CS_MODE_LITTLE_ENDIAN)
capstone_inst.detail = True
capstone_inst.imm_unsigned = False

error_count = 0
warning_count = 0

original_instrs = list(capstone_inst.disasm(funcData, 0))

object_path = getModule(sym)
if object_path == "":
    print("Failed to find object.")
    sys.exit(1)

with open(object_path, "rb") as f:
    elf = f
    
    elf_file = ELFFile(elf)
    symtab = elf_file.get_section_by_name('.symtab')

    if symtab.get_symbol_by_name(sym) is None:
        print("Could not find symbol in object file. This may be caused by the code not being compiled, the function being in the wrong C++ source file or the function signature being wrong.")
        sys.exit(1)

    compiled_symbol = symtab.get_symbol_by_name(sym)[0]
    custom_offset = compiled_symbol["st_value"]
    custom_size = compiled_symbol['st_size']
    text = elf_file.get_section_by_name('.text')
    custom_data = text.data()[custom_offset:custom_offset + custom_size]
    custom_instructions = list(capstone_inst.disasm(custom_data, 0))

orig_length = len(list(original_instrs))
cust_length = len(list(custom_instructions))

if orig_length != cust_length:
    print("Custom function does not match the size of the original.")
    sys.exit(1)

instr_equal = True
regs_equal = True

for i in range(orig_length):
    curOrigInstr = original_instrs[i]
    curCustInstr = custom_instructions[i]

    orig_operands = curOrigInstr.operands
    cust_operands = curCustInstr.operands

    if str(original_instrs) == str(custom_instructions):
        if printDiff == True:
            print(f"{Fore.GREEN}{str(curOrigInstr):<80}{curCustInstr}{Style.RESET_ALL}")
        continue

    if curOrigInstr.id != curOrigInstr.id:
        print(f"{Fore.RED}{str(curOrigInstr):<80}{curCustInstr}{Style.RESET_ALL}")
        instr_equal = False
        break

    for j in range(len(orig_operands)):
        if orig_operands[j].reg != cust_operands[j]:
            print(f"{Fore.RED}{str(curOrigInstr):<80}{curCustInstr}{Style.RESET_ALL}")
            regs_equal = False
            break

if instr_equal == True and regs_equal == True:
    print("Function is matching! Marking as decompiled...")

    with open("data/functions.csv", "r") as f:
        csvData = f.readlines()

    outCsv = []

    for c in csvData:
        spl = c.split(",")
        if spl[1] == sym:
            outCsv.append(f"{spl[0]},{spl[1]},true\n")
        else:
            outCsv.append(c)

    with open("data/functions.csv", "w") as w:
        w.writelines(outCsv)

elif instr_equal == True and regs_equal == False:
    print("Function has a matching instruction, but operands are not equal.")
elif instr_equal == False and regs_equal == True:
    print("Function has matching operands, but instructions are not equal.")
elif instr_equal == False and regs_equal == False:
    print("Function does not match in either instructions or operands.")