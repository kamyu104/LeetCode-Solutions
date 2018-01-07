# Time:  O(n)
# Space: O(n)

class Solution(object):
    def anagramMappings(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        lookup = collections.defaultdict(collections.deque)
        for i, n in enumerate(B):
            lookup[n].append(i)
        result = []
        for n in A:
            result.append(lookup[n].popleft())
        return result
