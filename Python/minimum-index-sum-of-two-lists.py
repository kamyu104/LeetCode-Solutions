# Time:  O(m + n), m is the size of list1, n is the size of list2
# Space: O(m * l), l is the max length of string

# Suppose Andy and Doris want to choose a restaurant for dinner,
# and they both have a list of favorite restaurants represented by strings.
#
# You need to help them find out their common interest with the least list index sum.
# If there is a choice tie between answers, output all of them with no order requirement.
# You could assume there always exists an answer.
#
# Example 1:
# Input:
# ["Shogun", "Tapioca Express", "Burger King", "KFC"]
# ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
# Output: ["Shogun"]
# Explanation: The only restaurant they both like is "Shogun".
# Example 2:
# Input:
# ["Shogun", "Tapioca Express", "Burger King", "KFC"]
# ["KFC", "Shogun", "Burger King"]
# Output: ["Shogun"]
# Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
# Note:
# The length of both lists will be in the range of [1, 1000].
# The length of strings in both lists will be in the range of [1, 30].
# The index is starting from 0 to the list length minus 1.
# No duplicates in both lists.

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
