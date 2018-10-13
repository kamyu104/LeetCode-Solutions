# Time:  O(4^n / n^(3/2)) ~= Catalan numbers
# Space: O(n)

class Solution(object):
    # @param an integer
    # @return a list of string
    def generateParenthesis(self, n):
        result = []
        self.generateParenthesisRecu(result, "", n, n)
        return result

    def generateParenthesisRecu(self, result, current, left, right):
        if left == 0 and right == 0:
            result.append(current)
        if left > 0:
            self.generateParenthesisRecu(result, current + "(", left - 1, right)
        if left < right:
            self.generateParenthesisRecu(result, current + ")", left, right - 1)

