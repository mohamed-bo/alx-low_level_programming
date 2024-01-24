#!/usr/bin/python3
"""
Module island_perimeter
"""


def island_perimeter(grid):
    """
    island_perimeter function
    """
    perimeter = 0
    for i, row in enumerate(grid):
        for j, zone in enumerate(row):
            if zone == 1:
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1
                if i == len(grid) - 1 or grid[i + 1][j] == 0:
                    perimeter += 1
                if j == len(row) - 1 or grid[i][j + 1] == 0:
                    perimeter += 1
    return perimeter
