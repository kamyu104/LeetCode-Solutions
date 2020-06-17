# Time:  O(nlogd), d is the max day of bloomDay
# Space: O(1)

class Solution(object):
    def minDays(self, bloomDay, m, k):
        """
        :type bloomDay: List[int]
        :type m: int
        :type k: int
        :rtype: int
        """
        def check(bloomDay, m, k, x):
            result = count = 0
            for d in bloomDay:
                count = count+1 if d <= x else 0
                if count == k:
                    count = 0
                    result += 1
                    if result == m:
                        break
            return result >= m

        if m*k > len(bloomDay):
            return -1
        left, right = 1, max(bloomDay)
        while left <= right:
            mid = left + (right-left)//2
            if check(bloomDay, m, k, mid):
                right = mid-1
            else:
                left = mid+1
        return left
