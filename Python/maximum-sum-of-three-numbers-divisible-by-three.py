# Time:  O(n)
# Space: O(1)

# sort, math
class Solution(object):
    def maximumSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def add(arr, x):
            for i in xrange(len(arr)):
                if x > arr[i]:
                    arr[i], x = x, arr[i]
            if len(arr) != 3:
                arr.append(x)

        group = [[] for _ in xrange(3)]
        for x in nums:
            add(group[x%3], x)
        result = 0
        for g in group:
            if len(g) == 3:
                result = max(result, sum(g))
        if group[0] and group[1] and group[2]:
            result = max(result, group[0][0]+group[1][0]+group[2][0])
        return result


# Time:  O(nlogn)
# Space: O(n)
# sort, math
class Solution2(object):
    def maximumSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        group = [[] for _ in xrange(3)]
        for x in nums:
            group[x%3].append(x)
        result = 0
        for g in group:
            g.sort(reverse=True)
            if len(g) >= 3:
                result = max(result, sum(g[i] for i in xrange(3)))
        if group[0] and group[1] and group[2]:
            result = max(result, group[0][0]+group[1][0]+group[2][0])
        return result
