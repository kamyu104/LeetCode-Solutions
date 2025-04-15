# Time:  O(26 * n)
# Space: O(26)

# freq table, counting sort, greedy, combinatorics
class Solution(object):
    def smallestPalindrome(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        cnt = [0]*26
        for i in xrange(len(s)//2):
            cnt[ord(s[i])-ord('a')] += 1
        total, count, remain = 0, 1, 0
        for i in reversed(xrange(len(cnt))):
            for c in xrange(1, cnt[i]+1):
                total += 1
                count = count*total//c
                if count >= k:
                    remain = cnt[i]-c
                    break
            if count >= k:
                break
        else:
            return ""
        result = []
        for j in xrange(i+1):
            x = chr(ord('a')+j)
            for _ in xrange(cnt[j] if j != i else remain):
                cnt[j] -= 1
                result.append(x)
        while total:
            for j in xrange(i, len(cnt)):
                if not cnt[j]:
                    continue
                new_count = count*cnt[j]//total
                if new_count < k:
                    k -= new_count
                    continue
                count = new_count
                cnt[j] -= 1
                total -= 1
                result.append(chr(ord('a')+j))
                break
        if len(s)%2:
            result.append(s[len(s)//2])
        result.extend((result[i] for i in reversed(xrange(len(result)-len(s)%2))))
        return "".join(result)
