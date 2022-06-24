#!/usr/bin/python3

import sys, os, re
import settings

def solution():
    av = sys.argv

    if len(av) != 2:
        print("not enough arg")
        exit(1)
    elif av[0] != "render.py" or av[1] != "myCV.template":
        print("arg not correct")
        exit(1)

    f = open("myCV.template", "r")
    html = f.read()
    fw = open("myCV.html", "w")
    html = html.format(**vars(settings))
    fw.write(html)
    f.close()
    fw.close()

if __name__ == '__main__':
    solution()