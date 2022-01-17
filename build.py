import subprocess
import sys
import os
import pathlib
import shutil

COMPILER_CMD = "-x c++ -std=gnu++14 -fno-common -fno-short-enums -ffunction-sections -fdata-sections -fPIC -mcpu=cortex-a57+fp+simd+crypto+crc -O3 -fomit-frame-pointer -Wall -g -I deps/Include -I deps/Common/Configs/Targets/NX-NXFP2-a64/Include -I include -DNN_NINTENDO_SDK -DNN_SDK_BUILD_RELEASE -c "
COMPILER_PATH = pathlib.Path("deps/Compilers/NX/nx/aarch64/bin/clang++.exe")

# todo -- implement ninja
tasks = list()

for root, dirs, files in os.walk("source"):
    for file in files:
        if file.endswith(".cpp"):
            source_path = os.path.join(root, file)
            build_path = source_path.replace("source", "build", 1).replace(".cpp", ".o")

            os.makedirs(os.path.dirname(build_path), exist_ok=True)
            tasks.append((source_path, build_path))

for task in tasks:
    source_path, build_path = task     

    print(f"Compiling {source_path}...")
    if subprocess.call(f"{COMPILER_PATH} {COMPILER_CMD} {source_path} -o {build_path}", shell=True) == 1:
            sys.exit(1)