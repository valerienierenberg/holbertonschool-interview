#!/usr/bin/python3
""" You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and each box
may contain keys to the other boxes. """

#!/usr/bin/python3
"""Determines if all boxes can be opened, beginning with 0"""


def canUnlockAll(boxes):
    keysDict = {
        0: True
    }
    # number of times going through the loop
    # need to keep track of this for while loop condition (to prevent infinite loop)
    loopIterations = 0

    # populate the rest of the dict to False values to start
    for i in range(1, len(boxes)):
        keysDict[i] = False

    # loop through all keys
    while False in keysDict.values() and trips < len(boxes):
        for i in keysDict:
            if keysDict[i] == True:
                for k in boxes[i]:
                    keysDict[k] = True
                loopIterations += 1

    # if there is still a False value anywhere in the dict, method returns false
    if False in keysDict.values():
        return False
    return True
