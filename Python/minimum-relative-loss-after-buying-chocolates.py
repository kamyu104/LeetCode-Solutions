# Time:  O((n + q) * logn)
# Space: O(n)

# sort, binary search, greedy, prefix sum
class Solution(object):
    def minimumRelativeLosses(self, prices, queries):
        """
        :type prices: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def binary_search(left, right, check):
            while left <= right:
                mid = left + (right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        prices.sort()
        prefix = [0]*(len(prices)+1)
        for i in xrange(len(prices)):
            prefix[i+1] = prefix[i]+prices[i]
        result = []
        for k, m in queries:
            cnt = binary_search(0, m-1, lambda x: k-(prices[-(m-x)]-k) <= prices[(x+1)-1]-0)
            a = prefix[-1]-prefix[-1-(m-cnt)]-(m-cnt)*k
            b = prefix[cnt]+(m-cnt)*k
            result.append(b-a)
        return result
