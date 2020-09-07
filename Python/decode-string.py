# Time:  O(n)
# Space: O(n)

class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        n, curr, nums, strs = 0, [], [], []
        for c in s:
            if c.isdigit():
                n = n*10 + ord(c)-ord('0')
            elif c.isalpha():
                curr.append(c)
            elif c == '[':
                nums.append(n)
                strs.append(curr)
                n, curr = 0, []
            elif c == ']':
                strs[-1].extend(curr*nums.pop())
                curr = strs.pop()
        return "".join(curr)
