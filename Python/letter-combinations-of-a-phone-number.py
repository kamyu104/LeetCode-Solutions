# Time:  O(n * 4^n)
# Space: O(1)

# iterative solution
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []

        lookup = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        total = 1
        for digit in digits:
            total *= len(lookup[int(digit)])
        result = []
        for i in xrange(total):
            base, curr = total, []
            for digit in digits:
                choices = lookup[int(digit)]
                base //= len(choices)
                curr.append(choices[(i//base)%len(choices)])
            result.append("".join(curr))
        return result


# Time:  O(n * 4^n)
# Space: O(1)
# iterative solution
class Solution2(object):
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
            result.extend([result[i % n] for i in xrange(n, m*n)])
            for i in xrange(m*n):
                result[i] = choices[i//n] + result[i]
        return result


# Time:  O(n * 4^n)
# Space: O(n)
# recursive solution
class Solution3(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        lookup = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

        def letterCombinationsRecu(result, digits, curr, n):
            if n == len(digits):
                result.append("".join(curr))
                return
            for choice in lookup[int(digits[n])]:
                curr.append(choice)
                letterCombinationsRecu(result, digits, curr, n+1)
                curr.pop()

        if not digits:
            return []
        result = []
        letterCombinationsRecu(result, digits, [], 0)
        return result

