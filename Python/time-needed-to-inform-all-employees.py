# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def numOfMinutes(self, n, headID, manager, informTime):
        """
        :type n: int
        :type headID: int
        :type manager: List[int]
        :type informTime: List[int]
        :rtype: int
        """
        def dfs(informTime, children, node):
            return (max(dfs(informTime, children, c)
                        for c in children[node])
                    if node in children
                    else 0) + informTime[node]

        children = collections.defaultdict(list)
        for child, parent in enumerate(manager):
            if parent != -1:
                children[parent].append(child)
        return dfs(informTime, children, headID)
