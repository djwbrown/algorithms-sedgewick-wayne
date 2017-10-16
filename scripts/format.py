#!/usr/bin/env python3
#
#  format.py
#  Copyright (c) 2017 Dylan Brown. All rights reserved.
#

# NOTES
# Use Python 3. Run from the `build/` directory.

import os
import sys
import json

CLANG_FORMAT_EXE = "/usr/local/opt/llvm/bin/clang-format"

# Ensure we don't silently fail by running Python 2.
assert sys.version_info[0] >= 3, "This script requires Python 3.x"

# Ensure we're in the correct directory.
if os.getcwd().split("/")[-1] != "build" or "compile_commands.json" not in os.listdir():
    raise OSError("Run this from the build/ directory containing the file: compile_commands.json")

with open("compile_commands.json") as db_file:
    database = json.load(db_file)
files = [entry['file'] for entry in database]

# Make formatting changes in-place to all files.
for file in files:
    os.system(" ".join(["{}".format(CLANG_FORMAT_EXE),
                        "-i",
                        "-style=llvm",
                        "{}".format(file)]))
