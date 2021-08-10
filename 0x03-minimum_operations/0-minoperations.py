#!/usr/bin/python3
""" program that calculates the minimum number of
    operations needed to result in exactly n H characters
    in the file
    (In a text file, there is a single character H.
    Your text editor can execute only two operations in this file:
    Copy All and Paste. Given a number n). """


def prime_factors(n):
    """ method to find the prime factors of a given number """
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors


def minOperations(n):
    """ method that calculates the minimum number of
    operations needed to result in exactly n H characters
    in the file """
    if n == 0 or n == 1:
        return 0
    else:
        factors_list = prime_factors(n)
        factorSum = sum(factors_list)
        return factorSum
