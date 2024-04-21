# Time:  O(nlogn)
# Space: O(n)

# sort, greedy
class Solution(object):
    def maxPotholes(self, road, budget):
        """
        :type road: str
        :type budget: int
        :rtype: int
        """
        ls = []
        l = 0
        for i in xrange(len(road)):
            l += 1
            if i+1 == len(road) or road[i+1] != road[i]:
                if road[i] == 'x':
                    ls.append(l)
                l = 0
        ls.sort()
        result = 0
        for l in reversed(ls):
            c = min(l+1, budget)
            if c <= 1:
                break
            result += c-1
            budget -= c
        return result
