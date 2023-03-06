# Time:  O(mlogm), m = O(logn)
# Space: O(m)

# sort, greedy
class Solution(object):
    def splitNum(self, num):
        """
        :type num: int
        :rtype: int
        """
        sorted_num = "".join(sorted(str(num)))
        return int(sorted_num[::2])+int(sorted_num[1::2])
