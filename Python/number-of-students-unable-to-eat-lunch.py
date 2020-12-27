# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def countStudents(self, students, sandwiches):
        """
        :type students: List[int]
        :type sandwiches: List[int]
        :rtype: int
        """
        count = collections.Counter(students)
        for i, s in enumerate(sandwiches):
            if not count[s]:
                break
            count[s] -= 1
        else:
            i = len(sandwiches)
        return len(sandwiches)-i
