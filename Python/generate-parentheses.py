# Time:  O(4^n / n^(3/2)) ~= Catalan numbers
# Space: O(n)

# iterative solution
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = []
        stk = [("", n, n)]
        while stk:
            curr, left, right = stk.pop()
            if left == 0 and right == 0:
                result.append(curr)
            if left < right:
                stk.append((curr+")", left, right-1))
            if left > 0:
                stk.append((curr+"(", left-1, right))
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
        def generateParenthesisRecu(result, current, left, right):
            if left == 0 and right == 0:
                result.append(current)
            if left > 0:
                generateParenthesisRecu(result, current + "(", left-1, right)
            if left < right:
                generateParenthesisRecu(result, current + ")", left, right-1)

        result = []
        generateParenthesisRecu(result, "", n, n)
        return result
