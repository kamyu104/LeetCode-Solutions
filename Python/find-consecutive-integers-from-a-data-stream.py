# Time:  O(1)
# Space: O(1)

# array
class DataStream(object):

    def __init__(self, value, k):
        """
        :type value: int
        :type k: int
        """
        self.__value = value
        self.__k = k
        self.__cnt = 0

    def consec(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num == self.__value:
            self.__cnt += 1
        else:
            self.__cnt = 0
        return self.__cnt >= self.__k
