# Time:  O(nlogn)
# Space: O(n)

# sort, line sweep, coordinate compression
class Solution(object):
    def maxIntersectionCount(self, y):
        """
        :type y: List[int]
        :rtype: int
        """
        val_to_idx = {x:i for i, x in enumerate(sorted(set(y)))}
        cnts = [0]*(2*len(val_to_idx)+1)
        for i in xrange(len(y)-1):
            # [y[i], y[i+1]) <=> [y[i], y[i+1]-0.5] <=> [2*y[i], 2*y[i+1]-1]
            left, right = 2*val_to_idx[y[i]], 2*val_to_idx[y[i+1]]+(-1 if y[i] < y[i+1] else +1)
            cnts[min(left, right)] += 1
            cnts[max(left, right)+1] -= 1
        # [y[i], y[i]] <=> [2*y[i], 2*y[i]]
        cnts[2*val_to_idx[y[-1]]] += 1
        cnts[2*val_to_idx[y[-1]]+1] -= 1
        result = cnt = 0
        for c in cnts:
            cnt += c
            result = max(result, cnt)
        return result
    

# Time:  O(nlogn)
# Space: O(n)
# sort, line sweep
class Solution2(object):
    def maxIntersectionCount(self, y):
        """
        :type y: List[int]
        :rtype: int
        """
        events = []
        for i in xrange(len(y)-1):
            # [y[i], y[i+1]) <=> [y[i], y[i+1]-0.5] <=> [2*y[i], 2*y[i+1]-1]
            left, right = 2*y[i], 2*y[i+1]+(-1 if y[i] < y[i+1] else +1)
            events.append((min(left, right), +1))
            events.append((max(left, right)+1, -1))
        # [y[i], y[i]] <=> [2*y[i], 2*y[i]]
        events.append((2*y[-1], +1))
        events.append((2*y[-1]+1, -1))
        events.sort()
        result = cnt = 0
        for _, c in events:
            cnt += c
            result = max(result, cnt)
        return result
