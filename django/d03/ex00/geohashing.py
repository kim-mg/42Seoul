#!/usr/bin/python3

import antigravity, sys

def solution():
    arg = sys.argv

    if len(arg) != 4:
        print("no 3 args")
        exit(1)
    else:
        antigravity.geohash(float(arg[1]), float(arg[2]), bytes(arg[3], "utf-8"))

if __name__=='__main__':
    solution()