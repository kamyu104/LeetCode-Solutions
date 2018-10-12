# Time:  O(logn)
# Space: O(logn)

class Solution(object):
    def findKthNumber(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        result = 0

        cnts = [0] * 10
        for i in xrange(1, 10):
            cnts[i] = cnts[i - 1] * 10 + 1

        nums = []
        i = n
        while i:
            nums.append(i % 10)
            i /= 10

        total, target = n, 0
        i = len(nums) - 1
        while i >= 0 and k > 0:
            target = target*10 + nums[i]
            start = int(i == len(nums)-1)
            for j in xrange(start, 10):
                candidate = result*10 + j
                if candidate < target:
                    num = cnts[i+1]
                elif candidate > target:
                    num = cnts[i]
                else:
                    num = total - cnts[i + 1]*(j-start) - cnts[i]*(9-j)
                if k > num:
                    k -= num
                else:
                    result = candidate
                    k -= 1
                    total = num-1
                    break
            i -= 1

        return result


# Time:  O(logn * logn)
# Space: O(logn)
class Solution2(object):
    def findKthNumber(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        def count(n, prefix):
            result, number = 0, 1
            while prefix <= n:
                result += number
                prefix *= 10
                number *= 10
            result -= max(number/10 - (n - prefix/10 + 1), 0)
            return result

        def findKthNumberHelper(n, k, cur, index):
            if cur:
                index += 1
                if index == k:
                    return (cur, index)

            i = int(cur == 0)
            while i <= 9:
                cur = cur * 10 + i
                cnt = count(n, cur)
                if k > cnt + index:
                    index += cnt
                elif cur <= n:
                    result = findKthNumberHelper(n, k, cur, index)
                    if result[0]:
                        return result
                i += 1
                cur /= 10
            return (0, index)

        return findKthNumberHelper(n, k, 0, 0)[0]

