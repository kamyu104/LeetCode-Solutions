# Time:  O(n^2)
# Space: O(t), t is the size of trie

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
        base = P
        for l in xrange(1, len(nums)+1):
            lookup = collections.defaultdict(list)
            cnt = h = 0
            for i in xrange(len(nums)):
                cnt += (nums[i]%p == 0)
                h = (h*P+nums[i])%MOD
                if i-l >= 0:
                    cnt -= (nums[i-l]%p == 0)
                    h = (h-nums[i-l]*base)%MOD
                if i < l-1 or cnt > k or not check(nums, lookup[h], l, i-l+1):
                    continue
                lookup[h].append(i-l+1)
                result += 1
            base = (base*P)%MOD
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
        base = P
        for l in xrange(1, len(nums)+1):
            lookup = set()
            cnt = h = 0
            for i in xrange(len(nums)):
                cnt += (nums[i]%p == 0)
                h = (h*P+nums[i])%MOD
                if i-l >= 0:
                    cnt -= (nums[i-l]%p == 0)
                    h = (h-nums[i-l]*base)%MOD
                if i < l-1 or cnt > k:
                    continue
                lookup.add(h)  # assumed no collision
            result += len(lookup)
            base = (base*P)%MOD
        return result
