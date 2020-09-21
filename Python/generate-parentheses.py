# Time:  O(4^n / n^(3/2)) ~= Catalan numbers
# Space: O(n)

# iterative solution
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result, curr = [], []
        stk = [(1, (n, n))]
        while stk:
            step, args = stk.pop()
            if step == 1:
                left, right = args
                if left == 0 and right == 0:
                    result.append("".join(curr))
                if left < right:
                    stk.append((3, tuple()))
                    stk.append((1, (left, right-1)))
                    stk.append((2, (')')))
                if left > 0:
                    stk.append((3, tuple()))
                    stk.append((1, (left-1, right)))
                    stk.append((2, ('(')))
            elif step == 2:
                curr.append(args[0])
            elif step == 3:
                curr.pop()
        return result


# Time:  O(4^n / n^(3/2)) ~= Catalan numbers
# Space: O(n)
# recursive solution
class Solution2(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def generateParenthesisRecu(left, right, curr, result):
            if left == 0 and right == 0:
                result.append("".join(curr))
            if left > 0:
                curr.append('(')
                generateParenthesisRecu(left-1, right, curr, result)
                curr.pop()
            if left < right:
                curr.append(')')
                generateParenthesisRecu(left, right-1, curr, result)
                curr.pop()

        result = []
        generateParenthesisRecu(n, n, [], result)
        return result
