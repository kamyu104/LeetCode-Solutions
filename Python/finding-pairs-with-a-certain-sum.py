# Time:  ctor:  O(n1 + n2)
#        add:   O(1)
#        count: O(n1)
# Space: O(n1 + n2)

import collections


class FindSumPairs(object):

    def __init__(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        """
        self.__nums2 = nums2
        self.__count1 = collections.Counter(nums1)
        self.__count2 = collections.Counter(nums2)

    def add(self, index, val):
        """
        :type index: int
        :type val: int
        :rtype: None
        """
        self.__count2[self.__nums2[index]] -= 1
        self.__nums2[index] += val
        self.__count2[self.__nums2[index]] += 1


    def count(self, tot):
        """
        :type tot: int
        :rtype: int
        """
        return sum(cnt * self.__count2[tot-x] for x, cnt in self.__count1.iteritems())
