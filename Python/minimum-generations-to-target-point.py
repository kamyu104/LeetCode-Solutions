# Time:  O(7^6)
# Space: O(7^3)

# bfs
class Solution(object):
    def minGenerations(self, points, target):
        """
        :type points: List[List[int]]
        :type target: List[int]
        :rtype: int
        """
        def encode(p):
            return p[0]*7*7+p[1]*7+p[2]
    
        lookup = [False]*(7**3)
        k = total = 0
        for p in points:
            if lookup[encode(p)]:
                continue
            if p == target:
                return k
            lookup[encode(p)] = True
        i = 0
        while i < len(points):
            if i == total:
                total = len(points)
                k += 1
            for j in xrange(i):
                p = [(points[i][0]+points[j][0])//2, (points[i][1]+points[j][1])//2, (points[i][2]+points[j][2])//2]
                if lookup[encode(p)]:
                    continue
                if p == target:
                    return k
                lookup[encode(p)] = True
                points.append(p)
            i += 1
        return -1


# Time:  O(7^6)
# Space: O(7^3)
# bfs
class Solution2(object):
    def minGenerations(self, points, target):
        """
        :type points: List[List[int]]
        :type target: List[int]
        :rtype: int
        """
        def encode(p):
            return p[0]*7*7+p[1]*7+p[2]
    
        lookup = [False]*(7**3)
        for p in points:
            if lookup[encode(p)]:
                continue
            lookup[encode(p)] = True
        i = k = 0
        while i < len(points):
            if lookup[encode(target)]:
                return k
            total = len(points)
            while i < total:
                for j in xrange(i):
                    p = [(points[i][0]+points[j][0])//2, (points[i][1]+points[j][1])//2, (points[i][2]+points[j][2])//2]
                    if lookup[encode(p)]:
                        continue
                    lookup[encode(p)] = True
                    points.append(p)
                i += 1
            k += 1
        return -1


# Time:  O(7^6)
# Space: O(7^3)
# bfs
class Solution3(object):
    def minGenerations(self, points, target):
        """
        :type points: List[List[int]]
        :type target: List[int]
        :rtype: int
        """
        def encode(p):
            return p[0]*7*7+p[1]*7+p[2]
    
        q = []
        lookup = [False]*(7**3)
        for p in points:
            if lookup[encode(p)]:
                continue
            lookup[encode(p)] = True
            q.append(p)
        k = 0
        while q:
            if lookup[encode(target)]:
                return k
            new_q = []
            for i in xrange(len(points)-len(q), len(points)):
                for j in xrange(i):
                    p = [(points[i][0]+points[j][0])//2, (points[i][1]+points[j][1])//2, (points[i][2]+points[j][2])//2]
                    if lookup[encode(p)]:
                        continue
                    lookup[encode(p)] = True
                    new_q.append(p)
            points.extend(new_q)
            q = new_q
            k += 1
        return -1
