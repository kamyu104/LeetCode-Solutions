# Time:  O(n * b), n is the length of gene string, b is size of bank
# Space: O(b)

# A gene string can be represented by an 8-character long string, 
# with choices from "A","C","G","T". 
# Suppose we need to investigate about a mutation (mutation from "start" to "end"), 
# where ONE mutation is defined as ONE single character changed in the gene string. 
# For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation. 
# Also, there is a given gene "bank", which records all the valid gene mutations.
# A gene must be in the bank to make it a valid gene string. 
#
# Now, given 3 things - start, end, bank,
# your task is to determine what is the minimum number of mutations needed to
# mutate from "start" to "end". If there is no such a mutation, return -1. 
#
# NOTE: 1. Starting point is assumed to be valid, so it might not be included in the bank.
#       2. If multiple mutations are needed, all mutations during in the sequence must be valid.
#
# For example, 
#     
# bank: "AACCGGTA" 
# start: "AACCGGTT" 
# end: "AACCGGTA" 
# return: 1
#
# bank: "AACCGGTA", "AACCGCTA", "AAACGGTA"
# start: "AACCGGTT"
# end: "AAACGGTA"
# return: 2
#
# bank: "AAAACCCC", "AAACCCCC", "AACCCCCC"
# start: "AAAAACCC"
# end: "AACCCCCC"
# return: 3

from collections import deque

class Solution(object):
    def minMutation(self, start, end, bank):
        """
        :type start: str
        :type end: str
        :type bank: List[str]
        :rtype: int
        """
        lookup = {}
        for b in bank:
            lookup[b] = False

        q = deque([(start, 0)])
        while q:
            cur, level = q.popleft()
            if cur == end:
                return level

            for i in xrange(len(cur)):
                for c in ['A', 'T', 'C', 'G']:
                    if cur[i] == c:
                        continue

                    next_str = cur[:i] + c + cur[i+1:]
                    if next_str in lookup and lookup[next_str] == False:
                        q.append((next_str, level+1))
                        lookup[next_str] = True

        return -1
