# Time:  O(nlogn)
# Space: O(n)

import itertools


# divide and conquer, merge sort, variant of closest pair
# reference: https://www.baeldung.com/cs/minimal-manhattan-distance
class Solution(object):
    def beautifulPair(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        INF = float("inf")
        MAX_NEIGHBOR_COUNT = (8+2)//2
        def manhattan_distance(a, b):
            return abs(a[0]-b[0])+abs(a[1]-b[1])
    
        def merge_sort(left, right):
            def update(arr, i):  # added
                for j in reversed(xrange(len(arr))):
                    if points[i][1]-points[arr[j]][1] > result[0]:
                        break
                    x, y = i, arr[j]
                    if x > y:
                        x, y = y, x
                    result[:] = min(result, [manhattan_distance(points[x], points[y]), (x, y)])
                else:
                    j = -1
                assert((len(arr)-1)-j <= MAX_NEIGHBOR_COUNT)

            if left == right:
                return
            mid = left+(right-left)//2
            x = points[order[mid]][0]  # added
            merge_sort(left, mid)
            merge_sort(mid+1, right)
            tmp, tmp_l, tmp_r = [], [], []
            l, r = left, mid+1
            while l <= mid or r <= right:
                if r == right+1 or (l <= mid and points[order[l]][1] <= points[order[r]][1]):  # modified
                    update(tmp_r, order[l])
                    if x-points[order[l]][0] <= result[0]:  # added
                        tmp_l.append(order[l])
                    tmp.append(order[l])
                    l += 1
                else:
                    update(tmp_l, order[r])
                    if points[order[r]][0]-x <= result[0]:  # added
                        tmp_r.append(order[r])
                    tmp.append(order[r])
                    r += 1
            order[left:right+1] = tmp

        points = [(i, j) for i, j in itertools.izip(nums1, nums2)]
        result = [INF, (INF, INF)]
        lookup = {}
        for i in reversed(xrange(len(points))):
            if points[i] in lookup:
                result = [0, (i, lookup[points[i]])]
            lookup[points[i]] = i            
        if result[0] == 0:
            return result[1]
        order = range(len(points))
        order.sort(key=lambda x: points[x])
        result = [INF, (INF, INF)]
        merge_sort(0, len(points)-1)
        return result[1]


# Time:  O(nlogn)
# Space: O(n)
import itertools


# divide and conquer, merge sort, variant of closest pair
# reference: https://www.baeldung.com/cs/minimal-manhattan-distance
class Solution2(object):
    def beautifulPair(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        INF = float("inf")
        MAX_NEIGHBOR_COUNT = 8
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

        points = [(i, j) for i, j in itertools.izip(nums1, nums2)]
        result = [INF, (INF, INF)]
        lookup = {}
        for i in reversed(xrange(len(points))):
            if points[i] in lookup:
                result = [0, (i, lookup[points[i]])]
            lookup[points[i]] = i            
        if result[0] == 0:
            return result[1]
        order = range(len(points))
        order.sort(key=lambda x: points[x])
        result = [INF, (INF, INF)]
        merge_sort(0, len(points)-1)
        return result[1]
