# Time:  O(n)
# Space: O(1)

# linked list
class Solution:
    def toArray(self, head):
        """
        :type head: Node
        :rtype: List[int]
        """
        result = []
        while head:
            result.append(head.val)
            head = head.next
        return result
