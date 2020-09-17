# Time:  O(logn)
# Space: O(1)

class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        pivot, result = 1, 0
        while n >= pivot:
            result += (n//(10*pivot))*pivot + \
                      min(pivot, max(n%(10*pivot) - pivot + 1, 0))
            pivot *= 10
        return result


# Time:  O(logn)
# Space: O(1)
class Solution2(object):
    # @param {integer} n
    # @return {integer}
    def countDigitOne(self, n):
        k = 1
        cnt, multiplier, left_part = 0, 1, n

        while left_part > 0:
            # split number into: left_part, curr, right_part
            curr = left_part % 10
            right_part = n % multiplier

            # count of (c000 ~ oooc000) = (ooo + (k < curr)? 1 : 0) * 1000
            cnt += (left_part / 10 + (k < curr)) * multiplier

            # if k == 0, oooc000 = (ooo - 1) * 1000
            if k == 0 and multiplier > 1:
                cnt -= multiplier

            # count of (oook000 ~ oookxxx): count += xxx + 1
            if curr == k:
                cnt += right_part + 1

            left_part /= 10
            multiplier *= 10

        return cnt

