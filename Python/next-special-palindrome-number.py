# Time:  precompute: O(9 * 2^9 + 16 * p + plogp), p = len(PALINDROMES)
#        runtime:    O(logp)
# Space: O(p)

import bisect


# precompute, bitmasks, sort, binary search
def next_permutation(nums, begin, end):
    def reverse(nums, begin, end):
        left, right = begin, end-1
        while left < right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1

    k, l = begin-1, begin
    for i in reversed(xrange(begin, end-1)):
        if nums[i] < nums[i+1]:
            k = i
            break
    else:
        reverse(nums, begin, end)
        return False
    for i in reversed(xrange(k+1, end)):
        if nums[i] > nums[k]:
            l = i
            break
    nums[k], nums[l] = nums[l], nums[k]
    reverse(nums, k+1, end)
    return True


def precompute():
    def f(mask):
        result = []
        mid = ""
        for i in xrange(9):
            if mask&(1<<i) == 0:
                continue
            if (i+1)%2:
                if mid:
                    return result, mid, False
                mid = str(i+1)
            result.extend([str(i+1)]*((i+1)//2))
        return result, mid, True

    result = []
    for mask in xrange(1, 1<<9):
        left, mid, ok = f(mask)
        if not ok:
            continue
        while True:
            s = "".join(left)
            p = s+mid+s[::-1]
            if len(p) > MAX_LEN:
                break
            result.append(int(p))
            if not next_permutation(left, 0, len(left)):
                break
    result.sort()
    return result


MAX_LEN = 16
PALINDROMES = precompute()
class Solution(object):
    def specialPalindrome(self, n):
        """
        :type n: int
        :rtype: int
        """
        return PALINDROMES[bisect.bisect_right(PALINDROMES, n)]
