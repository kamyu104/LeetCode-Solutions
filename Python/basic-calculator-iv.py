# Time:  O(m + n^3 * logn)
# Space: O(m + n)

class Poly(collections.Counter):
    def __init__(self, expr=""):
        if not expr:
            return
        if expr.isdigit():
            self.update({(): int(expr)})
        else:
            self[(expr,)] += 1

    def __add__(self, other):
        self.update(other)
        return self

    def __sub__(self, other):
        self.update({k: -v for k, v in other.items()})
        return self

    def __mul__(self, other):
        result = Poly()
        for k1, v1 in self.items():
            for k2, v2 in other.items():
                result.update({tuple(sorted(k1+k2)): v1*v2})
        return result

    def evaluate(self, lookup):
        result = Poly()
        for k, c in self.items():
            poly = []
            for token in k:
                if token in lookup:
                    c *= lookup[token]
                else:
                    poly.append(token)
            result[tuple(poly)] += c
        return result

    def to_list(self):
        return ["*".join((str(v),) + k) \
                for k, v in sorted(self.items(), key=lambda(k, v): (-len(k), k, v)) \
                if v]
    
    
class Solution(object):
    def basicCalculatorIV(self, expression, evalvars, evalints):
        """
        :type expression: str
        :type evalvars: List[str]
        :type evalints: List[int]
        :rtype: List[str]
        """
        lookup = dict(itertools.izip(evalvars, evalints))

        def do_operator(left, right, operator):
            if operator == '+': return left + right
            if operator == '-': return left - right
            if operator == '*': return left * right
            raise

        def parse(expr):
            operands = []
            operators = []
            i = 0
            while i < len(expr):
                if expr[i] == '(':
                    cnt = 0
                    for j in xrange(i, len(expr)):
                        if expr[j] == '(': cnt += 1
                        if expr[j] == ')': cnt -= 1
                        if cnt == 0: break
                    operands.append(parse(expr[i+1:j]))
                    i = j
                elif expr[i].isalnum():
                    for j in xrange(i, len(expr)):
                        if expr[j] == ' ':
                            operands.append(Poly(expr[i:j]))
                            break
                    else:
                        operands.append(Poly(expr[i:]))
                    i = j
                elif expr[i] in '+-*':
                    operators.append(expr[i])
                i += 1

            for i in reversed(xrange(len(operators))):
                if operators[i] == '*':
                    operands[i] = do_operator(operands[i], operands.pop(i+1), \
                                              operators.pop(i))

            if not operands: return Poly()
            result = operands[0]
            for i, operator in enumerate(operators, 1):
                result = do_operator(result, operands[i], operator)
            return result

        return parse(expression).evaluate(lookup).to_list()
