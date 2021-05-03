# Time:  O(n^2)
# Space: O(n)

class Solution(object):
    def splitString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        def backtracking(s, i, num, cnt):
            if i == len(s):
                return cnt >= 2
            new_num = 0
            for j in xrange(i, len(s)):
                new_num = new_num*10 + int(s[j])
                if new_num >= num >= 0:
                    break
                if (num == -1 or num-1 == new_num) and backtracking(s, j+1, new_num, cnt+1):
                    return True
            return False
            
        return backtracking(s, 0, -1, 0)
