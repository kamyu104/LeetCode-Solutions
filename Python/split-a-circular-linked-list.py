# Time:  O(n)
# Space: O(1)

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        pass


# two pointers, slow and fast pointers
class Solution(object):
    def splitCircularLinkedList(self, list):
        """
        :type list: Optional[ListNode]
        :rtype: List[Optional[ListNode]]
        """
        head1 = list
        slow, fast = head1, head1.next
        while head1  != fast.next:
            slow = slow.next
            fast = fast.next.next if head1 != fast.next.next else fast.next
        head2 = slow.next
        slow.next, fast.next = head1, head2
        return [head1, head2]
