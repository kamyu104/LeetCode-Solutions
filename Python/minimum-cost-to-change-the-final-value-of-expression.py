# Time:  O(n)
# Space: O(n)

class Solution(object):
    def minOperationsToFlip(self, expression):
        """
        :type expression: str
        :rtype: int
        """
        def compute(operands, operators):
            right, left, op = operands.pop(), operands.pop(), operators.pop()
            if op == '&':
                operands.append([min(left[0], right[0]),
                                 min(left[1]+right[1], min(left[1], right[1])+1)])
            else:
                operands.append([min(left[0]+right[0], min(left[0], right[0])+1),
                                 min(left[1], right[1])])

        precedence = {'&':0, '|':0}
        operands, operators = [], []
        for c in expression:
            if c.isdigit():
                operands.append([int(c != '0'), int(c != '1')])
            elif c == '(':
                operators.append(c)
            elif c == ')':
                while operators[-1] != '(':
                    compute(operands, operators)
                operators.pop()
            elif c in precedence:
                while operators and operators[-1] in precedence and \
                      precedence[operators[-1]] >= precedence[c]:
                    compute(operands, operators)
                operators.append(c)
        while operators:
            compute(operands, operators)
        return max(operands[-1])

 
# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def minOperationsToFlip(self, expression):
        """
        :type expression: str
        :rtype: int
        """
        stk = [[None]*3]
        for c in expression:                                
            if c == '(':                                            
                stk.append([None]*3)
            elif c in {')', '0', '1'}:
                if c == ')':
                    dp0, dp1, _ = stk.pop()
                else:
                    dp0, dp1 = int(c != '0'), int(c != '1')
                if stk[-1][2] == '&':
                    stk[-1] = [min(stk[-1][0], dp0),
                               min(stk[-1][1]+dp1, min(stk[-1][1], dp1)+1),
                               None]
                elif stk[-1][2] == '|':
                    stk[-1] = [min(stk[-1][0]+dp0, min(stk[-1][0], dp0)+1),
                               min(stk[-1][1], dp1),
                               None]
                else:  # operand
                    stk[-1] = [dp0, dp1, None]
            else:
                stk[-1][2] = c
        return max(stk[0][0], stk[0][1])
