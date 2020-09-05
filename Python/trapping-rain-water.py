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
    # @param A, a list of integers
    # @return an integer
    def trap(self, A):
        result = 0
        stack = []

        for i in xrange(len(A)):
            mid_height = 0
            while stack:
                [pos, height] = stack.pop()
                result += (min(height, A[i]) - mid_height) * (i - pos - 1)
                mid_height = height

                if A[i] < height:
                    stack.append([pos, height])
                    break
            stack.append([i, A[i]])

        return result

