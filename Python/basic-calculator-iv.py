# Time:  +:        O(d * t), t is the number of terms,
#                            d is the average degree of terms
#        -:        O(d * t)
#        *:        O(d * t^2)
#        eval:     O(d * t)
#        to_list:  O(d * tlogt)
# Space: O(e + d * t), e is the number of evalvars

import collections
import itertools
import operator


def clear(result):
    to_remove = [k for k, v in result.iteritems() if v == 0]
    for k in to_remove:
        result.pop(k)


class Poly(collections.Counter):
    def __init__(self, expr=None):
        if expr is None:
            return
        if expr.isdigit():
            if int(expr):
                self.update({(): int(expr)})
        else:
            self[(expr,)] += 1

    def __add__(self, other):
        result = Poly()
        result.update(self)
        result.update(other)
        clear(result)
        return result

    def __sub__(self, other):
        result = Poly()
        result.update(self)
        result.update({k: -v for k, v in other.iteritems()})
        clear(result)
        return result

    def __mul__(self, other):
        def merge(k1, k2):
            result = []
            i, j = 0, 0
            while i != len(k1) or j != len(k2):
                if j == len(k2) or (i != len(k1) and k1[i] < k2[j]):
                    result.append(k1[i])
                    i += 1
                else:
                    result.append(k2[j])
                    j += 1
            return result

        result = Poly()
        for k1, v1 in self.iteritems():
            for k2, v2 in other.iteritems():
                result.update({tuple(merge(k1, k2)): v1*v2})
        clear(result)
        return result

    def eval(self, lookup):
        result = Poly()
        for polies, c in self.iteritems():
            key = []
            for var in polies:
                if var in lookup:
                    c *= lookup[var]
                else:
                    key.append(var)
            result[tuple(key)] += c
        clear(result)
        return result

    def to_list(self):
        return ["*".join((str(v),) + k)
                for k, v in sorted(self.iteritems(),
                                   key=lambda x: (-len(x[0]), x[0]))]


class Solution(object):
    def basicCalculatorIV(self, expression, evalvars, evalints):
        """
        :type expression: str
        :type evalvars: List[str]
        :type evalints: List[int]
        :rtype: List[str]
        """
        ops = {'+':operator.add, '-':operator.sub, '*':operator.mul}
        def compute(operands, operators):
            right, left = operands.pop(), operands.pop()
            operands.append(ops[operators.pop()](left, right))

        def parse(s):
            precedence = {'+':0, '-':0, '*':1}
            operands, operators, operand = [], [], []
            for i in xrange(len(s)):
                if s[i].isalnum():
                    operand.append(s[i])
                    if i == len(s)-1 or not s[i+1].isalnum():
                        operands.append(Poly("".join(operand)))
                        operand = []
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

        lookup = dict(itertools.izip(evalvars, evalints))
        return parse(expression).eval(lookup).to_list()


class Solution2(object):
    def basicCalculatorIV(self, expression, evalvars, evalints):
        """
        :type expression: str
        :type evalvars: List[str]
        :type evalints: List[int]
        :rtype: List[str]
        """
        def compute(operands, operators):
            left, right = operands.pop(), operands.pop()
            op = operators.pop()
            if op == '+':
                operands.append(left + right)
            elif op == '-':
                operands.append(left - right)
            elif op == '*':
                operands.append(left * right)

        def parse(s):
            if not s:
                return Poly()
            operands, operators = [], []
            operand = ""
            for i in reversed(xrange(len(s))):
                if s[i].isalnum():
                    operand += s[i]
                    if i == 0 or not s[i-1].isalnum():
                        operands.append(Poly(operand[::-1]))
                        operand = ""
                elif s[i] == ')' or s[i] == '*':
                    operators.append(s[i])
                elif s[i] == '+' or s[i] == '-':
                    while operators and operators[-1] == '*':
                        compute(operands, operators)
                    operators.append(s[i])
                elif s[i] == '(':
                    while operators[-1] != ')':
                        compute(operands, operators)
                    operators.pop()
            while operators:
                compute(operands, operators)
            return operands[-1]

        lookup = dict(itertools.izip(evalvars, evalints))
        return parse(expression).eval(lookup).to_list()

