# Time:  O(mlogm + nlogn + (m + n) * logr), r = 2*(max(max(hens), max(grains))-min(min(hens), min(grains))
# Space: O(1)

# binary search, greedy
class Solution(object):
    def minimumTime(self, hens, grains):
        """
        :type hens: List[int]
        :type grains: List[int]
        :rtype: int
        """
        def check(x):
            i = 0
            for h in hens:
                if h-grains[i] > x:
                    return False
                elif h-grains[i] > 0:
                    d = h-grains[i]
                    c = max(x-2*d, (x-d)//2)  # max(go left then right, go right then left)
                else:
                    c = x                   
                while i < len(grains) and grains[i] <= h+c:
                    i += 1
                if i == len(grains):
                    return True
            return False
    
        hens.sort()
        grains.sort()
        left, right = 0, 2*(max(grains[-1], hens[-1])-min(grains[0], hens[0]))
        while left <= right:
            mid = left+(right-left)//2
            if check(mid):
                right = mid-1
            else:
                left = mid+1
        return left
    
