# Time:  O(|V| + |E|)
# Space: O(|E|)

import collections

class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        res, zero_in_degree_queue, in_degree, out_degree = [], collections.deque(), {}, {}

        for i, j in prerequisites:
            if i not in in_degree:
                in_degree[i] = set()
            if j not in out_degree:
                out_degree[j] = set()
            in_degree[i].add(j)
            out_degree[j].add(i)

        for i in xrange(numCourses):
            if i not in in_degree:
                zero_in_degree_queue.append(i)

        while zero_in_degree_queue:
            prerequisite = zero_in_degree_queue.popleft()
            res.append(prerequisite)

            if prerequisite in out_degree:
                for course in out_degree[prerequisite]:
                    in_degree[course].discard(prerequisite)
                    if not in_degree[course]:
                        zero_in_degree_queue.append(course)

                del out_degree[prerequisite]

        if out_degree:
            return []

        return res

