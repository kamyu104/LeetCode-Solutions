# Time:  O(x)
# Space: O(x)

# memoization
class Solution(object):
    def minimumOperationsToMakeEqual(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        def memoization(x):
            if y >= x:
                return y-x
            if x not in lookup:
                lookup[x] = min(x-y, min(min(x%d, d-x%d)+memoization(x//d+int(d-x%d < x%d))+1 for d in (5, 11)))
            return lookup[x]
    
        lookup = {}
        return memoization(x)


# Time:  O(x)
# Space: O(x)
# bfs
class Solution2(object):
    def minimumOperationsToMakeEqual(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """

        if y >= x:
            return y-x
        upper_bound = x+(x-y)
        result = 0
        lookup = {x}
        q = [x]
        while q:
            new_q = []
            for x in q:
                if x == y:
                    return result
                candidates = [x+1, x-1]
                for d in (5, 11):
                    if x%d == 0:
                        candidates.append(x//d)
                for new_x in candidates:
                    if not (0 <= new_x <= upper_bound and new_x not in lookup):
                        continue
                    lookup.add(new_x)
                    new_q.append(new_x)
            q = new_q
            result += 1
        return -1
