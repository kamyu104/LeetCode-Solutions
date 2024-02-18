# Time:  O(n)
# Space: O(1)

# freq table
class Solution(object):
    def lastNonEmptyString(self, s):
        """
        :type s: str
        :rtype: str
        """
        cnt = [0]*26
        for x in s:
            cnt[ord(x)-ord('a')] += 1
        mx = max(cnt)
        result = []
        for x in reversed(s):
            if cnt[ord(x)-ord('a')] != mx:
                continue
            cnt[ord(x)-ord('a')] -= 1
            result.append(x)
        return "".join(reversed(result))
