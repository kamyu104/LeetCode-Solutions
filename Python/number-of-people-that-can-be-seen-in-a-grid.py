# Time:  O(m * n)
# Space: O(m + n)

# mono stack, optimized from solution2
class Solution(object):
    def seePeople(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: List[List[int]]
        """
        def count(h, stk):
            cnt = 0
            while stk and stk[-1] < h:
                stk.pop()
                cnt += 1
            if stk:
                cnt += 1
            if not stk or stk[-1] != h:
                stk.append(h)
            return cnt
            
        result = [[0]*len(heights[0]) for _ in xrange(len(heights))]
        for i in xrange(len(heights)):
            stk = []
            for j in reversed(xrange(len(heights[0]))):
                result[i][j] += count(heights[i][j], stk)     
        for j in xrange(len(heights[0])):
            stk = []
            for i in reversed(xrange(len(heights))):
                result[i][j] += count(heights[i][j], stk)             
        return result


# Time:  O(m * n)
# Space: O(m + n)
# mono stack
class Solution2(object):
    def seePeople(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: List[List[int]]
        """
        def count(heights, i, stk):
            cnt = 0
            while stk and heights(stk[-1]) < heights(i):
                stk.pop()
                cnt += 1
            if stk:
                cnt += 1
            if stk and heights(stk[-1]) == heights(i):
                stk.pop()
            stk.append(i)
            return cnt
            
        result = [[0]*len(heights[0]) for _ in xrange(len(heights))]
        for i in xrange(len(heights)):
            stk = []
            for j in reversed(xrange(len(heights[0]))):
                result[i][j] += count(lambda x: heights[i][x], j, stk)     
        for j in xrange(len(heights[0])):
            stk = []
            for i in reversed(xrange(len(heights))):
                result[i][j] += count(lambda x: heights[x][j], i, stk)             
        return result


# Time:  O(m * n)
# Space: O(m + n)
# mono stack
class Solution3(object):
    def seePeople(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: List[List[int]]
        """
        def count(heights, i, stk, add):
            while stk and heights(stk[-1]) < heights(i):
                increase(stk.pop())
            if stk:
                increase(stk[-1])
            if stk and heights(stk[-1]) == heights(i):
                stk.pop()
            stk.append(i)
            
        result = [[0]*len(heights[0]) for _ in xrange(len(heights))]
        for i in xrange(len(heights)):
            stk = []
            def increase(x): result[i][x] += 1
            for j in xrange(len(heights[0])):
                count(lambda x: heights[i][x], j, stk, add)
        for j in xrange(len(heights[0])):
            stk = []
            def increase(x): result[x][j] += 1
            for i in xrange(len(heights)):
                count(lambda x: heights[x][j], i, stk, add)
        return result
