# Time:  O(n) on average
# Space: O(n)

import random
import itertools
import math


# random algorithms, variant of closest pair
# reference: https://github.com/jilljenn/tryalgo/blob/master/tryalgo/closest_points.py
random.seed(0)
class Solution(object):
    def beautifulPair(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        INF = float("inf")
        def dist(a, b):
            x, y = a[-1], b[-1]
            if x > y:
                x, y = y, x
            return [abs(a[0]-b[0])+abs(a[1]-b[1]), x, y]

        def cell(point, size):
            x, y, _ = point
            return math.floor(x/size), math.floor(y/size)

        def improve():
            lookup = {}
            for p in points:
                i, j = map(int, cell(p, result[0]/2.0))
                for ni in xrange(i-2, (i+2)+1):
                    for nj in xrange(j-2, (j+2)+1):
                        if (ni, nj) not in lookup:
                            continue
                        d = dist(p, lookup[ni, nj])
                        if d < result:
                            result[:] = d
                            return True
                lookup[i, j] = p
            return False

        points = [(i, j, idx) for idx, (i, j) in enumerate(itertools.izip(nums1, nums2))]
        result = [INF]*3
        lookup = {}
        for i in reversed(xrange(len(points))):
            if points[i][:2] in lookup:
                result = [0, i, lookup[points[i][:2]]]
            lookup[points[i][:2]] = i
        if result[0] == 0:
            return result[1:]
        random.shuffle(points)
        p, q = points[0], points[1]
        result = dist(p, q)
        while improve():
            pass
        return result[1:]


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
        MAX_NEIGHBOR_COUNT = (8+2)//2
        def dist(a, b):
            if a > b:
                a, b = b, a
            return [abs(points[a][0]-points[b][0])+abs(points[a][1]-points[b][1]), a, b]

        def merge_sort(left, right):
            def update(arr, i):  # added
                for j in reversed(xrange(len(arr))):
                    if points[i][1]-points[arr[j]][1] > result[0]:
                        break
                    result[:] = min(result, dist(i, arr[j]))
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
        result = [INF]*3
        lookup = {}
        for i in reversed(xrange(len(points))):
            if points[i] in lookup:
                result = [0, (i, lookup[points[i]])]
            lookup[points[i]] = i
        if result[0] == 0:
            return result[1]
        order = range(len(points))
        order.sort(key=lambda x: points[x])
        merge_sort(0, len(points)-1)
        return result[1:]


# Time:  O(nlogn)
# Space: O(n)
import itertools


# divide and conquer, merge sort, variant of closest pair
# reference: https://www.baeldung.com/cs/minimal-manhattan-distance
class Solution3(object):
    def beautifulPair(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        INF = float("inf")
        MAX_NEIGHBOR_COUNT = 8
        def dist(a, b):
            if a > b:
                a, b = b, a
            return [abs(points[a][0]-points[b][0])+abs(points[a][1]-points[b][1]), a, b]

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
                    result[:] = min(result, dist(x, y))
                else:
                    j = len(stripe)
                assert(j-(i+1) <= MAX_NEIGHBOR_COUNT)

        points = [(i, j) for i, j in itertools.izip(nums1, nums2)]
        result = [INF]*3
        lookup = {}
        for i in reversed(xrange(len(points))):
            if points[i] in lookup:
                result = [0, (i, lookup[points[i]])]
            lookup[points[i]] = i
        if result[0] == 0:
            return result[1]
        order = range(len(points))
        order.sort(key=lambda x: points[x])
        merge_sort(0, len(points)-1)
        return result[1:]
