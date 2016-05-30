#!/usr/bin/python
# -*- coding: utf-8 -*-



import re

class Solution:
    # @return a boolean
    def isMatch(self, s, p):
        return re.match('^' + p + '$', s) != None

# debug
s = Solution()
print s.isMatch("aa", "a*")