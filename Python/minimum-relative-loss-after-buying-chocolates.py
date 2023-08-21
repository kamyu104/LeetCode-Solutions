# Time:  O((n + q) *logn)
# Space: O(n)

# sort, binary search, greedy, prefix sum
class Solution(object):
    def minimumRelativeLosses(self, prices, queries):
        """
        :type prices: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def binary_search(k, m):
            def check(x):
                return k-(prices[-x]-k) <= prices[((m-x)+1)-1]-0

            left, right = 1, m
            while left <= right:
                mid = left + (right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right

        prices.sort()
        prefix = [0]*(len(prices)+1)
        for i in xrange(len(prices)):
            prefix[i+1] = prefix[i]+prices[i]
        result = []
        for k, m in queries:
            cnt = binary_search(k, m)
            a = prefix[-1]-prefix[-1-cnt]-cnt*k
            b = prefix[m-cnt]+cnt*k
            result.append(b-a)
        return result
