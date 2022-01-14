#ifndef _SANDPILES_H
#define _SANDPILES_H

#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void sandpile_stabilization(int grid1[3][3]);
void _print_grid(int grid[3][3]);
void copy_array_int(int grid[3][3], int temp_grid[3][3]);

#endif
