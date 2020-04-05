# Time:  O(n)
# Space: O(1)

import heapq


class Solution(object):
    def longestDiverseString(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: str
        """
        max_heap = []
        if a:
            heapq.heappush(max_heap, (-a, 'a'))
        if b:
            heapq.heappush(max_heap, (-b, 'b'))
        if c:
            heapq.heappush(max_heap, (-c, 'c'))
        result = []
        while max_heap:
            count1, c1 = heapq.heappop(max_heap)
            if len(result) >= 2 and result[-1] == result[-2] == c1:
                if not max_heap:
                    return "".join(result)
                count2, c2 = heapq.heappop(max_heap)
                result.append(c2)
                count2 += 1
                if count2:
                    heapq.heappush(max_heap, (count2, c2))
                heapq.heappush(max_heap, (count1, c1))
                continue
            result.append(c1)
            count1 += 1
            if count1 != 0:
                heapq.heappush(max_heap, (count1, c1))
        return "".join(result)


# Time:  O(n)
# Space: O(1)
class Solution2(object):
    def longestDiverseString(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: str
        """
        choices = [[a, 'a'], [b, 'b'], [c, 'c']]
        result = []
        for _ in xrange(a+b+c):
            choices.sort(reverse=True)
            for i, (x, c) in enumerate(choices):
                if x and result[-2:] != [c, c]:
                    result.append(c)
                    choices[i][0] -= 1
                    break
            else:
                break
        return "".join(result)
