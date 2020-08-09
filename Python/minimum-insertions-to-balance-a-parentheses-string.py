# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minInsertions(self, s):
        """
        :type s: str
        :rtype: int
        """
        add, bal = 0, 0
        for c in s:
            if c == '(':
                if bal > 0 and bal%2:
                    add += 1
                    bal -= 1
                bal += 2
            else:
                bal -= 1
                if bal < 0:
                    add += 1
                    bal += 2
        return add + bal
