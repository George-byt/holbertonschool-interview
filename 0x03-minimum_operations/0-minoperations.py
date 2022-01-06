#!/usr/bin/python3

"""Minimum Operations
In a text file, there is a single character H. Your text editor can execute
only two operations in this file: Copy All and Paste. Given a number n,
write a method that calculates the fewest number of operations needed to
result in exactly n H characters in the file
"""


def minOperations(n):
    """
    Description:
    Method that calculates the fewest number of operations needed to result
    in exactly n H characters in the file.
    return: Returns an integer, f n is impossible to achieve, return 0
    """

    if type(n) != int or n <= 1 or n is None:
        return 0

    divisor = 2
    minimum_operations = 0

    while n >= divisor:

        if n % divisor == 0:
            minimum_operations += divisor
            n /= divisor

        else:
            divisor += 1
    return minimum_operations