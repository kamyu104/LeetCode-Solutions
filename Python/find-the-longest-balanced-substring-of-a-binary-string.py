# Time:  O(n)
# Space: O(1)

# two pointers
class Solution(object):
    def findTheLongestBalancedSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        for i in xrange(len(s)):
            left, right = i+1, i
            while left-1 >= 0 and right+1 < len(s) and s[left-1] == '0' and s[right+1] == '1':
                left -= 1
                right += 1
            result = max(result, right-left+1)
        return result


# Time:  O(n)
# Space: O(1)
# string
class Solution2(object):
    def findTheLongestBalancedSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        prev, cnt = [0]*2, [0]*2
        for c in s:
            cnt[int(c)] += 1
            if cnt[int(c)^1]:
                prev[int(c)^1], cnt[int(c)^1] = cnt[int(c)^1], 0
            result = max(result, 2*min(prev[0], cnt[1]))
        return result
