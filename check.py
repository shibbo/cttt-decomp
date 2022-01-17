import nso, sys
from capstone import *
from capstone.ppc import *

if len(sys.argv) < 2:
    print("python check.py symbol_name")
    sys.exit(1)

sym = sys.argv[1]

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

funcData = nso_file.getFunction(int(sym_map[sym]), int(func_sizes[sym]))
capstone_inst = Cs(CS_ARCH_ARM64, CS_MODE_ARM + CS_MODE_LITTLE_ENDIAN)
capstone_inst.detail = True

original_instrs = capstone_inst.disasm(funcData, 0)
