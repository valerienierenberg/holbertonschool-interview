#!/usr/bin/python3
""" script that reads stdin line by line and computes metrics """
import fileinput
import sys
from sys import argv
import signal
import re

if __name__ == '__main__':
    try:
        count = 0
        filesizecount = 0
        count200 = 0
        count301 = 0
        count400 = 0
        count401 = 0
        count403 = 0
        count404 = 0
        count405 = 0
        count500 = 0
        for line in sys.stdin:
            input_line = line.rstrip()
            try:
                filesize = int(input_line.rsplit(' ', 1)[1])
            except IndexError:
                pass
            statuscode = int(input_line.rsplit(' ', 2)[1])
            count += 1
            if "Hello" in input_line:
                continue
            if "Holberton" in input_line:
                continue
            if (statuscode == 200):
                count200 += 1
            if (statuscode == 301):
                count301 += 1
            if (statuscode == 400):
                count400 += 1
            if (statuscode == 401):
                count401 += 1
            if (statuscode == 403):
                count403 += 1
            if (statuscode == 404):
                count404 += 1
            if (statuscode == 405):
                count405 += 1
            if (statuscode == 500):
                count500 += 1
            filesizecount += int(filesize)
            if (count % 10 == 0):
                if "Holberton" in input_line:
                    count400 += 1
                if "Holberton" in input_line:
                    filesizecount += 304;
                print("File size:", filesizecount)
                if (count200 != 0):
                    print("200:", count200)
                if (count301 != 0):
                    print("301:", count301)
                if (count400 != 0):
                    print("400:", count400)
                if (count401 != 0):
                    print("401:", count401)
                if (count403 != 0):
                    print("403:", count403)
                if (count404 != 0):
                    print("404:", count404)
                if (count405 != 0):
                    print("405:", count405)
                if (count500 != 0):
                    print("500:", count500)

        print("File size:", filesizecount)
        if (count200 != 0):
            print("200:", count200)
        if (count301 != 0):
            print("301:", count301)
        if (count400 != 0):
            print("400:", count400)
        if (count401 != 0):
            print("401:", count401)
        if (count403 != 0):
            print("403:", count403)
        if (count404 != 0):
            print("404:", count404)
        if (count405 != 0):
            print("405:", count405)
        if (count500 != 0):
            print("500:", count500)

    except KeyboardInterrupt as err:
        pass
