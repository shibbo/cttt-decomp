import zipfile
import urllib.request
import os
import sys
import subprocess

def install(what):
    subprocess.check_call([sys.executable, '-m', 'pip', 'install', what])

if not os.path.exists("cttt.nso"):
    print("cttt.nso does not exist. Place a SMG1 dol named baserom.dol in the root.")
    sys.exit(1)
else:
    print("Found cttt.nso...")

try:
    import capstone
    print("Found capstone, continuing...")
except ModuleNotFoundError:
    print("Module 'capstone' not installed. Installing...")
    install("capstone")

try:
    import elftools
    print("Found elftools, continuing...")
except ModuleNotFoundError:
    print("Module `elftools` not found. Installing...")
    install("pyelftools")

try:
    import lz4
    print("Found lz4, continuing...")
except ModuleNotFoundError:
    print("Module `lz4` not found. Installing...")
    install("lz4")

try:
    import ninja
    print("Found ninja, continuing...")
except ModuleNotFoundError:
    print("Module 'ninja' not found. Installing...")
    install("ninja")

try:
    import colorama
    print("Found colorama, continuing...")
except ModuleNotFoundError:
    print("Module 'colorama' not found. Installing...")
    install("colorama")

if not os.path.exists("deps"):
    print("Dependency folder not found, downloading...")

    with urllib.request.urlopen("http://shibboleet.us.to/cttt/deps.zip") as response, open("deps.zip", 'wb') as out:
        data = response.read()
        out.write(data)

    if os.path.exists("deps.zip"):
        os.mkdir("deps")
        print("Extracting file...")
        with zipfile.ZipFile("deps.zip", "r") as zip:
            zip.extractall("deps")

        os.remove("deps.zip")
    else:
        print("deps.zip failed to download.")
        sys.exit(1)

print("Done.")
sys.exit(1)