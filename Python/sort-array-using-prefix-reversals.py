# Time:  O(n! * n * m)
# Space: O(n! * n)

# bi-bfs
class Solution(object):
    def sortArray(self, nums, pre):
        """
        :type nums: List[int]
        :type pre: List[int]
        :rtype: int
        """
        def bi_bfs(start, target):
            left, right = {start}, {target}
            lookup = set()
            steps = 0
            while left:
                if len(left) > len(right): 
                    left, right = right, left
                for x in left:
                    lookup.add(x)
                new_left = set()
                for x in left:
                    if x in right: 
                        return steps
                    for i in pre:
                        nx = tuple(reversed(x[:i]))+x[i:]
                        if nx in lookup:
                            continue
                        new_left.add(nx)
                left = new_left
                steps += 1
            return -1

        return bi_bfs(tuple(nums), tuple(xrange(len(nums))))


# Time:  O(n! * n * m)
# Space: O(n! * n)
# bfs
class Solution2(object):
    def sortArray(self, nums, pre):
        """
        :type nums: List[int]
        :type pre: List[int]
        :rtype: int
        """
        def bfs(start, target):
            lookup = {start}
            q = [start]
            steps = 0
            while q:
                new_q = []
                for x in q:
                    if x == target:
                        return steps
                    for i in pre:
                        nx = tuple(reversed(x[:i]))+x[i:]
                        if nx in lookup:
                            continue
                        lookup.add(nx)
                        new_q.append(nx)
                q = new_q
                steps += 1
            return -1

        return bfs(tuple(nums), tuple(xrange(len(nums))))
