# Time:  O(n)
# Space: O(n)

class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        curr, nums, strs = [], [], []
        n = 0

        for c in s:
            if c.isdigit():
                n = n * 10 + ord(c) - ord('0')
            elif c == '[':
                nums.append(n)
                n = 0
                strs.append(curr)
                curr = []
            elif c == ']':
                strs[-1].extend(curr * nums.pop())
                curr = strs.pop()
            else:
                curr.append(c)

        return "".join(strs[-1]) if strs else "".join(curr)

