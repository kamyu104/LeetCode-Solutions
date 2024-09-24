# Time:  O(nlogr), r = min(workerTimes) * (mountainHeight + 1) * mountainHeight / 2
# Space: O(1)

# binary search, quadratic equation
class Solution(object):
    def minNumberOfSeconds(self, mountainHeight, workerTimes):
        """
        :type mountainHeight: int
        :type workerTimes: List[int]
        :rtype: int
        """
        def binary_search(left, right, check):
            while left <= right:
                mid = left + (right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def check(target):
            # t * (1 + 2 + 3 + ... + x) <= target
            # t * (x+1)*x/2 <= target
            # x^2+x-2*target/t <= 0
            # x <= (-1+(1+8*target/t)**0.5)/2
            return sum(int((-1+(1+8*target/t)**0.5)/2) for t in workerTimes) >= mountainHeight
    
        mn = min(workerTimes)
        left, right = mn, mn*(mountainHeight+1)*mountainHeight//2
        return binary_search(left, right, check)


# Time:  O(hlogn)
# Space: O(n)
import heapq


# heap
class Solution2(object):
    def minNumberOfSeconds(self, mountainHeight, workerTimes):
        """
        :type mountainHeight: int
        :type workerTimes: List[int]
        :rtype: int
        """
        min_heap = [(0+1*t, i, 1) for i, t in enumerate(workerTimes)]
        heapq.heapify(min_heap)
        for _ in xrange(mountainHeight):
            result, i, x = heapq.heappop(min_heap)
            heapq.heappush(min_heap, (result+(x+1)*workerTimes[i], i, x+1))
        return result
