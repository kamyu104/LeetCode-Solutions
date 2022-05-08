# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def largestGoodInteger(self, num):
        """
        :type num: str
        :rtype: str
        """
        result = ''
        cnt = 0
        for i, x in enumerate(num):
            cnt += 1
            if i+1 < len(num) and num[i] == num[i+1]:
                continue
            if cnt >= 3:
                result = max(result, num[i])
            cnt = 0
        return result*3


# Time:  O(n)
# Space: O(1)
# string
class Solution2(object):
    def largestGoodInteger(self, num):
        """
        :type num: str
        :rtype: str
        """
        return max(num[i] if num[i] == num[i+1] == num[i+2] else '' for i in xrange(len(num)-2))*3
