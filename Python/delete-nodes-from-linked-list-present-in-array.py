# Time:  O(n)
# Space: O(m)

# hash table, linked list
class Solution(object):
    def modifiedList(self, nums, head):
        """
        :type nums: List[int]
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        lookup = set(nums)
        curr = dummy = ListNode(0, head)
        while curr.next:
            if curr.next.val not in lookup:
                curr = curr.next
            else:
                curr.next = curr.next.next
        return dummy.next
