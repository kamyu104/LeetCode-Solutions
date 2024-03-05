# Time:  O(n)
# Space: O(1)

# linked list
class Solution(object):
    def frequenciesOfElements(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        curr = dummy = ListNode(0)
        cnt = 0
        while head:
            cnt += 1
            if not head.next or head.next.val != head.val:
                curr.next = ListNode(cnt)
                curr = curr.next
                cnt = 0
            head = head.next
        return dummy.next
