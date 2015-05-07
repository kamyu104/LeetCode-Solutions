# Time:  O(nlogk)
# Space: O(k)
#
# Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
import heapq

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    
    def __repr__(self):
        if self:
            return "{} -> {}".format(self.val, repr(self.next))

class Solution:
    # @param a list of ListNode
    # @return a ListNode
    def mergeKLists(self, lists):
        dummy = ListNode(0)
        current = dummy
        
        heap = []
        for sorted_list in lists:
            if sorted_list:
                heapq.heappush(heap, (sorted_list.val, sorted_list))
                
        while heap:
            smallest = heapq.heappop(heap)[1]
            current.next = smallest
            current = current.next
            if smallest.next:
                heapq.heappush(heap, (smallest.next.val, smallest.next))
                
        return dummy.next

if __name__ == "__main__":
    list1 = ListNode(1)
    list1.next = ListNode(3)
    list2 = ListNode(2)
    list2.next = ListNode(4)
    
    print Solution().mergeKLists([list1, list2])
