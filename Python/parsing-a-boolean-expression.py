# Time:  O(n)
# Space: O(n)

class Solution(object):
    def parseBoolExpr(self, expression):
        """
        :type expression: str
        :rtype: bool
        """
        def parse(expression, i):
            if expression[i[0]] not in "&|!":
                result = expression[i[0]] == 't'
                i[0] += 1
                return result
            op = expression[i[0]]
            i[0] += 2
            stk = []
            while expression[i[0]] != ')':
                if expression[i[0]] == ',': 
                    i[0] += 1
                    continue
                stk.append(parse(expression, i))
            i[0] += 1
            if op == '&':
                return all(stk)
            if op == '|':
                return any(stk)
            return not stk[0]

        return parse(expression, [0])
