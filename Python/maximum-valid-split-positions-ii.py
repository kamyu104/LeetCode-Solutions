# Time:  O(n + (logr)^2)) = O(n)
# Space: O(n + logr) = O(n)

# number theory, prefix sum
class Solution(object):
    def maxValidSplits(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Time: O(logr), Space: O(1)
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        # Time: O(n + logr), Space: O(n)
        def prefix_gcd(nums):
            prefix = [0]*(len(nums)+1)
            for i in xrange(len(nums)):
                prefix[i+1] = gcd(prefix[i], nums[i])
            return prefix

        # Time: O(n + logr), Space: O(n)
        def suffix_gcd(nums):
            suffix = [0]*(len(nums)+1)
            for i in reversed(xrange(len(nums))):
                suffix[i] = gcd(suffix[i+1], nums[i])
            return suffix

        # Time: O(n + (logr)^2), Space: O(n)
        def diff(nums, candidates):
            # Time: O(1), Space: O(1)
            def add(groups, x, left, right):
                if groups and groups[-1][0] == x:
                    groups[-1][2] = right
                else:
                    groups.append([x, left, right])

            # Time: O(1), Space: O(1)
            def count(lookup, x, left, right):
                if x not in lookup:
                    return 0
                l, r = lookup[x]
                return max(min(right, r)-max(left, l)+1, 0)

            prefix = prefix_gcd(nums)
            suffix = suffix_gcd(nums)
            lookup = {}
            left = 0
            while left < len(nums):
                right = left
                while right+1 < len(nums) and suffix[right+1] == suffix[left]:
                    right += 1
                lookup[suffix[left]] = (left-1, right-1)
                left = right+1
            result = [0]*len(candidates)
            groups = []
            for i in reversed(xrange(len(candidates))):
                new_groups = []
                g = 0
                for j in xrange(candidates[i]+1, (candidates[i+1] if i+1 < len(candidates) else len(nums)-1)+1):
                    g = gcd(g, nums[j])
                    add(new_groups, g, j, j)
                for x, left, right in groups:
                    g = gcd(g, x)
                    add(new_groups, g, left, right)
                groups = new_groups
                new_g = prefix[candidates[i]]
                old_g = nums[candidates[i]]
                for x, left, right in groups:
                    new_g = gcd(new_g, x)
                    old_g = gcd(old_g, new_g)
                    right = min(right, len(nums)-2)
                    if left > right:
                        continue
                    result[i] += count(lookup, new_g, left, right)-count(lookup, old_g, left, right)
            return result

        prefix = prefix_gcd(nums)
        suffix = suffix_gcd(nums)
        candidates = [i for i in xrange(len(nums)) if prefix[i+1] != prefix[i]]
        left = diff(nums[::-1], [len(nums)-1-x for x in reversed(candidates)])
        right = diff(nums, candidates)
        valid = [prefix[i+1] == suffix[i+1] for i in xrange(len(nums)-1)]
        result = base = sum(valid)
        for i, x in enumerate(candidates):
            total = base
            total += left[~i]   # split < x-1
            if x-1 >= 0:        # split = x-1
                total += (prefix[x] == suffix[x+1])-valid[x-1]
            if x < len(valid):  # split = x
                total += 0-valid[x]
            total += right[i]   # split > x
            result = max(result, total)
        return result


# Time:  O(logr * (n + logr)) = O(nlogr)
# Space: O(n)
# number theory, prefix sum
class Solution2(object):
    def maxValidSplits(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Time: O(logr), Space: O(1)
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        # Time: O(n + logr), Space: O(n)
        def count(skip):
            prefix = [0]*(len(nums)+1)
            for i in xrange(len(nums)):
                prefix[i+1] = gcd(prefix[i], nums[i]) if i != skip else prefix[i]
            suffix = [0]*(len(nums)+1)
            for i in reversed(xrange(len(nums))):
                suffix[i] = gcd(suffix[i+1], nums[i]) if i != skip else suffix[i+1]
            return sum(i != skip and prefix[i+1] == suffix[i+1] for i in xrange(len(nums)-1))

        prefix = [0]*(len(nums)+1)
        for i in xrange(len(nums)):
            prefix[i+1] = gcd(prefix[i], nums[i])
        return max(count(i) for i in xrange(-1, len(nums)) if i == -1 or prefix[i+1] != prefix[i])
