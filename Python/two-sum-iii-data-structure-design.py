# Time:  O(n)
# Space: O(n)

from collections import defaultdict

class TwoSum(object):

    def __init__(self):
        """
        initialize your data structure here
        """
        self.lookup = defaultdict(int)



    def add(self, number):
        """
        Add the number to an internal data structure.
        :rtype: nothing
        """
        self.lookup[number] += 1


    def find(self, value):
        """
        Find if there exists any pair of numbers which sum is equal to the value.
        :type value: int
        :rtype: bool
        """
        for key in self.lookup:
            num = value - key
            if num in self.lookup and (num != key or self.lookup[key] > 1):
                return True
        return False


