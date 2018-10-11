from __future__ import print_function
# Time:  O(n)
# Space: O(1)

class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        length = 0
        for i in reversed(s):
            if i == ' ':
                if length:
                    break
            else:
                length += 1
        return length

class Solution2:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        return len(s.strip().split(" ")[-1])

if __name__ == "__main__":
    print(Solution().lengthOfLastWord("Hello World"))
    print(Solution2().lengthOfLastWord(""))

