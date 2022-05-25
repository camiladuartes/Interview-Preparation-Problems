#!/bin/python3

import math
import os
import random
import re
import sys

def substrCount(n, s):
    # mnonopoo
    # m:1 n:1 o:1 n:1 o:1 p:1 o:2
    
    # aaaabbaac
    # a:4 b:2 a:2 c:1
    
    freq = []
    count = 0
    cur = None

    for i in range(n):
        if s[i] == cur:
            count += 1
        else:
            if cur is not None:
                freq.append((cur, count))
            cur = s[i]
            count = 1
    freq.append((cur, count))

    ans = 0
        
    for i in freq:
        ans += (i[1] * (i[1] + 1)) // 2

    for i in range(1, len(freq) - 1):
        if freq[i - 1][0] == freq[i + 1][0] and freq[i][1] == 1:
            ans += min(freq[i - 1][1], freq[i + 1][1])

    return ans
