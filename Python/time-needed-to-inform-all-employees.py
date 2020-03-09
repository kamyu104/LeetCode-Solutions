# Time:  O(n)
# Space: O(n)

import collections


# dfs solution with stack
class Solution(object):
    def numOfMinutes(self, n, headID, manager, informTime):
        """
        :type n: int
        :type headID: int
        :type manager: List[int]
        :type informTime: List[int]
        :rtype: int
        """
        children = collections.defaultdict(list)
        for child, parent in enumerate(manager):
            if parent != -1:
                children[parent].append(child)

        result = 0
        stk = [(headID, 0)]
        while stk:
            node, curr = stk.pop()
            curr += informTime[node]
            result = max(result, curr)
            if node not in children:
                continue
            for c in children[node]:
                stk.append((c, curr))
        return result

    
# Time:  O(n)
# Space: O(n)
# dfs solution with recursion
class Solution2(object):
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
