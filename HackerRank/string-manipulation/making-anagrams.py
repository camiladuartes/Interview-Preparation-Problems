#!/bin/python3

import math
import os
import random
import re
import sys

def makeAnagram(a, b):
    sizeA = sizeB = deletions = 0
    a = sorted(a)
    b = sorted(b)
    while(sizeA < len(a) and sizeB < len(b)):
        if(a[sizeA] == b[sizeB]):
            sizeA += 1
            sizeB += 1
        elif(a[sizeA] < b[sizeB]):
            deletions += 1
            sizeA += 1
        else:
            deletions += 1
            sizeB += 1
    
    if(sizeA < len(a)):
        deletions += len(a) - sizeA
    elif(sizeB < len(b)):
        deletions += len(b) - sizeB
        
    return deletions

