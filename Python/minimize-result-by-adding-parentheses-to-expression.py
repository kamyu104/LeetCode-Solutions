# Time:  O(n^2)
# Space: O(1)

# brute force
class Solution(object):
    def minimizeResult(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        def stoi(s, i, j):
            if i == j:
                return 1
            result = 0
            for k in xrange(i, j):
                result = result*10+(ord(s[k])-ord('0'))
            return result

        result = None
        min_val = float("inf")
        pos = expression.index('+')
        for i in xrange(pos):
            for j in xrange(pos+1, len(expression)):
                val = (stoi(expression, 0, i)*
                       (stoi(expression, i, pos)+stoi(expression, pos+1, j+1))*
                       stoi(expression, j+1, len(expression)))
                if val < min_val:
                    min_val = val
                    result = (i, j)
        return "".join([expression[:result[0]], '(', expression[result[0]:result[1]+1], ')', expression[result[1]+1:]])

    
# Time:  O(n^2)
# Space: O(n)
# brute force
class Solution2(object):
    def minimizeResult(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        result = None
        min_val = float("inf")
        pos = expression.index('+')
        for i in xrange(pos):
            for j in xrange(pos+1, len(expression)):
                val = (int(expression[:i] or "1")*
                       (int(expression[i:pos])+int(expression[pos+1:j+1]))*
                       int(expression[j+1:] or "1"))
                if val < min_val:
                    min_val = val
                    result = (i, j)
        return "".join([expression[:result[0]], '(', expression[result[0]:result[1]+1], ')', expression[result[1]+1:]])
