from __future__ import print_function
# Time:  O(n)
# Space: O(n)

class Solution:
    # @return a boolean
    def isValid(self, s):
        stack, lookup = [], {"(": ")", "{": "}", "[": "]"}
        for parenthese in s:
            if parenthese in lookup:
                stack.append(parenthese)
            elif len(stack) == 0 or lookup[stack.pop()] != parenthese:
                return False
        return len(stack) == 0

if __name__ == "__main__":
    print(Solution().isValid("()[]{}"))
    print(Solution().isValid("()[{]}"))

