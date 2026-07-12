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
        source, target = tuple(nums), tuple(xrange(len(nums)))
        left, right = {source}, {target}
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
        source, target = tuple(nums), tuple(xrange(len(nums)))
        lookup = {source}
        q = [source]
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
    
