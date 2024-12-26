# Time:  O(nlogn)
# Space: O(1)

# sort, merge intervals
class Solution(object):
    def checkValidCuts(self, n, rectangles):
        """
        :type n: int
        :type rectangles: List[List[int]]
        :rtype: bool
        """
        def check(idx):
            cnt = 0
            curr = rectangles[0][idx+2]
            for x in rectangles:
                cnt += int(curr <= x[idx])
                curr = max(curr, x[idx+2])
            return cnt >= 2
    
        for idx in xrange(2):
            rectangles.sort(key=lambda x: x[idx])
            if check(idx):
                return True
        return False
