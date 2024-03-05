# Time:  O(n)
# Space: O(1)

# linked list
class Solution(object):
    def gameResult(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: str
        """
        cnt = 0
        while head:
            cnt += cmp(head.val, head.next.val)
            head = head.next.next
        return "Tie" if cnt == 0 else "Odd" if cnt < 0 else "Even"
