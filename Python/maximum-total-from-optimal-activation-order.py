# Time:  O(nlogn)
# Space: O(n)

# sort, greedy
class Solution(object):
    def maxTotal(self, value, limit):
        """
        :type value: List[int]
        :type limit: List[int]
        :rtype: int
        """
        idxs = range(len(value))
        idxs.sort(key=lambda x: (limit[x], -value[x]))
        result = cnt = prev = 0
        for i in idxs:
            l, v = limit[i], value[i]
            if l != prev:
                cnt = 0
                prev = l
            if cnt < l:
                result += v
                cnt += 1
        return result
