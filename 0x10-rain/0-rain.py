#!/usr/bin/python3
""" calculate how many square units of water will be retained after rain
    Return: Integer indicating total amount of rainwater retained
    If the list is empty, return 0 """


def rain(walls):
    """ rain Method """
    if not walls:
        return 0
    left = [0] * len(walls)
    right = [0] * len(walls)
    left[0] = walls[0]
    right[-1] = walls[-1]
    for i in range(1, len(walls)):
        left[i] = max(left[i-1], walls[i])
    for i in range(len(walls)-2, -1, -1):
        right[i] = max(right[i+1], walls[i])
    total = 0
    for i in range(len(walls)):
        total += min(left[i], right[i]) - walls[i]
    return total
