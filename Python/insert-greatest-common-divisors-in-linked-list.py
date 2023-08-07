# Time:  O(n)
# Space: O(1)

# linked list
class Solution(object):
    def insertGreatestCommonDivisors(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        curr = head
        while curr.next:
            curr.next = ListNode(gcd(curr.val, curr.next.val), curr.next)
            curr = curr.next.next
        return head
