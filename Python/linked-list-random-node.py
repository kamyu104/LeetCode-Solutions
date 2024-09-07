# Time:  ctor:      O(1)
#        getRandom: O(n)
# Space: O(1)

from random import randint


# if the length is unknown without using extra space
class Solution(object):

    def __init__(self, head):
        """
        :type head: Optional[ListNode]
        """
        self.__head = head


    # Proof of Reservoir Sampling:
    # https://discuss.leetcode.com/topic/53753/brief-explanation-for-reservoir-sampling
    def getRandom(self):
        """
        :rtype: int
        """
        reservoir = -1
        curr, n = self.__head, 0
        while curr:
            reservoir = curr.val if randint(1, n+1) == 1 else reservoir
            curr, n = curr.next, n+1
        return reservoir


# Time:  ctor:      O(n)
#        getRandom: O(1)
# Space: O(n)
from random import randint


# if the length is known with using extra space
class Solution2(object):

    def __init__(self, head):
        """
        :type head: Optional[ListNode]
        """
        self.__lookup = []
        while head:
            self.__lookup.append(head.val)
            head = head.next
        

    def getRandom(self):
        """
        :rtype: int
        """
        return self.__lookup[randint(0, len(self.__lookup)-1)]
