# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def totalFruit(self, tree):
        """
        :type tree: List[int]
        :rtype: int
        """
        count = collections.defaultdict(int)
        result, i = 0, 0
        for j, v in enumerate(tree):
            count[v] += 1
            while len(count) > 2:
                count[tree[i]] -= 1
                if count[tree[i]] == 0:
                    del count[tree[i]]
                i += 1
            result = max(result, j-i+1)
        return result
 

