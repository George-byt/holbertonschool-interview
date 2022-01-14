#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: the array 1 to be sum
 * @grid2: the array 2 to be sum
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int grid1_is_stable = 1, i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			if (grid1[i][j] > 3)
				grid1_is_stable = 0;
		}
	}

	if (!grid1_is_stable)
	{
		printf("=\n");
		_print_grid(grid1);
		sandpile_stabilization(grid1);
	}
}

/**
 * sandpile_stabilization - stabilize a sandpiles
 * @grid1: array to stabilize
 */
void sandpile_stabilization(int grid1[3][3])
{
	int i, j, start, end, grains, sandpile_is_stable = 1, temp_grid1[3][3];

	copy_array_int(grid1, temp_grid1);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grains = 0;
			/* Evaluate rows */
			start = i == 0 ? i : i - 1;
			end = i == 2 ? i : i + 1;

			for (; start <= end; start++)
			{
				if (start != i && temp_grid1[start][j] > 3)
					grains++;
			}
			/* Evaluate columns */
			start = j == 0 ? j : j - 1;
			end = j == 2 ? j : j + 1;

			for (; start <= end; start++)
			{
				if (start != j && temp_grid1[i][start] > 3)
					grains++;
			}

			grid1[i][j] = grid1[i][j] > 3 ?
				grid1[i][j] - 4 + grains : grid1[i][j] + grains;
			sandpile_is_stable = grid1[i][j] > 3 ?
				0 : sandpile_is_stable;
		}
	}
	if (!sandpile_is_stable)
	{
		printf("=\n");
		_print_grid(grid1);
		sandpile_stabilization(grid1);
	}
}

/**
 * _print_grid - print sandpiles
 * @grid: print grid
 */
void _print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * copy_array_int - copy array
 * @grid: origin array
 * @temp_grid: copy array
 */
void copy_array_int(int grid[3][3], int temp_grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			temp_grid[i][j] = grid[i][j];
		}
	}
}
