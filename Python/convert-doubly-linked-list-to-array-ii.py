# Time:  O(n)
# Space: O(1)

# linked list
class Solution:
    def toArray(self, node):
        """
        :type head: Node
        :rtype: List[int]
        """
        while node.prev:
            node = node.prev
        result = []
        while node:
            result.append(node.val)
            node = node.next
        return result
