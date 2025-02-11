# Time:  O(n * log(m * r))
# Space: O(1)

# binary search, greedy
class Solution(object):
    def maxScore(self, points, m):
        """
        :type points: List[int]
        :type m: int
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b

        def binary_search_right(left, right, check):
            while left <= right:
                mid = left + (right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right
        
        def check(x):
            cnt = prev = 0
            for i in xrange(len(points)):
                remain = ceil_divide(x, points[i])-prev
                if remain >= 1:
                    prev = remain-1
                    cnt += 2*remain-1
                elif i != len(points)-1:
                    prev = 0
                    cnt += 1
                if cnt > m:
                    return False
            return True

        return binary_search_right(1, max(points)*m, check)
