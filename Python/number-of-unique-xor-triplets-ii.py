# Time:  O(nlogn)
# Space: O(n)

# FWHT, fst
class Solution(object):
    def uniqueXorTriplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Template: https://github.com/kth-competitive-programming/kactl/blob/main/content/numerical/FastSubsetTransform.h
        def fst(a, inverse):
            n = len(a)
            step = 1
            while step < n:
                for i in xrange(0, n, step<<1):
                    for j in xrange(i, i+step):
                        u, v = a[j], a[j+step]
                        a[j], a[j+step] = u+v, u-v
                step <<= 1
            if inverse:
                for i in xrange(n):
                    a[i] //= n
        
        a = [0]*(1<<max(nums).bit_length())
        for x in nums:
            a[x] += 1
        fst(a, False)
        for i in xrange(len(a)):
            a[i] = a[i]**3
        fst(a, True)
        return sum(x != 0 for x in a)


# Time:  O(n^2)
# Space: O(n)
# hash table
class Solution2(object):
    def uniqueXorTriplets(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt2, cnt3 = set([0]), set(),  
        max_cnt = 1<<max(nums).bit_length()
        for x in nums:
            for y in cnt2:
                cnt3.add(x^y)
            for y in nums:
                cnt2.add(x^y)
            if len(cnt3) == max_cnt:
                break
        return len(cnt3)
