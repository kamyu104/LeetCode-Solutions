# Time:  O(n)
# Space: O(1)

class Solution(object):
    def minimumRefill(self, plants, capacityA, capacityB):
        """
        :type plants: List[int]
        :type capacityA: int
        :type capacityB: int
        :rtype: int
        """
        result = 0 
        left, right = 0, len(plants)-1
        canA, canB = capacityA, capacityB
        while left < right: 
            if canA < plants[left]:
                result += 1
                canA = capacityA
            canA -= plants[left]
            if canB < plants[right]:
                result += 1
                canB = capacityB
            canB -= plants[right]
            left, right = left+1, right-1
        if left == right:
            if max(canA, canB) < plants[left]:
                result += 1
        return result
