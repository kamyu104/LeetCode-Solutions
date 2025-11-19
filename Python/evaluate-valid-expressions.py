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

        stk, curr = [[]], []
        for x in expression:
            if x not in SYMBOLS:
                curr.append(x)
                continue
            if x == '(':
                stk.append(["".join(curr)])
                curr = []
                continue
            if curr:
                stk[-1].append(int("".join(curr)))
                curr = []
            if x == ')':
                op, a, b = stk.pop()
                stk[-1].append(LOOKUP[op](a, b))
        return stk[0][0] if stk[0] else int("".join(curr))
