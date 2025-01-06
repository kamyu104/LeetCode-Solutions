# Time:  O(nlogn)
# Space: O(1)

# sort, two pointers, sliding window
class Solution(object):
    def maximumCoins(self, coins, k):
        """
        :type coins: List[List[int]]
        :type k: int
        :rtype: int
        """
        def max_amount():
            coins.sort()
            result = curr = left = 0
            for right in xrange(len(coins)):
                curr += (coins[right][1]-coins[right][0]+1)*coins[right][2]
                while coins[right][1]-coins[left][1]+1 > k:
                    curr -= (coins[left][1]-coins[left][0]+1)*coins[left][2]
                    left += 1
                result = max(result, curr-max((coins[right][1]-coins[left][0]+1)-k, 0)*coins[left][2])
            return result
    
        result = max_amount()
        for i, (l, r, w) in enumerate(coins):
            coins[i][:] = [-r, -l, w]
        result = max(result, max_amount())
        return result
