# Time:  O(n)
# Space: O(1)

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    # @param {ListNode} head
    # @param {integer} val
    # @return {ListNode}
    def removeElements(self, head, val):
        dummy = ListNode(float("-inf"))
        dummy.next = head
        prev, curr = dummy, dummy.next

        while curr:
            if curr.val == val:
                prev.next = curr.next
            else:
                prev = curr

            curr = curr.next

        return dummy.next



