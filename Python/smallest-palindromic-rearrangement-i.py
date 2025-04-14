# Time:  O(n)
# Space: O(1)

# counting sort, greedy
class Solution(object):
    def smallestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt = [0]*26
        for x in s:
            cnt[ord(x)-ord('a')] += 1
        result = [chr(ord('a')+i)*(c//2) for i, c in enumerate(cnt) if c//2]
        if len(s)%2:
            result.append(s[len(s)//2])
        result.extend((result[i] for i in reversed(xrange(len(result)-len(s)%2))))
        return "".join(result)
