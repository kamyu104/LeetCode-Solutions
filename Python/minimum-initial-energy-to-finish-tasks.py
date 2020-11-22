# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def minimumEffort(self, tasks):
        """
        :type tasks: List[List[int]]
        :rtype: int
        """
        tasks.sort(key=lambda x: x[1]-x[0])  # sort by waste in asc
        result = 0
        # you can see proof here, https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/discuss/944633/Explanation-on-why-sort-by-difference
        for a, m in tasks:  # we need to pick all the wastes, so greedily to pick the least waste first is always better
            result = max(result+a, m)
        return result


# Time:  O(nlogn)
# Space: O(1)
class Solution2(object):
    def minimumEffort(self, tasks):
        """
        :type tasks: List[List[int]]
        :rtype: int
        """
        tasks.sort(key=lambda x: x[0]-x[1])  # sort by save in desc
        result = curr = 0
        for a, m in tasks:  # we need to pick all the saves, so greedily to pick the most save first is always better
            result += max(m-curr, 0)
            curr = max(curr, m)-a
        return result
