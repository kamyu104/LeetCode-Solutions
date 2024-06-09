# Time:  O(n)
# Space: O(1)

# two pointers
class Solution(object):
    def clearDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = list(s)
        j = 0
        for i, x in enumerate(s):
            if x.isdigit():
                j -= 1
                continue
            s[j] = x
            j += 1
        while len(s) > j:
            s.pop()
        return "".join(s)


# Time:  O(n)
# Space: O(1)
# stack
class Solution2(object):
    def clearDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = []
        for x in s:
            if x.isdigit():
                result.pop()
                continue
            result.append(x)
        return "".join(result)
