# Time:  O(n)
# Space: O(n)

# hash table
class Solution(object):
    def simulationResult(self, windows, queries):
        """
        :type windows: List[int]
        :type queries: List[int]
        :rtype: List[int]
        """
        lookup = [False]*len(windows)
        result = []
        for x in reversed(queries):
            if lookup[x-1]:
                continue
            lookup[x-1] = True
            result.append(x)
        result.extend(x for x in windows if not lookup[x-1])
        return result
