# Time:  O(n + 26)
# Space: O(26)

# freq table, greedy
class Solution(object):
    def lexSmallestAfterDeletion(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt = [0]*26
        for x in s:
            cnt[ord(x)-ord('a')] += 1
        result = []
        for x in s:
            while result and result[-1] > x and cnt[ord(result[-1])-ord('a')] != 1:
                cnt[ord(result[-1])-ord('a')] -= 1
                result.pop()
            result.append(x)
        while cnt[ord(result[-1])-ord('a')] != 1:
            cnt[ord(result[-1])-ord('a')] -= 1
            result.pop()
        return "".join(result)
