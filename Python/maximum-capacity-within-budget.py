# Time:  O(n + b)
# Space: O(b)

# hash table, prefix sum
class Solution(object):
    def maxCapacity(self, costs, capacity, budget):
        """
        :type costs: List[int]
        :type capacity: List[int]
        :type budget: int
        :rtype: int
        """
        mid = (budget-1)//2
        lookup = [0]*budget
        for i in xrange(len(costs)):
            if costs[i] >= budget:
                continue
            lookup[costs[i]] = max(lookup[costs[i]], capacity[i])
        for i in xrange(mid):
            lookup[i+1] = max(lookup[i+1], lookup[i])
        result = mx = 0
        for i in xrange(len(costs)):
            if costs[i] > mid:
                continue
            result = max(result, mx+capacity[i])
            mx = max(mx, capacity[i])
        for i in xrange(mid+1, budget):
            result = max(result, lookup[i]+lookup[(budget-1)-i])
        return result


# Time:  O(nlogn)
# Space: O(n)
# sort, mono stack
class Solution2(object):
    def maxCapacity(self, costs, capacity, budget):
        """
        :type costs: List[int]
        :type capacity: List[int]
        :type budget: int
        :rtype: int
        """
        result = 0
        stk = []
        for i in sorted(xrange(len(costs)), key=lambda i: costs[i]):
            cost, cap = costs[i], capacity[i]
            if cost >= budget:
                break
            while stk and stk[-1][0]+cost >= budget:
                stk.pop()
            result = max(result, (stk[-1][1] if stk else 0)+cap)
            if not stk or stk[-1][1] < cap:
                stk.append((cost, cap))
        return result


# Time:  O(nlogn)
# Space: O(n)
import bisect


# sort, prefix sum, binary search
class Solution3(object):
    def maxCapacity(self, costs, capacity, budget):
        """
        :type costs: List[int]
        :type capacity: List[int]
        :type budget: int
        :rtype: int
        """
        def binary_search_right(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right

        idxs = sorted(xrange(len(costs)), key=lambda i: costs[i])
        prefix = [0]*(len(idxs)+1)
        for i, idx in enumerate(idxs):
            prefix[i+1] = max(prefix[i], capacity[idx])
        result = 0
        sorted_costs = [costs[i] for i in idxs]
        for i, idx in enumerate(idxs):
            cost, cap = costs[idx], capacity[idx]
            if cost >= budget:
                break
            j = bisect.bisect_left(sorted_costs, budget-cost, hi=i)-1
            result = max(result, prefix[j+1]+cap)
        return result


# Time:  O(nlogn)
# Space: O(n)
# sort, prefix sum, binary search
class Solution4(object):
    def maxCapacity(self, costs, capacity, budget):
        """
        :type costs: List[int]
        :type capacity: List[int]
        :type budget: int
        :rtype: int
        """
        def binary_search_right(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right

        idxs = sorted(xrange(len(costs)), key=lambda i: costs[i])
        prefix = [0]*(len(idxs)+1)
        for i, idx in enumerate(idxs):
            prefix[i+1] = max(prefix[i], capacity[idx])
        result = 0
        for i, idx in enumerate(idxs):
            cost, cap = costs[idx], capacity[idx]
            if cost >= budget:
                break
            j = binary_search_right(0, i-1, lambda x: costs[idxs[x]]+cost < budget)
            result = max(result, prefix[j+1]+cap)
        return result
