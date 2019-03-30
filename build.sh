#flags wie -march sind nur drinne damit der compiler strenger ist :D
gcc -o c5_hw1_ostep c5_hw1_ostep.c -Wall -Werror -Wextra -Wpedantic -Wpedantic -pedantic-errors -fopenmp -O0 -march=native -mstackrealign -mfpmath=both
gcc -o c5_hw2_ostep c5_hw2_ostep.c -Wall -Werror -Wextra -Wpedantic -Wpedantic -pedantic-errors -fopenmp -O0 -march=native -mstackrealign -mfpmath=both
gcc -o c5_hw3_ostep c5_hw3_ostep.c -Wall -Werror -Wextra -Wpedantic -Wpedantic -pedantic-errors -fopenmp -O0 -march=native -mstackrealign -mfpmath=both

