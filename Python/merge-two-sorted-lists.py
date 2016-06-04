# Time:  O(n)
# Space: O(1)
#
# Merge two sorted linked lists and return it as a new list. 
# The new list should be made by splicing together the nodes of the first two lists.
#

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def __repr__(self):
        if self:
            return "{} -> {}".format(self.val, self.next)


class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        curr = dummy = ListNode(0)
        while l1 and l2:
            if l1.val < l2.val:
                curr.next = l1
                l1 = l1.next
            else:
                curr.next = l2
                l2 = l2.next
            curr = curr.next
        curr.next = l1 or l2
        return dummy.next


if __name__ == "__main__":
    l1 = ListNode(0)
    l1.next = ListNode(1)
    l2 = ListNode (2)
    l2.next = ListNode(3)
    print Solution().mergeTwoLists(l1, l2)
    
        
