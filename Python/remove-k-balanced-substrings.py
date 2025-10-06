# Time:  O(n)
# Space: O(n)

# stack
class Solution(object):
    def removeSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        def count(x):
            if x == '(':
                if cnt[0] < k:
                    cnt[0] += 1
                elif cnt[0] > k:
                    cnt[0] = 1
            else:
                if cnt[0] >= k:
                    cnt[0] += 1
                else:
                    cnt[0] = 0
                    
        result = []
        cnt = [0]
        for x in s:
            result.append(x)
            count(x)
            if cnt[0] != 2*k:
                continue
            for _ in xrange(2*k):
                result.pop()
            cnt[0] = 0
            for i in xrange(max(len(result)-(2*k-1), 0), len(result)):
                count(result[i])  
        return "".join(result)
