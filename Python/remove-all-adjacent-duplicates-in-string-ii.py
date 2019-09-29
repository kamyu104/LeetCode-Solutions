# Time:  O(n)
# Space: O(n)

class Solution(object):
    def removeDuplicates(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        stk = [['^', 0]]
        for c in s:
            if stk[-1][0] == c:
                stk[-1][1] += 1
                if stk[-1][1] == k:
                    stk.pop()
            else:
                stk.append([c, 1])
        return "".join(c*k for c, k in stk)
