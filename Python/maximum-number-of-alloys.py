# Time:  O(k * n * logr), r = min(stock)+budget
# Space: O(1)

# binary search
class Solution(object):
    def maxNumberOfAlloys(self, n, k, budget, composition, stock, cost):
        """
        :type n: int
        :type k: int
        :type budget: int
        :type composition: List[List[int]]
        :type stock: List[int]
        :type cost: List[int]
        :rtype: int
        """
        def check(x):
            for machine in composition:
                curr = 0
                for i in xrange(n):
                    curr += max(x*machine[i]-stock[i], 0)*cost[i]
                    if curr > budget:
                        break
                if curr <= budget:
                    return True
            return False

        left, right = 1, min(stock)+budget
        while left <= right:
            mid = left+(right-left)//2
            if not check(mid):
                right = mid-1
            else:
                left = mid+1
        return right
