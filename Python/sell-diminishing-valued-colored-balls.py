# Time:  O(nlogm), m is the max of inventory, n is the size of inventory
# Space: O(1)

class Solution(object):
    def maxProfit(self, inventory, orders):
        """
        :type inventory: List[int]
        :type orders: int
        :rtype: int
        """
        MOD = 10**9+7
        def check(inventory, orders, x):
            return count(inventory, x) > orders
        
        def count(inventory, x):
            return sum(count-x+1 for count in inventory if count >= x)

        left, right = 1, max(inventory)
        while left <= right:
            mid = left + (right-left)//2
            if not check(inventory, orders, mid):
                right = mid-1
            else:
                left = mid+1
        # assert(orders-count(inventory, left) >= 0)
        return (sum((left+cnt)*(cnt-left+1)//2 for cnt in inventory if cnt >= left) +
                (left-1)*(orders-count(inventory, left)))% MOD
