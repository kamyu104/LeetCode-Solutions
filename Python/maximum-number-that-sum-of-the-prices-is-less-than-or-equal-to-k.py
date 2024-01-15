# Time:  O(max(logk, x) * log((logk) / x))
# Space: O((logk) / x)

# bit manipulation, binary search, combinatorics
class Solution(object):
    def findMaximumNumber(self, k, x):
        """
        :type k: int
        :type x: int
        :rtype: int
        """
        def floor_log2(x):
            return x.bit_length()-1

        def binary_search_right(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right
    
        def count(l):
            return (prefix_cnt<<(x*l))+lookup[l]

        result = prefix_cnt = 0
        lookup = [0]
        i = 0
        while (lookup[-1]<<x)+(1<<(i+x-1)) <= k:
            lookup.append((lookup[-1]<<x)+(1<<(i+x-1)))
            i += x
        while k >= prefix_cnt:
            # l = result.bit_length()
            # assert(prefix_cnt == sum(c == '1' and (l-i)%x == 0 for i, c in enumerate(bin(result)[2:])))
            l = binary_search_right(1, len(lookup)-1, lambda l: count(l) <= k)
            cnt, i = count(l), x*l
            c = min(floor_log2(k//cnt) if cnt else float("inf"), x-1)
            cnt <<= c
            i += c
            k -= cnt
            result += 1<<i
            prefix_cnt += int((i+1)%x == 0)
        return result-1


# Time:  O(max(logk, x) * (max(logk, x) / x))
# Space: O(1)
# bit manipulation, combinatorics
class Solution2(object):
    def findMaximumNumber(self, k, x):
        """
        :type k: int
        :type x: int
        :rtype: int
        """
        def floor_log2(x):
            return x.bit_length()-1

        result = prefix_cnt = 0
        while k >= prefix_cnt:
            # l = result.bit_length()
            # assert(prefix_cnt == sum(c == '1' and (l-i)%x == 0 for i, c in enumerate(bin(result)[2:])))
            cnt, i = prefix_cnt, 0
            while (cnt<<x)+(1<<(i+x-1)) <= k:
                cnt = (cnt<<x)+(1<<(i+x-1))
                i += x
            c = min(floor_log2(k//cnt) if cnt else float("inf"), x-1)
            cnt <<= c
            i += c
            k -= cnt
            result += 1<<i
            prefix_cnt += int((i+1)%x == 0)
        return result-1


# Time:  O(max(logk, x)^2)
# Space: O(1)
# bit manipulation, combinatorics
class Solution3(object):
    def findMaximumNumber(self, k, x):
        """
        :type k: int
        :type x: int
        :rtype: int
        """
        def floor_log2(x):
            return x.bit_length()-1

        result = prefix_cnt = 0
        while k >= prefix_cnt:
            # l = result.bit_length()
            # assert(prefix_cnt == sum(c == '1' and (l-i)%x == 0 for i, c in enumerate(bin(result)[2:])))
            cnt, i = prefix_cnt, 0
            while (cnt<<1)+(1<<i if (i+1)%x == 0 else 0) <= k:
                cnt = (cnt<<1)+(1<<i if (i+1)%x == 0 else 0)
                i += 1
            k -= cnt
            result += 1<<i
            prefix_cnt += int((i+1)%x == 0)
        return result-1


# Time:  O(max(logk, x) * (max(logk, x) / x))
# Space: O(1)
# bit manipulation, binary search, combinatorics
class Solution4(object):
    def findMaximumNumber(self, k, x):
        """
        :type k: int
        :type x: int
        :rtype: int
        """
        def binary_search_right(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if not check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return right

        def count(v):
            cnt = i = 0
            while 1<<(i+x-1) <= v:
                q, r = divmod(v+1, 1<<((i+x-1)+1))
                cnt += q*1*(1<<(i+x-1))+max(r-1*(1<<(i+x-1)), 0)
                i += x
            return cnt

        return binary_search_right(1, max(k<<2, 1<<x), lambda v: count(v) <= k)  # right bound is verified by checking all possible (k, v) values, or just set right = solution.findMaximumNumber(10**15, 8) <= 10**15
