# Time:  O((m + n) * l), m is the size of list1, n is the size of list2
# Space: O(m * l), l is the average length of string

class Solution(object):
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        lookup = {}
        for i, s in enumerate(list1):
            lookup[s] = i

        result = []
        min_sum = float("inf")
        for j, s in enumerate(list2):
            if j > min_sum:
                break
            if s in lookup:
                if j + lookup[s] < min_sum:
                    result = [s]
                    min_sum = j + lookup[s]
                elif j + lookup[s] == min_sum:
                    result.append(s)
        return result

