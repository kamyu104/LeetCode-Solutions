# Time:  O(nlogn)
# Space: O(n)

# coordinate compression, merge sort, mono stack
class Solution(object):
    def shadowPairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def merge_and_count(left, right):
            merged, cnt = [], 0
            stk1, stk2 = [], []
            i = 0
            for idx in right:
                while i < len(left) and left[i] < idx:
                    while stk1 and stk1[-1] < nums[left[i]]:
                        stk1.pop()
                    if stk2:
                        stk2[-1][1] = min(stk2[-1][1], len(stk1))
                    stk1.append(nums[left[i]])
                    merged.append(left[i])
                    i += 1
                while stk2 and stk2[-1][0] >= nums[idx]:
                    base = stk2.pop()[1]
                    if stk2:
                        stk2[-1][1] = min(stk2[-1][1], base)
                cnt += len(stk1)-(stk2[-1][1] if stk2 else 0)
                stk2.append([nums[idx], len(stk1)])
                merged.append(idx)
            merged.extend(left[i] for i in xrange(i, len(left)))
            return merged, cnt

        val_to_idx = {x:i for i, x in enumerate(sorted(set(nums)))}
        groups = [[] for _ in xrange(len(val_to_idx))]
        for i, x in enumerate(nums):
            groups[val_to_idx[x]].append(i)
        result = 0
        while len(groups) != 1:
            new_groups = []
            for i in xrange(0, len(groups)-1, 2):
                merged, cnt = merge_and_count(groups[i], groups[i+1])
                result += cnt
                new_groups.append(merged)
            if len(groups)%2:
                new_groups.append(groups[-1])
            groups = new_groups
        return result
