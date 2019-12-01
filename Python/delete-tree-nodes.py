# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def deleteTreeNodes(self, nodes, parent, value):
        """
        :type nodes: int
        :type parent: List[int]
        :type value: List[int]
        :rtype: int
        """
        def dfs(value, children, x):
            total, count = value[x], 1
            for y in children[x]:
                t, c = dfs(value, children, y)
                total += t
                count += c if t else 0
            return total, count if total else 0

        children = collections.defaultdict(list)
        for i, p in enumerate(parent):
            if i:
                children[p].append(i)
        return dfs(value, children, 0)[1]


# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def deleteTreeNodes(self, nodes, parent, value):
        """
        :type nodes: int
        :type parent: List[int]
        :type value: List[int]
        :rtype: int
        """
        # assuming parent[i] < i for all i > 0
        result = [1]*nodes
        for i in reversed(xrange(1, nodes)):
            value[parent[i]] += value[i]
            result[parent[i]] += result[i] if value[i] else 0
        return result[0]
