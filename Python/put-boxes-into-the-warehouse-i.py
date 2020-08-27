# Time:  O(nlogn + m)
# Space: O(1)

class Solution(object):
    def maxBoxesInWarehouse(self, boxes, warehouse):
        """
        :type boxes: List[int]
        :type warehouse: List[int]
        :rtype: int
        """
        boxes.sort()
        for i in xrange(1, len(warehouse)):
            warehouse[i] = min(warehouse[i], warehouse[i-1])
        result, curr = 0, 0
        for h in reversed(warehouse):
            if boxes[curr] > h:
                continue
            result += 1
            curr += 1
            if curr == len(boxes):
                break
        return result
