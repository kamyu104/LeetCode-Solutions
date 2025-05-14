# Time:  O(n + 26)
# Space: O(n + 26)

# freq table, counting sort, greedy
class Solution(object):
    def minDeletion(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        cnt = [0]*26
        for x in s:
            cnt[ord(x)-ord('a')] += 1
        cnt2 = [0]*(max(cnt)+1)
        for x in cnt:
            cnt2[x] += 1
        result = 0
        total = 26-k
        for i, x in enumerate(cnt2):
            c = min(total, x)
            result += i*c
            total -= c
            if total == 0:
                break
        return result
