# Time:  O((n + q) * logn)
# Space: O(nlogn)

# prefix sum, persistent segment tree, binary search
class PersistentSegmentTree(object):
    LEFT, RIGHT, CNT, TOTAL = range(4)

    def __init__(self, vals):
        self.sorted_unique_vals = sorted(set(vals))
        self.val_to_idx = {x: i for i, x in enumerate(self.sorted_unique_vals)}
        self.n = len(self.val_to_idx)
        self.roots = []
        self.__build(vals)

    def __new_node(self):
        return [None, None, 0, 0]

    def __build(self, vals):
        root = self.__new_node()
        self.roots.append(root)
        for x in vals:
            root = root[:]
            self.roots.append(root)
            curr = root
            left, right = 0, self.n-1
            i = self.val_to_idx[x]
            while left < right:
                curr[self.CNT] += 1
                curr[self.TOTAL] += x
                mid = left+(right-left)//2
                if i <= mid:
                    curr[self.LEFT] = curr = curr[self.LEFT][:] if curr[self.LEFT] else self.__new_node()
                    right = mid
                else:
                    curr[self.RIGHT] = curr = curr[self.RIGHT][:] if curr[self.RIGHT] else self.__new_node()
                    left = mid+1
            curr[self.CNT] += 1
            curr[self.TOTAL] += x

    def query(self, l, r):
        a, b = self.roots[l], self.roots[r+1]
        left_cnt = left_total = 0
        med_cnt = (r-l+1)//2+1
        left, right = 0, self.n-1
        while left < right:
            mid = left+(right-left)//2
            cnt = ((b[self.LEFT][self.CNT] if b and b[self.LEFT] else 0)-
                   (a[self.LEFT][self.CNT] if a and a[self.LEFT] else 0))
            if med_cnt <= cnt:
                a = a[self.LEFT] if a else None
                b = b[self.LEFT] if b else None
                right = mid
            else:
                med_cnt -= cnt
                left_cnt += cnt
                left_total += ((b[self.LEFT][self.TOTAL] if b and b[self.LEFT] else 0)-
                               (a[self.LEFT][self.TOTAL] if a and a[self.LEFT] else 0))
                a = a[self.RIGHT] if a else None
                b = b[self.RIGHT] if b else None
                left = mid+1
        return ((self.sorted_unique_vals[left]*left_cnt-left_total)+((self.roots[r+1][self.TOTAL]-
                self.roots[l][self.TOTAL]-left_total)-self.sorted_unique_vals[left]*((r-l+1)-left_cnt)))


class Solution(object):
    def minOperations(self, nums, k, queries):
        """
        :type nums: List[int]
        :type k: int
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        prefix = [0]*(len(nums)+1)
        for i, x in enumerate(nums):
            prefix[i+1] = prefix[i]+(1 if i-1 >= 0 and nums[i]%k != nums[i-1]%k else 0)
        pst = PersistentSegmentTree([x//k for x in nums])
        return [pst.query(s, t) if prefix[t+1]-prefix[s+1] == 0 else -1 for s, t in queries]
