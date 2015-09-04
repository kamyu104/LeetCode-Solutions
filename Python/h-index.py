# Time:  O(n)
# Space: O(n)

# Given an array of citations (each citation is a non-negative integer)
# of a researcher, write a function to compute the researcher's h-index.
#
# According to the definition of h-index on Wikipedia: 
# "A scientist has index h if h of his/her N papers have
# at least h citations each, and the other N − h papers have
# no more than h citations each."
#
# For example, given citations = [3, 0, 6, 1, 5], 
# which means the researcher has 5 papers in total
# and each of them had received 3, 0, 6, 1, 5 citations respectively. 
# Since the researcher has 3 papers with at least 3 citations each and 
# the remaining two with no more than 3 citations each, his h-index is 3.
#
# Note: If there are several possible values for h, the maximum one is taken as the h-index.
#

class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations);
        count = [0] * (n + 1)
        for x in citations:
            if x >= n:
                count[n] += 1
            else:
                count[x] += 1

        h = 0
        for i in reversed(xrange(0, n + 1)):
            h += count[i]
            if h >= i:
                return i
        return h

# Time:  O(nlogn)
# Space: O(1)
class Solution2(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        citations.sort(reverse=True)
        h = 0
        for x in citations:
            if x >= h + 1:
                h += 1
            else:
                break
        return h
  
# Time:  O(nlogn)
# Space: O(n)
class Solution2(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        return sum(x >= i + 1 for i, x in enumerate(sorted(citations, reverse=True)))
  
