# Time:  O(n)
# Space: O(n)

# stack
class Solution(object):
    def isPreorder(self, nodes):
        """
        :type nodes: List[List[int]]
        :rtype: bool
        """
        stk = [nodes[0][0]]
        for i in xrange(1, len(nodes)):
            while stk and stk[-1] != nodes[i][1]:
                stk.pop()                
            if not stk:
                return False            
            stk.append(nodes[i][0])            
        return True
