# Time:  O(nlogn)
# Space: O(n)

import itertools


# divide and conquer, merge sort
# reference: https://www.baeldung.com/cs/minimal-manhattan-distance
class Solution(object):
    def beautifulPair(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        INF = float("inf")
        MAX_NEIGHBOR_COUNT = 9
        def manhattan_distance(a, b):
            return abs(a[0]-b[0])+abs(a[1]-b[1])
    
        def merge_sort(left, right):
            if left == right:
                return
            mid = left + (right-left)//2
            x = points[order[mid]][0]  # added
            merge_sort(left, mid)
            merge_sort(mid+1, right)
            r = mid+1
            tmp = []
            for l in xrange(left, mid+1):
                while r <= right and points[order[r]][1] < points[order[l]][1]:  # modified
                    tmp.append(order[r])
                    r += 1
                tmp.append(order[l])
            order[left:left+len(tmp)] = tmp

            # added below
            stripe = [order[i] for i in xrange(left, right+1) if abs(points[order[i]][0]-x) <= result[0]]
            for i in xrange(len(stripe)-1):
                for j in xrange(i+1, len(stripe)):
                    x, y = stripe[i], stripe[j]
                    if points[y][1]-points[x][1] > result[0]:
                        break
                    if x > y:
                        x, y = y, x
                    result[:] = min(result, [manhattan_distance(points[x], points[y]), (x, y)])
                else:
                    j = len(stripe)
                assert(j-(i+1) <= MAX_NEIGHBOR_COUNT)

        points = [(i, j, idx) for idx, (i, j) in enumerate(itertools.izip(nums1, nums2))]
        order = range(len(points))
        order.sort(key=lambda x: (points[x], x))
        result = [INF, (INF, INF)]
        for i in xrange(len(order)-1):
            if points[order[i]][:2] == points[order[i+1]][:2]:
                result = min(result, [0, (points[order[i]][2], points[order[i+1]][2])]) 
        if result[0]:
            merge_sort(0, len(points)-1)
        return result[1]
