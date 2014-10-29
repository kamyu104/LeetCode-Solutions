# Time:  O(n)
# Space: O(1)
#
# Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
# 
# Follow up:
# Can you solve it without using extra space?
#

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    
    def __str__(self):
        if self:
            return "{}".format(self.val)
        else:
            return None
        
class Solution:
    # @param head, a ListNode
    # @return a list node
    def detectCycle(self, head):
        fast, slow = head, head
        while fast and fast.next:
            fast, slow = fast.next.next, slow.next
            if fast is slow:
                fast = head
                while fast is not slow:
                    fast, slow = fast.next, slow.next
                return fast
        return None

if __name__ == "__main__":
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = head.next
    print Solution().detectCycle(head)