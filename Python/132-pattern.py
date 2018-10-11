# Time:  O(n)
# Space: O(n)

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3

class Solution(object):
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        ak = float("-inf")
        st = []
        for i in reversed(xrange(len(nums))):
            if nums[i] < ak:
                return True
            else:
                while st and nums[i] > st[-1]:
                    ak = st.pop()
            st.append(nums[i])
        return False

