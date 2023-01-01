# Time:  O(n)
# Space: O(1)

class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        result, left, right, level = 0, 0, len(height)-1, 0
        while left < right:
            if height[left] < height[right]:
                lower = height[left]
                left += 1
            else:
                lower = height[right]
                right -= 1
            level = max(level, lower)
            result += level-lower
        return result


# Time:  O(n)
# Space: O(1)
class Solution2(object):
    # @param A, a list of integers
    # @return an integer
    def trap(self, A):
        result = 0
        top = 0
        for i in xrange(len(A)):
            if A[top] < A[i]:
                top = i

        second_top = 0
        for i in xrange(top):
            if A[second_top] < A[i]:
                second_top = i
            result += A[second_top] - A[i]

        second_top = len(A) - 1
        for i in reversed(xrange(top, len(A))):
            if A[second_top] < A[i]:
                second_top = i
            result += A[second_top] - A[i]

        return result


# Time:  O(n)
# Space: O(n)
class Solution3(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        right = [0]*len(height)
        mx = 0
        for i in reversed(xrange(len(height))):
            right[i] = mx
            mx = max(mx, height[i])
        result = left = 0
        for i in xrange(len(height)):
            left = max(left, height[i])
            result += max(min(left, right[i])-height[i], 0)
        return result


# Time:  O(n)
# Space: O(n)
class Solution4(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        result = 0
        stk = []
        for i in xrange(len(height)):
            prev = 0
            while stk and height[stk[-1]] <= height[i]:
                j = stk.pop()
                result += (height[j] - prev) * (i - j - 1)
                prev = height[j]
            if stk:
                result += (height[i] - prev) * (i - stk[-1] - 1)
            stk.append(i)
        return result
