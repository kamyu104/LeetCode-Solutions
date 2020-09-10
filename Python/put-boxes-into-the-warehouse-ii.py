# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def maxBoxesInWarehouse(self, boxes, warehouse):
        """
        :type boxes: List[int]
        :type warehouse: List[int]
        :rtype: int
        """
        boxes.sort(reverse=True)
        left, right = 0, len(warehouse)-1
        for h in boxes:
            if h <= warehouse[left]:
                left += 1
            elif h <= warehouse[right]:
                right -= 1
            if left > right:
                break
        return left + (len(warehouse)-1-right)
