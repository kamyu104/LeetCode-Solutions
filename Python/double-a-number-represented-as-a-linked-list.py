# Time:  O(n)
# Space: O(1)

# linked list
class Solution(object):
    def doubleIt(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if head.val >= 5:
            head = ListNode(0, head)
        curr = head
        while curr:
            curr.val = (curr.val*2)%10
            if curr.next and curr.next.val >= 5:
                curr.val += 1
            curr = curr.next
        return head
