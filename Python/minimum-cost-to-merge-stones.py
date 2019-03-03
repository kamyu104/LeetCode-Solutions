# Time:  O(n^3)
# Space: O(n^3)

# memoization (top-down dp)
class Solution(object):
    def mergeStones(self, stones, K):
        """
        :type stones: List[int]
        :type K: int
        :rtype: int
        """
        def dp(prefix, K, i, j, k, lookup):
            if (i, j, k) in lookup:
                return lookup[i, j, k]
            if i == j:
                result = 0 if k == 1 else float("inf")
            else:
                if k == 1:
                    result = dp(prefix, K, i, j, K, lookup) + \
                             prefix[j+1] - prefix[i]
                else:
                    result = float("inf")
                    for mid in xrange(i, j, K-1):
                        result = min(result, dp(prefix, K, i, mid, 1, lookup) + 
                                             dp(prefix, K, mid+1, j, k-1, lookup))
            lookup[i, j, k] = result
            return result
        
        if (len(stones)-1) % (K-1):
            return -1
        lookup = {}
        prefix = [0]
        for x in stones:
            prefix.append(prefix[-1]+x)
        result = dp(prefix, K, 0, len(stones)-1, 1, lookup)
        return result if result != float("inf") else 0
