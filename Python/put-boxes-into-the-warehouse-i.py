# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def maxBoxesInWarehouse(self, boxes, warehouse):
        """
        :type boxes: List[int]
        :type warehouse: List[int]
        :rtype: int
        """
        boxes.sort()
        min_h = warehouse[0]
        for i in xrange(len(warehouse)):
            warehouse[i] = min_h = min(min_h, warehouse[i])
        result, curr = 0, 0
        for h in reversed(warehouse):
            if boxes[curr] > h:
                continue
            result += 1
            curr += 1
            if curr == len(boxes):
                break
        return result
