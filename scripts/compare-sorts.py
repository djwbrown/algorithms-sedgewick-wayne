#
#  compare-sorts.py
#  Copyright (c) 2017 Dylan Brown. All rights reserved.
#

# Use Python 3. Run from within the scripts/ directory.

import os
import re
import subprocess

# Number of iterations to average over.
N = 100

# Data file to sort.
DATA = "../algs4-data/words3.txt"

def main():
    sorts = ["selection-sort",
             "insertion-sort"]

    for sort in sorts:
        exe_path = "../build/{}".format(sort)
        if not os.path.isfile(exe_path):
            raise OSError("The executable ../build/{} does not exist.".format(sort))

        accumulated_time = 0
        for i in range(N):
            # Note shell=True has security implications. Don't accept external inputs.
            b_output = subprocess.check_output(" ".join([exe_path, DATA]), shell=True)
            str_output = str(b_output)
            # Use regex to extract the number follwing "(ns) =" in the output.
            accumulated_time += int(re.findall("\d+", str_output)[0])  # Elapsed time in nanoseconds.
        average_time = accumulated_time / N

        if "selection-sort" == sort:
            print("{} took {} ns on average.".format(sort, int(average_time)))
            sel_sort_time = average_time
        else:
            print("{} took {} ns on average, "
                  "a {:.1f}x speedup over selection sort.".format(sort, int(average_time), sel_sort_time / average_time))

if __name__ == "__main__":
    main()
