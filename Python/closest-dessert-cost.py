# Time:  O(m * max(max_base, target + max_topping / 2)) ~= O(m * t)
# Space: O(max(max_base, target + max_topping / 2)) ~= O(t)

class Solution(object):
    def closestCost(self, baseCosts, toppingCosts, target):
        """
        :type baseCosts: List[int]
        :type toppingCosts: List[int]
        :type target: int
        :rtype: int
        """
        max_count = 2
        max_base, max_topping = max(baseCosts), max(toppingCosts)
        dp = [False]*(max(max_base, target+max_topping//2)+1)
        for b in baseCosts:
            dp[b] = True
        for t in toppingCosts:
            for _ in xrange(max_count):
                for i in reversed(xrange(len(dp)-t)):
                    if dp[i]:
                        dp[i+t] = True
        result = float("inf")
        for i in xrange(1, len(dp)):
            if not dp[i]:
                continue
            if abs(i-target) < abs(result-target):
                result = i
            if i >= target:
                break
        return result
            

# Time:  O(n * 3^m)
# Space: O(m * t)
class Solution2(object):
    def closestCost(self, baseCosts, toppingCosts, target):
        """
        :type baseCosts: List[int]
        :type toppingCosts: List[int]
        :type target: int
        :rtype: int
        """
        max_count = 2
        def backtracking(toppingCosts, i, cost, target, lookup, result):
            if (i, cost) in lookup:
                return
            lookup.add((i, cost))
            if cost >= target or i == len(toppingCosts):
                if (abs(cost-target), cost) < (abs(result[0]-target), result[0]):
                    result[0] = cost
                return
            for j in xrange(max_count+1):
                backtracking(toppingCosts, i+1, cost+j*toppingCosts[i], target, lookup, result)

        result = [float("inf")]
        lookup = set()
        for b in baseCosts:
            backtracking(toppingCosts, 0, b, target, lookup, result)
        return result[0]


# Time:  O(3^m*log(3^m)) + O(n*log(3^m)) = O(m*(3^m + n))
# Space: O(3^m)
import bisect


class Solution3(object):
    def closestCost(self, baseCosts, toppingCosts, target):
        """
        :type baseCosts: List[int]
        :type toppingCosts: List[int]
        :type target: int
        :rtype: int
        """
        max_count = 2
        combs = set([0])
        for t in toppingCosts:
            combs = set([c+i*t for c in combs for i in xrange(max_count+1)])
        result, combs = float("inf"), sorted(combs)
        for b in baseCosts:
            idx = bisect.bisect_left(combs, target-b)
            if idx < len(combs):
                result = min(result, b+combs[idx], key=lambda x: (abs(x-target), x))
            if idx > 0:
                result = min(result, b+combs[idx-1], key=lambda x: (abs(x-target), x))        
        return result


# Time:  O(n * 3^m)
# Space: O(3^m)
class Solution4(object):
    def closestCost(self, baseCosts, toppingCosts, target):
        """
        :type baseCosts: List[int]
        :type toppingCosts: List[int]
        :type target: int
        :rtype: int
        """
        max_count = 2
        combs = set([0])
        for t in toppingCosts:
            combs = set([c+i*t for c in combs for i in xrange(max_count+1)])
        result = float("inf")
        for b in baseCosts:
            for c in combs:
                result = min(result, b+c, key=lambda x: (abs(x-target), x))      
        return result
