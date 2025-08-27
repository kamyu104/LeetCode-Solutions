# Time:  O(n + 26)
# Space: O(26)

# freq table
class Solution(object):
    def filterCharacters(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        cnt = [0]*26
        for x in s:
            cnt[ord(x)-ord('a')] += 1
        return "".join(x for x in s if cnt[ord(x)-ord('a')] < k)
