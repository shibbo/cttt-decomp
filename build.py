import subprocess
import sys
import os
import pathlib
import shutil

COMPILER_CMD = "-x c++ -std=gnu++14 -fno-common -fno-short-enums -fdata-sections -fPIC -mcpu=cortex-a57+fp+simd+crypto+crc -O3 -fno-exceptions -fomit-frame-pointer -Wall -I deps/Include -I deps/Common/Configs/Targets/NX-NXFP2-a64/Include -I include -DNN_NINTENDO_SDK -DNN_SDK_BUILD_RELEASE -c "
COMPILER_PATH = pathlib.Path("deps/Compilers/NX/nx/aarch64/bin/clang++.exe")
OBJDUMP_PATH = pathlib.Path("deps/Compilers/NX/nx/aarch64/bin/aarch64-nintendo-nx-elf-objdump.exe")

# todo -- implement ninja
tasks = list()

for root, dirs, files in os.walk("source"):
    for file in files:
        if file.endswith(".cpp"):
            source_path = os.path.join(root, file)
            build_path = source_path.replace("source", "build", 1).replace(".cpp", ".o")
            map_path = build_path.replace("build", "map", 1).replace(".o", ".map")

            os.makedirs(os.path.dirname(build_path), exist_ok=True)
            os.makedirs(os.path.dirname(map_path), exist_ok=True)
            tasks.append((source_path, build_path, map_path))

for task in tasks:
    source_path, build_path, map_path = task     

    print(f"Compiling {source_path}...")
    if subprocess.call(f"{COMPILER_PATH} {COMPILER_CMD} {source_path} -o {build_path}", shell=True) == 1:
            sys.exit(1)

    mapFileOutput = subprocess.check_output([OBJDUMP_PATH, build_path, "-t"]).decode("utf-8").replace("\r", "")
    lines = mapFileOutput.split("\n")
   
    newOutput = []

    for line in lines:
        if line == '':
            continue

        if line.startswith("build") or line.startswith("SYMBOL TABLE"):
            continue

        more_split = line.split(" ")
        
        # if global, it is most likely a symbol
        if more_split[1] == "g":
            # symbol is always the last entry
            sym = more_split[(len(more_split) - 1)]
            newOutput.append(f"{sym}\n")
            

    with open(map_path, "w") as w:
        w.writelines(newOutput)
    