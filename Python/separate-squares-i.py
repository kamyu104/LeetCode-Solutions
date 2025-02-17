# Time:  O(nlogn)
# Space: O(n)

# sort, line sweep
class Solution(object):
    def separateSquares(self, squares):
        """
        :type squares: List[List[int]]
        :rtype: float
        """
        events = []
        for x, y, l in squares:
            events.append((y, 1, l))
            events.append((y+l, -1, l))
        events.sort(key=lambda e: e[0])
        total = curr = 0.0
        prev = events[0][0]
        for y, v, l in events:
            if y != prev:
                total += (y-prev)*curr
                prev = y
            curr += l*v
        expect = total/2.0
        total = curr = 0.0
        prev = events[0][0]
        for y, v, l in events:
            if y != prev:
                if total+(y-prev)*curr >= expect:
                    break
                total += (y-prev)*curr
                prev = y
            curr += l*v
        return prev+(expect-total)/curr


# Time:  O(nlogr)
# Space: O(1)
# binary search
class Solution2(object):
    def separateSquares(self, squares):
        """
        :type squares: List[List[int]]
        :rtype: float
        """
        EPS = 1e-5
        def binary_search(left, right, check):
            while right-left > EPS:
                mid = left+(right-left)/2.0
                if check(mid):
                    right = mid
                else:
                    left = mid
            return left
    
        def check(k):
            result = 0
            for x, y, l in squares:
                if y >= k:
                    result += l**2
                elif y+l <= k:
                    result -= l**2
                else:
                    result += l*(((y+l)-k)-(k-y))
            return result <= 0
    
        return binary_search(min(y for _, y, _ in squares), max(y+l for _, y, l in squares), check)
