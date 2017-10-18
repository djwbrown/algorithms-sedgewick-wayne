#!/usr/bin/env python3
#
#  compare-sorts.py
#  Copyright (c) 2017 Dylan Brown. All rights reserved.
#

# Use Python 3. Run from within the scripts/ directory.

import os
import sys
import re
import subprocess

# Ensure we don't silently fail by running Python 2.
assert sys.version_info[0] >= 3, "This script requires Python 3.x"
assert os.getcwd().split("/")[-1] == "algorithms-sedgewick-wayne", \
    "This script must be run from the project's root directory."

# Number of iterations to average over.
N = 25

# Data file to sort.
# DATA = "./algs4-data/words3.txt"
DATA = "./algs4-data/medTale.txt"

def main():
    sorts = ["selection-sort",
             "insertion-sort",
             "shell-sort"]

    for sort in sorts:
        exe_path = "./build/{}".format(sort.rstrip())
        if not os.path.isfile(exe_path):
            raise OSError("The executable {} does not exist.".format(exe_path))

        accumulated_time = 0
        for i in range(N):
            # Note shell=True has security implications. Don't accept external inputs.
            b_output = subprocess.check_output(" ".join([exe_path, DATA]), shell=True)
            str_output = str(b_output)
            # Use regex to extract the number follwing "(ns) =" in the output.
            accumulated_time += int(re.findall("\d+", str_output)[0])  # Elapsed time in nanoseconds.
        average_time = accumulated_time / N

        if "selection-sort" == sort:
            print("{:>14} took {:>8} ns on average.".format(sort, int(average_time)))
            sel_sort_time = average_time
        else:
            print("{:>14} took {:>8} ns on average, "
                  "a {:4.1f}x speedup over selection sort.".format(sort,
                                                                  int(average_time),
                                                                  sel_sort_time / average_time))

if __name__ == "__main__":
    main()
