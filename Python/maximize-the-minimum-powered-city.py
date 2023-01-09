# Time:  O(nlogk)
# Space: O(n)

# binary search, sliding window, greedy
class Solution(object):
    def maxPower(self, stations, r, k):
        """
        :type stations: List[int]
        :type r: int
        :type k: int
        :rtype: int
        """
        def min_power():
            mn = float("inf")
            curr = sum(stations[i] for i in xrange(r))
            for i in xrange(len(stations)):
                if i+r < len(stations):
                    curr += stations[i+r]
                if i >= r+1:
                    curr -= stations[i-(r+1)]
                mn = min(mn, curr)
            return mn
    
        def check(target):
            arr = stations[:]
            curr = sum(arr[i] for i in xrange(r))
            cnt = k
            for i in xrange(len(arr)):
                if i+r < len(arr):
                    curr += arr[i+r]
                if i >= r+1:
                    curr -= arr[i-(r+1)]
                if curr >= target:
                    continue
                diff = target-curr
                if diff > cnt:
                    return False
                cnt -= diff
                curr += diff
                if i+r < len(arr):
                    arr[i+r] += diff
            return True

        mn = min_power() 
        left, right = mn, mn+k
        while left <= right:
            mid = left + (right-left)//2
            if not check(mid):
                right = mid-1
            else:
                left = mid+1
        return right
    
