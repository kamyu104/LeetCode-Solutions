# Time:  ctor:         O(1)
#        add:          O(1)
#        deleteOne:    O(1)
#        hasFrequency: O(1)
# Space: O(min(n, r))

# freq table
class FrequencyTracker(object):

    def __init__(self):
        self.__cnt = collections.Counter()
        self.__freq = collections.Counter()

    def add(self, number):
        """
        :type number: int
        :rtype: None
        """
        self.__freq[self.__cnt[number]] -= 1
        if self.__freq[self.__cnt[number]] == 0:
            del self.__freq[self.__cnt[number]]
        self.__cnt[number] += 1
        self.__freq[self.__cnt[number]] += 1
        

    def deleteOne(self, number):
        """
        :type number: int
        :rtype: None
        """
        if self.__cnt[number] == 0:
            return
        self.__freq[self.__cnt[number]] -= 1
        if self.__freq[self.__cnt[number]] == 0:
            del self.__freq[self.__cnt[number]]
        self.__cnt[number] -= 1
        self.__freq[self.__cnt[number]] += 1
        if self.__cnt[number] == 0:
            del self.__cnt[number]
        

    def hasFrequency(self, frequency):
        """
        :type frequency: int
        :rtype: bool
        """
        return frequency in self.__freq
