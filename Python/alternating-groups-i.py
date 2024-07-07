# Time:  O(n)
# Space: O(1)

# sliding window, two pointers
class Solution(object):
    def numberOfAlternatingGroups(self, colors):
        """
        :type colors: List[int]
        :rtype: int
        """
        k = 3
        result = curr = left = 0
        for right in xrange(len(colors)+k-1):  
            if right-left+1 == k:
                result += int(curr == k-1)
                curr -= int(colors[left] != colors[(left+1)%len(colors)])
                left += 1
            curr += int(colors[right%len(colors)] != colors[(right+1)%len(colors)])
        return result


# Time:  O(n)
# Space: O(1)
# sliding window
class Solution2(object):
    def numberOfAlternatingGroups(self, colors):
        """
        :type colors: List[int]
        :rtype: int
        """
        return sum(colors[i] != colors[(i+1)%len(colors)] != colors[(i+2)%len(colors)] for i in xrange(len(colors)))
