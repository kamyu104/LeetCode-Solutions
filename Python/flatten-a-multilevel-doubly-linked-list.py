# Time:  O(n)
# Space: O(1)

class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


class Solution(object):
    def flatten(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        curr = head
        while curr:
            if curr.child:
                curr_next = curr.next
                curr.child.prev = curr
                curr.next = curr.child
                last_child = curr
                while last_child.next:
                    last_child = last_child.next
                if curr_next:
                    last_child.next = curr_next
                    curr_next.prev = last_child
                curr.child = None
            curr = curr.next
        return head

