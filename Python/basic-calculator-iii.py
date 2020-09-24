# Time:  O(n)
# Space: O(n)

import operator


class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        def compute(operands, operators):
            right, left = operands.pop(), operands.pop()
            operands.append(ops[operators.pop()](left, right))

        ops = {'+':operator.add, '-':operator.sub, '*':operator.mul, '/':operator.div}
        precedence = {'+':0, '-':0, '*':1, '/':1}
        operands, operators, operand = [], [], 0
        for i in xrange(len(s)):
            if s[i].isdigit():
                operand = operand*10 + int(s[i])
                if i == len(s)-1 or not s[i+1].isdigit():
                    operands.append(operand)
                    operand = 0
            elif s[i] == '(':
                operators.append(s[i])
            elif s[i] == ')':
                while operators[-1] != '(':
                    compute(operands, operators)
                operators.pop()
            elif s[i] in precedence:
                while operators and operators[-1] in precedence and \
                      precedence[operators[-1]] >= precedence[s[i]]:
                    compute(operands, operators)
                operators.append(s[i])
        while operators:
            compute(operands, operators)
        return operands[-1]


# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        operands, operators = [], []
        operand = ""
        for i in reversed(xrange(len(s))):
            if s[i].isdigit():
                operand += s[i]
                if i == 0 or not s[i-1].isdigit():
                    operands.append(int(operand[::-1]))
                    operand = ""
            elif s[i] == ')' or s[i] == '*' or s[i] == '/':
                operators.append(s[i])
            elif s[i] == '+' or s[i] == '-':
                while operators and \
                      (operators[-1] == '*' or operators[-1] == '/'):
                    self.compute(operands, operators)
                operators.append(s[i])
            elif s[i] == '(':
                while operators[-1] != ')':
                    self.compute(operands, operators)
                operators.pop()

        while operators:
            self.compute(operands, operators)

        return operands[-1]

    def compute(self, operands, operators):
        left, right = operands.pop(), operands.pop()
        op = operators.pop()
        if op == '+':
            operands.append(left + right)
        elif op == '-':
            operands.append(left - right)
        elif op == '*':
            operands.append(left * right)
        elif op == '/':
            operands.append(left / right)

