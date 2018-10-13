# Time:  O(m + n)
# Space: O(1)

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    # @param two ListNodes
    # @return the intersected ListNode
    def getIntersectionNode(self, headA, headB):
        curA, curB = headA, headB
        begin, tailA, tailB = None, None, None

        # a->c->b->c
        # b->c->a->c
        while curA and curB:
            if curA == curB:
                begin = curA
                break

            if curA.next:
                curA = curA.next
            elif tailA is None:
                tailA = curA
                curA = headB
            else:
                break

            if curB.next:
                curB = curB.next
            elif tailB is None:
                tailB = curB
                curB = headA
            else:
                break

        return begin

