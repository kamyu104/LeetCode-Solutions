# Time:  O(4^n)
# Space: O(1)
#
# Given a digit string, return all possible letter combinations that the number could represent.
# 
# A mapping of digit to letters (just like on the telephone buttons) is given below.
# 
# lookup = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
# 
# Input:Digit string "23"
# Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
# Note:
# Although the above answer is in lexicographical order, your answer could be in any order you want.
#

# Iterative Solution
class Solution:
    # @return a list of strings, [s1, s2]
    def letterCombinations(self, digits):
        lookup, result = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"], [""]

        for digit in digits:
            choices = lookup[int(digit)]
            m, n = len(choices), len(result)
            result.extend([result[i % n] for i in xrange(n, m * n)])    

            for i in xrange(m * n):
                result[i] += choices[i / n]
            
        return result

# Time:  O(4^n)
# Space: O(n)
# Recursive Solution
class Solution2:
    # @return a list of strings, [s1, s2]
    def letterCombinations(self, digits):
        lookup, result = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"], []
        self.letterCombinationsRecu(result, digits, lookup, "", 0)
        return result
    
    def letterCombinationsRecu(self, result, digits, lookup, cur, n):
        if n == len(digits):
            result.append(cur)
        else:
            for choice in lookup[int(digits[n])]:
                self.letterCombinationsRecu(result, digits, lookup, cur + choice, n + 1)

if __name__ == "__main__":
    print Solution().letterCombinations("23")
