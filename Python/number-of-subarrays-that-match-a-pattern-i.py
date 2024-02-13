# Time:  O(n)
# Space: O(m)

# kmp
class Solution(object):
    def countMatchingSubarrays(self, nums, pattern):
        """
        :type nums: List[int]
        :type pattern: List[int]
        :rtype: int
        """
        def getPrefix(pattern):
            prefix = [-1]*len(pattern)
            j = -1
            for i in xrange(1, len(pattern)):
                while j+1 > 0 and pattern[j+1] != pattern[i]:
                    j = prefix[j]
                if pattern[j+1] == pattern[i]:
                    j += 1
                prefix[i] = j
            return prefix

        def KMP(text, pattern):
            prefix = getPrefix(pattern)
            j = -1
            for i, x in enumerate(text):
                while j+1 > 0 and pattern[j+1] != x:
                    j = prefix[j]
                if pattern[j+1] == x:
                    j += 1
                if j+1 == len(pattern):
                    yield i-j
                    j = prefix[j]

        return sum(1 for _ in KMP((cmp(nums[i+1], nums[i]) for i in xrange(len(nums)-1)), pattern))


# Time:  O(n * m)
# Space: O(1)
# brute force
class Solution2(object):
    def countMatchingSubarrays(self, nums, pattern):
        """
        :type nums: List[int]
        :type pattern: List[int]
        :rtype: int
        """
        def check(i):
            return all(nums[i+j] == pattern[j] for j in xrange(len(pattern)))
    
        for i in xrange(len(nums)-1):
            nums[i] = cmp(nums[i+1], nums[i])
        return sum(check(i) for i in xrange(len(nums)-len(pattern)+1))
