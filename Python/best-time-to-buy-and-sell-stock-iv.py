# Time:  O(n) on average, using Median of Medians could achieve O(n) (Intro Select)
# Space: O(n)

import random


class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        def nth_element(nums, n, compare=lambda a, b: a < b):
            def tri_partition(nums, left, right, target, compare):
                mid = left
                while mid <= right:
                    if nums[mid] == target:
                        mid += 1
                    elif compare(nums[mid], target):
                        nums[left], nums[mid] = nums[mid], nums[left]
                        left += 1
                        mid += 1
                    else:
                        nums[mid], nums[right] = nums[right], nums[mid]
                        right -= 1
                return left, right

            left, right = 0, len(nums)-1
            while left <= right:
                pivot_idx = random.randint(left, right)
                pivot_left, pivot_right = tri_partition(nums, left, right, nums[pivot_idx], compare)
                if pivot_left <= n <= pivot_right:
                    return
                elif pivot_left > n:
                    right = pivot_left-1
                else:  # pivot_right < n.
                    left = pivot_right+1

        profits = []
        v_p_stk = []  # mono stack, where v is increasing and p is strictly decreasing
        v, p = -1, -1
        while p+1 < len(prices): # at most O(n) peaks, so v_p_stk and profits are both at most O(n) space
            for v in xrange(p+1, len(prices)-1):
                if prices[v] < prices[v+1]:
                    break
            else:
                v = len(prices)-1
            for p in xrange(v, len(prices)-1):
                if prices[p] > prices[p+1]:
                    break 
            else:
                p = len(prices)-1
            while v_p_stk and prices[v_p_stk[-1][0]] > prices[v]:  # not overlapped
                last_v, last_p = v_p_stk.pop()
                profits.append(prices[last_p]-prices[last_v])  # count [prices[last_v], prices[last_p]] interval
            while v_p_stk and prices[v_p_stk[-1][1]] <= prices[p]:  # overlapped
                # prices[last_v] <= prices[v] <= prices[last_p] <= prices[p],
                # treat overlapped as [prices[v], prices[last_p]], [prices[last_v], prices[p]] intervals due to invariant max profit
                last_v, last_p = v_p_stk.pop()
                profits.append(prices[last_p]-prices[v])  # count [prices[v], prices[last_p]] interval
                v = last_v
            v_p_stk.append((v, p))  # keep [prices[last_v], prices[p]] interval to check overlapped      
        while v_p_stk:
            last_v, last_p = v_p_stk.pop()
            profits.append(prices[last_p]-prices[last_v])  # count [prices[last_v], prices[last_p]] interval
        if k > len(profits):
            k = len(profits)
        else:
            nth_element(profits, k-1, compare=lambda a, b: a > b)
        return sum(profits[i] for i in xrange(k))  # top k profits of nonoverlapped intervals


# Time:  O(k * n)
# Space: O(k)
class Solution2(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        def maxAtMostNPairsProfit(sprices):
            profit = 0
            for i in xrange(len(prices) - 1):
                profit += max(0, prices[i + 1] - prices[i])
            return profit

        def maxAtMostKPairsProfit(prices, k):
            max_buy = [float("-inf") for _ in xrange(k + 1)]
            max_sell = [0 for _ in xrange(k + 1)]
            for i in xrange(len(prices)):
                for j in xrange(1, k + 1):
                    max_buy[j] = max(max_buy[j], max_sell[j-1] - prices[i])
                    max_sell[j] = max(max_sell[j], max_buy[j] + prices[i])
            return max_sell[k]

        if k >= len(prices) // 2:
            return maxAtMostNPairsProfit(prices)

        return maxAtMostKPairsProfit(prices, k)
