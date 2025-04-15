# Time:  O(n + 26)
# Space: O(26)

# freq table, counting sort, greedy
class Solution(object):
    def smallestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt = [0]*26
        for i in xrange(len(s)//2):
            cnt[ord(s[i])-ord('a')] += 1
        result = [chr(ord('a')+i)*c for i, c in enumerate(cnt)]
        if len(s)%2:
            result.append(s[len(s)//2])
        result.extend((result[i] for i in reversed(xrange(len(result)-len(s)%2))))
        return "".join(result)
