# Time:  O(n^2 * sqrt(r))
# Space: O(n^2)

import random


# number theory, quick select
class Solution(object):
    def sumOfLargestPrimes(self, s):
        """
        :type s: str
        :rtype: int
        """
        COUNT = 3
        def nth_element(nums, n, left=0, compare=lambda a, b: a < b):
            def tri_partition(nums, left, right, target, compare):
                mid = left
                while mid <= right:
                    if nums[mid] == target:
                        mid += 1
                    elif compare(nums[mid], target):
                        nums[left], nums[mid] = nums[mid], nums[left]
                        left += 1
                        mid += 1
                    else:
                        nums[mid], nums[right] = nums[right], nums[mid]
                        right -= 1
                return left, right
            
            right = len(nums)-1
            while left <= right:
                pivot_idx = random.randint(left, right)
                pivot_left, pivot_right = tri_partition(nums, left, right, nums[pivot_idx], compare)
                if pivot_left <= n <= pivot_right:
                    return
                elif pivot_left > n:
                    right = pivot_left-1
                else:  # pivot_right < n.
                    left = pivot_right+1

        def is_prime(n):
            if n == 1:
                return False
            if n in (2, 3):
                return True
            if n%2 == 0 or n%3 == 0:
                return False
            for i in xrange(5, n, 6):
                if i*i > n:
                    break
                if n%i == 0 or n%(i+2) == 0:
                    return False
            return True
    
        primes_set = set()
        for i in xrange(len(s)):
            curr = 0
            for j in xrange(i, len(s)):
                curr = curr*10+int(s[j])
                if is_prime(curr):
                    primes_set.add(curr)
        primes = list(primes_set)
        d = min(len(primes), COUNT)
        nth_element(primes, d, compare=lambda a, b: a > b)
        return sum(primes[i] for i in xrange(d))
