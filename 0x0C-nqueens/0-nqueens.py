#!/usr/bin/python3
"""The N Queens Problem"""
if __name__ == '__main__':

    import sys

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        size = int(sys.argv[1])
    except BaseException:
        print("N must be a number")
        sys.exit(1)
    if size < 4:
        print("N must be at least 4")
        sys.exit(1)

    def startSolve():
        data = [[0 for j in range(size)] for i in range(size)]
        checkRecursive(data, 0)
        return

    def checkRecursive(data, c):
        if (c == size):
            solution(data)
            return True
        ret = False
        for i in range(size):
            if (checkPosition(data, i, c)):
                data[i][c] = 1
                ret = checkRecursive(data, c + 1) or ret
                data[i][c] = 0
        return ret

    def checkPosition(data, r, c):
        for i in range(c):
            if (data[r][i]):
                return False
        i = r
        j = c
        while i >= 0 and j >= 0:
            if(data[i][j]):
                return False
            i = i - 1
            j = j - 1
        i = r
        j = c
        while j >= 0 and i < size:
            if(data[i][j]):
                return False
            i = i + 1
            j = j - 1
        return True

    def solution(data):
        solve = []
        for i in range(size):
            for j in range(size):
                if(data[i][j] is 1):
                    solve.append([i, j])
        print(solve)
        solve.clear()
    startSolve()
