# Time:  O(n)
# Space: O(1)

class Solution(object):
    def areNumbersAscending(self, s):
        """
        :type s: str
        :rtype: bool
        """
        prev = curr = -1
        for i, c in enumerate(s):
            if c.isdigit():
                curr = max(curr, 0)*10+int(c)
                continue
            if prev != -1 and curr != -1 and prev >= curr:
                return False
            if curr != -1:
                prev = curr
            curr = -1            
        return curr == -1 or prev < curr


# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def areNumbersAscending(self, s):
        """
        :type s: str
        :rtype: bool
        """
        nums = [int(x) for x in s.split() if x.isdigit()]
        return all(nums[i] < nums[i+1] for i in xrange(len(nums)-1))
