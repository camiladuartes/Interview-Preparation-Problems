#!/bin/python3

import math
import os
import random
import re
import sys

def alternatingCharacters(s):
    previous = s[0]
    deletions = 0
    for i in range(1, len(s)):
        if(previous == s[i]):
            deletions += 1
        else:
            previous = s[i]
    
    return deletions

