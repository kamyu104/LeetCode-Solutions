# Time:  O(n)
# Space: O(1)

# sliding window, two pointers
class Solution(object):
    def numberOfAlternatingGroups(self, colors, k):
        """
        :type colors: List[int]
        :type k: int
        :rtype: int
        """
        result = curr = left = 0
        for right in xrange(len(colors)+k-1):  
            if right-left+1 == k:
                result += int(curr == k-1)
                curr -= int(colors[left] != colors[(left+1)%len(colors)])
                left += 1
            curr += int(colors[right%len(colors)] != colors[(right+1)%len(colors)])
        return result
