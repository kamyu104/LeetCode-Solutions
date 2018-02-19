# Time:  O(n * 2^n)
# Space: O(1)

# Given a string S, we can transform every letter individually to be lowercase
# or uppercase to create another string.  Return a list of all possible strings we could create.
#
# Examples:
# Input: S = "a1b2"
# Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
#
# Input: S = "3z4"
# Output: ["3z4", "3Z4"]
#
# Input: S = "12345"
# Output: ["12345"]
#
# Note:
# - S will be a string with length at most 12.
# - S will consist only of letters or digits.

class Solution(object):
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        result = [[]]
        for c in S:
            if c.isalpha():
                for i in xrange(len(result)):
                    result.append(result[i][:])
                    result[-1].append(c.upper())
                    result[i].append(c.lower())
            else:
                for s in result:
                    s.append(c)
        return map("".join, result)
