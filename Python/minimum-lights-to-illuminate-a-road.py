# Time:  O(n)
# Space: O(n)

# difference array, greedy
class Solution(object):
    def minLights(self, lights):
        """
        :type lights: List[int]
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+b-1)//b
        
        diff = [0]*(len(lights)+1)
        for i in xrange(len(lights)):
            if not lights[i]:
                continue
            diff[max(i-lights[i], 0)] += 1
            diff[min(i+lights[i], len(lights)-1)+1] -= 1
        result = curr = cnt = 0
        for i in xrange(len(diff)):
            curr += diff[i]
            if i+1 == len(diff) or curr:
                result += ceil_divide(cnt, 3)
                cnt = 0
            else:
                cnt += 1
        return result
