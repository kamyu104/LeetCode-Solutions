# Time:  O(n * 4^n)
# Space: O(n)

# iterative solution
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []

        result = [""]
        lookup = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        for digit in reversed(digits):
            choices = lookup[int(digit)]
            m, n = len(choices), len(result)
            result += [result[i % n] for i in xrange(n, m*n)]
            for i in xrange(m*n):
                result[i] = choices[i//n] + result[i]
        return result


# Time:  O(n * 4^n)
# Space: O(n)
# recursive solution
class Solution2(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        def letterCombinationsRecu(result, digits, lookup, curr, n):
            if n == len(digits):
                result.append(curr)
                return
            for choice in lookup[int(digits[n])]:
                letterCombinationsRecu(result, digits, lookup, curr+choice, n+1)

        if not digits:
            return []
        result = []
        lookup = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        letterCombinationsRecu(result, digits, lookup, "", 0)
        return result

