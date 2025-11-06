# Time:  O(nlogn)
# Space: O(n)

# rolling hash, binary search
class Solution(object):
    def lexSmallest(self, s):
        """
        :type s: str
        :rtype: str
        """
        MOD = 10**9+7
        B = 29
        def binary_search(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def get_prefix_hash(l, r):
            return (prefix[r+1]-prefix[l]*base[r-l+1])%MOD if l <= r else 0

        def get_suffix_hash(l, r):
            return (suffix[l]-suffix[r+1]*base[r-l+1])%MOD if l <= r else 0
        
        def get_total_hash(k, t, l):
            if not t:
                return get_suffix_hash(k-l, k-1) if l <= k else ((get_suffix_hash(0, k-1))*base[l-k]+get_prefix_hash(k, l-1))%MOD
            nk = len(s)-k
            return get_prefix_hash(0, l-1) if l <= nk else ((get_prefix_hash(0, nk-1))*base[l-nk]+get_suffix_hash(len(s)-(l-nk), len(s)-1))%MOD

        def get_char(k, t, idx):
            if not t:
                return s[(k-1)-idx] if idx < k else s[idx]
            return s[idx] if idx < len(s)-k else s[(len(s)-1)-(idx-(len(s)-k))]

        def is_less(k, i):
            idx = binary_search(0, len(s)-1, lambda x: get_total_hash(k, i, x+1) != get_total_hash(best_k, best_i, x+1))
            return idx != len(s) and get_char(k, i, idx) < get_char(best_k, best_i, idx)

        prefix = [0]*(len(s)+1)
        for i in xrange(len(prefix)-1):
            prefix[i+1] = (prefix[i]*B+ord(s[i]))%MOD
        suffix = [0]*(len(s)+1)
        for i in reversed(xrange(len(suffix)-1)):
            suffix[i] = (suffix[i+1]*B+ord(s[i]))%MOD
        base = [1]*(len(s)+1)
        for i in xrange(len(base)-1):
            base[i+1] = (base[i]*B)%MOD
        best_k, best_i = 1, 0
        mn = min(s)
        for k in xrange(1, len(s)+1):
            if s[k-1] != mn:
                continue
            if is_less(k, 0):
                best_k, best_i = k, 0
        for k in xrange(1, len(s)+1):
            if not s[-k] >= s[-1]:
                continue
            if is_less(k, 1):
                best_k, best_i = k, 1
        return s[:best_k][::-1]+s[best_k:] if not best_i else s[:-best_k]+s[-best_k:][::-1]
