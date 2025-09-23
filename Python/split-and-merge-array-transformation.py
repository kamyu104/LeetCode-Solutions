# Time:  O(n^4 * n!)
# Space: O(n * n!)

# bfs
class Solution(object):
    def minSplitMerge(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        def bfs(start, target):
            def adj(arr):
                for l in xrange(len(arr)):
                    for r in xrange(l, len(arr)):
                        sub = arr[l:r+1]
                        rem = arr[:l]+arr[r+1:]
                        for i in xrange(len(rem)+1):
                            if i == l:
                                continue
                            yield rem[:i]+sub+rem[i:]

            d = 0
            if start == target:
                return d
            lookup = {start}
            q = [start]
            d += 1
            while q:
                new_q = []
                for u in q:
                    for v in adj(u):
                        if v in lookup:
                            continue
                        if v == target:
                            return d
                        lookup.add(v)
                        new_q.append(v)
                q = new_q
                d += 1
            return -1
    
        return bfs(tuple(nums1), tuple(nums2))


# Time:  O(n^4 * n!)
# Space: O(n * n!)
# bfs
class Solution2(object):
    def minSplitMerge(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        def bfs(start, target):
            def adj(arr):
                for l in xrange(len(arr)):
                    for r in xrange(l, len(arr)):
                        sub = arr[l:r+1]
                        rem = arr[:l]+arr[r+1:]
                        for i in xrange(len(rem)+1):
                            if i == l:
                                continue
                            yield rem[:i]+sub+rem[i:]

            d = 0
            lookup = {start}
            q = [start]
            while q:
                new_q = []
                for u in q:
                    if u == target:
                        return d
                    for v in adj(u):
                        if v in lookup:
                            continue
                        lookup.add(v)
                        new_q.append(v)
                q = new_q
                d += 1
            return -1

        return bfs(tuple(nums1), tuple(nums2))
