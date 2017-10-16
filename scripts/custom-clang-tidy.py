#!/usr/bin/env python3
#
#  run-clang-tidy.py
#  Copyright (c) 2017 Dylan Brown. All rights reserved.
#

# NOTES
# Use Python 3. Run from the `build/` directory.
# A wrapper which calls the run-clang-tidy.py tool from the LLVM project.

import os

# Comma separated list of check flags.
# For example, "-*,readablity-*" means remove all checks and add back readability.
CHECKS = "*"
CLANG_TIDY_EXE = "/usr/local/opt/llvm/bin/clang-tidy"

# Ensure we're in the correct directory.
if os.getcwd().split("/")[-1] != "build" or "compile_commands.json" not in os.listdir():
    raise OSError("Run this from the build/ directory containing the file: compile_commands.json")

os.system(" ".join(["python2 ../scripts/run-clang-tidy.py",
                    "-clang-tidy-binary {}".format(CLANG_TIDY_EXE),
                    "-checks={}".format(CHECKS)]))
