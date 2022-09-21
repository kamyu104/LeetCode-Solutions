# Time:  O(n^2)
# Space: O(t), t is the size of trie

import collections


# trie
class Solution(object):
    def countDistinct(self, nums, k, p):
        """
        :type nums: List[int]
        :type k: int
        :type p: int
        :rtype: int
        """
        _trie = lambda: collections.defaultdict(_trie)
        trie = _trie()
        result = 0
        for i in xrange(len(nums)):
            cnt = 0
            curr = trie
            for j in xrange(i, len(nums)):
                cnt += (nums[j]%p == 0)
                if cnt > k:
                    break
                if nums[j] not in curr:
                    result += 1
                curr = curr[nums[j]]
        return result


# Time:  O(n^2) on average, worst is O(n^3)
# Space: O(n)
import collections


# rolling hash
class Solution2(object):
    def countDistinct(self, nums, k, p):
        """
        :type nums: List[int]
        :type k: int
        :type p: int
        :rtype: int
        """
        MOD, P = 10**9+7, 113
        def check(nums, lookup, l, i):
            return all(any(nums[i+k] != nums[j+k] for k in xrange(l)) for j in lookup)

        result = 0
        cnt, h = [0]*len(nums), [0]*len(nums)
        for l in xrange(1, len(nums)+1):
            lookup = collections.defaultdict(list)
            for i in xrange(len(nums)-l+1):
                cnt[i] += (nums[i+l-1]%p == 0)
                if cnt[i] > k:
                    continue
                h[i] = (h[i]*P+nums[i+l-1])%MOD
                if not check(nums, lookup[h[i]], l, i):
                    continue
                lookup[h[i]].append(i)
                result += 1
        return result


# Time:  O(n^2)
# Space: O(n)
# rolling hash
class Solution3(object):
    def countDistinct(self, nums, k, p):
        """
        :type nums: List[int]
        :type k: int
        :type p: int
        :rtype: int
        """
        MOD, P = 10**9+7, 200
        result = 0
        cnt, h = [0]*len(nums), [0]*len(nums)
        for l in xrange(1, len(nums)+1):
            lookup = set()
            for i in xrange(len(nums)-l+1):
                cnt[i] += (nums[i+l-1]%p == 0)
                if cnt[i] > k:
                    continue
                h[i] = (h[i]*P+nums[i+l-1])%MOD
                lookup.add(h[i])
            result += len(lookup)
        return result
