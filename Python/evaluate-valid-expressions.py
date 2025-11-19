# Time:  O(n)
# Space: O(n)

# stack
class Solution(object):
    def evaluateExpression(self, expression):
        """
        :type expression: str
        :rtype: int
        """
        LOOKUP = {
            "add":lambda a, b: a+b,
            "sub":lambda a, b: a-b,
            "mul":lambda a, b: a*b,
            "div":lambda a, b: a//b
        }

        SYMBOLS = "(,)"

        result = -1
        stk, curr = [], []
        for x in expression:
            if x not in SYMBOLS:
                curr.append(x)
                continue
            if x == '(':
                stk.append(["".join(curr)])
                curr = []
                continue
            if curr:
                result = int("".join(curr))
                curr = []
            stk[-1].append(result)
            if x == ')':
                op, a, b = stk.pop()
                result = LOOKUP[op](a, b)
        if curr:
            result = int("".join(curr))
            curr = []
        return result
