# Time:  O(1)
# Space: O(1)

class Solution(object):
    # @param {ListNode} node
    # @return {void} Do not return anything, modify node in-place instead.
    def deleteNode(self, node):
        if node and node.next:
            node_to_delete = node.next
            node.val = node_to_delete.val
            node.next = node_to_delete.next
            del node_to_delete

