# Time:  O(n)
# Space: O(w), w is the max node count of the level in the tree

class Solution(object):
    def pathSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        class Node(object):
            def __init__(self, num):
                self.level = num/100 - 1
                self.i = (num%100)/10 - 1
                self.val = num%10
                self.leaf = True
                
            def isParent(self, other):
                return self.level == other.level-1 and \
                       self.i == other.i/2

        if not nums:
            return 0
        result = 0
        q = collections.deque()
        dummy = Node(10)
        parent = dummy
        for num in nums:
            child = Node(num)
            while not parent.isParent(child):
                result += parent.val if parent.leaf else 0
                parent = q[0]
                q.popleft()
            parent.leaf = False
            child.val += parent.val
            q.append(child)
        while q:
            result += q.pop().val
        return result
