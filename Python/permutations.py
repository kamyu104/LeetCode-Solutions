# Time:  O(n * n!)
# Space: O(n)

class Solution(object):
    # @param num, a list of integer
    # @return a list of lists of integers
    def permute(self, num):
        result = []
        used = [False] * len(num)
        self.permuteRecu(result, used, [], num)
        return result

    def permuteRecu(self, result, used, cur, num):
        if len(cur) == len(num):
            result.append(cur[:])
            return
        for i in xrange(len(num)):
            if not used[i]:
                used[i] = True
                cur.append(num[i])
                self.permuteRecu(result, used, cur, num)
                cur.pop()
                used[i] = False


# Time:  O(n^2 * n!)
# Space: O(n^2)
class Solution2(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        self.dfs(nums, [], res)
        return res

    def dfs(self, nums, path, res):
        if not nums:
            res.append(path)

        for i in xrange(len(nums)):
            # e.g., [1, 2, 3]: 3! = 6 cases
            # idx -> nums, path
            # 0 -> [2, 3], [1] -> 0: [3], [1, 2] -> [], [1, 2, 3]
            #                  -> 1: [2], [1, 3] -> [], [1, 3, 2]
            #
            # 1 -> [1, 3], [2] -> 0: [3], [2, 1] -> [], [2, 1, 3]
            #                  -> 1: [1], [2, 3] -> [], [2, 3, 1]
            #
            # 2 -> [1, 2], [3] -> 0: [2], [3, 1] -> [], [3, 1, 2]
            #                  -> 1: [1], [3, 2] -> [], [3, 2, 1]
            self.dfs(nums[:i] + nums[i+1:], path + [nums[i]], res)
