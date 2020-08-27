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
        min_h = float("inf")
        for i in xrange(len(warehouse)):
            min_h = min(min_h, warehouse[i])
            warehouse[i] = min_h
        result, curr = 0, 0
        for h in reversed(warehouse):
            if boxes[curr] > h:
                continue
            curr += 1
            result += 1
            if curr == len(boxes):
                break
        return result
