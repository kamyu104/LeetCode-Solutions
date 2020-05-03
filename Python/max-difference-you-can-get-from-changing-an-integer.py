# Time:  O(logn)
# Space: O(logn)

class Solution(object):
    def maxDiff(self, num):
        """
        :type num: int
        :rtype: int
        """
        digits = str(num)
        for b in digits:
            if b < '9':
                break
        if digits[0] != '1':
            a = digits[0]
        else:
            for a in digits:
                if a > '1':
                    break
        return int(digits.replace(b, '9')) - \
               int(digits.replace(a, '1' if digits[0] != '1' else '0'))
