# Time:  O(n)
# Space: O(1)

class Solution(object):
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

# Time:  O(n)
# Space: O(n)
class Solution2(object):
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        return len(s.strip().split(" ")[-1])

