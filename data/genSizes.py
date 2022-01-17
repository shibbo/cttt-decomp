import os, sys

LAST_FUNC_END = 0x6BEF28

with open("main.map", "r") as f:
    lines = f.readlines()

output = []

for i in range(len(lines)):
    line_split = lines[i].split("=")
    func_name = line_split[1].replace("\n", "")
    func_addr = line_split[0]
    # remove 0000007100
    func_addr = func_addr[10:]

    next_func_addr = 0
    if i == len(lines) - 1:
        next_func_addr = LAST_FUNC_END
    else:
        next_addr = lines[i + 1].split("=")[0]
        next_addr = next_addr[10:]
        next_func_addr = int(next_addr, 16)

    func_size = next_func_addr - int(func_addr, 16)
    output.append(f"{func_name}={func_size}\n")

with open("funcSizes.txt", "w") as w:
    w.writelines(output)