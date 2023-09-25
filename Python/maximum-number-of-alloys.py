# Time:  O(k * nlogn)
# Space: O(n)

# math
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
        def count(machine, budget):
            def cnt(x):
                return stock[x]//machine[x]
    
            idxs = range(n)
            idxs.sort(key=cnt)
            result = cnt(idxs[0])
            curr = delta = remain = 0
            for i in xrange(n):
                delta += cost[idxs[i]]*machine[idxs[i]]
                remain += cost[idxs[i]]*(stock[idxs[i]]%machine[idxs[i]])
                if i+1 != n and cnt(idxs[i+1])-cnt(idxs[i]) == 0:
                    continue
                if curr+delta > budget+remain:
                    break
                curr += delta
                budget += remain
                if i+1 == n or budget-curr*(cnt(idxs[i+1])-cnt(idxs[i])) <= 0:
                    result += budget//curr
                    break
                budget -= curr*(cnt(idxs[i+1])-cnt(idxs[i]))
                result += cnt(idxs[i+1])-cnt(idxs[i])
                remain = delta = 0
            return result

        return max(count(machine, budget) for machine in composition)


# Time:  O(k * n * logr), remain = min(stock)+budget
# Space: O(1)
# binary search
class Solution2(object):
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
