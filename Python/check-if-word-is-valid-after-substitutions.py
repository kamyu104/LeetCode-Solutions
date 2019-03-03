# Time:  O(n)
# Space: O(n)

class Solution(object):
    def isValid(self, S):
        """
        :type S: str
        :rtype: bool
        """
        stack = []
        for i in S:
            if i == 'c':
                if stack[-2:] == ['a', 'b']:
                    stack.pop()
                    stack.pop()
                else:
                    return False
            else:
                stack.append(i)
        return not stack
