#!/usr/bin/python3
"""
Print stats from server's logs
"""
import sys


def print_stats(file_size_total, status_codes):
    """Print the stats"""
    print("File size: {}".format(file_size_total))
    [print("{}: {}".format(code, status_codes[code]))
     for code in sorted(status_codes.keys()) if status_codes[code] != 0]


def get_data_from_stdin():
    """Get data form standard input"""
    status_codes = {"200": 0, "301": 0, "400": 0,
                    "401": 0, "403": 0, "404": 0, "405": 0, "500": 0}
    file_size_total = 0
    line_counts = 0
    try:
        while True:
            try:
                line = input()
                data = line.split()
                if data and len(data) > 2:
                    line_counts += 1
                    file_size_total += int(data[-1])
                    try:
                        status_codes[data[-2]] += 1
                    except Exception:
                        pass
                if line_counts >= 10:
                    print_stats(file_size_total, status_codes)
                    line_counts = 0
            except EOFError:
                if line_counts < 10:
                    print_stats(file_size_total, status_codes)
                break
    except KeyboardInterrupt:
        print_stats(file_size_total, status_codes)


if __name__ == "__main__":
    get_data_from_stdin()
