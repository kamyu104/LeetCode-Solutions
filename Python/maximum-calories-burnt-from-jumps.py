# Time:  O(nlogn)
# Space: O(1)

# sort, greedy
class Solution(object):
    def maxCaloriesBurnt(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        heights.sort()
        left, right = 0, len(heights)-1
        result = (0-heights[right])**2
        while left != right:
            result += (heights[right]-heights[left])**2
            right -= 1
            if left == right:
                break
            result += (heights[left]-heights[right])**2
            left += 1
        return result


# Time:  O(nlogn)
# Space: O(1)
# sort, greedy
class Solution2(object):
    def maxCaloriesBurnt(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        heights.sort()
        d = 0
        left, right = 0, len(heights)-1
        result = (0-heights[right])**2
        while left != right:
            result += (heights[right]-heights[left])**2
            left += d
            d ^= 1
            right -= d
        return result
