# Time:  O(10^6), the most times of finding x is 665502 (k = 7, n = 30)
# Space: O(1)

class Solution(object):
    def kMirror(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: int
        """
        def get_mirror(n, base, even):
            result = n
            if not even:
                n //= base
            while n:
                result = result*base+n%base
                n //= base
            return result

        def reverse(n, base):
            result = 0
            while n:
                result = result*base+n%base
                n = n//base
            return result

        result = 0
        base1, base2 = k, 10  # (10, k) is slower
        prefix_num, cnt, total = [1]*2, [0]*2, [base1-1]*2
        even = False
        for _ in xrange(n):
            while True:
                x = get_mirror(prefix_num[even], base1, even)
                prefix_num[even] += 1
                cnt[even] += 1
                if cnt[even] == total[even]:
                    cnt[even] = 0
                    total[even] *= base1
                    even = not even
                if x == reverse(x, base2):
                    break
            result += x
        return result


# Time:  O(10^6), the most times of finding x is 665502 (k = 7, n = 30)
# Space: O(1)
class Solution2(object):
    def kMirror(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: int
        """
        def num_gen(k):
            digits = ['0']
            while True:
                for i in xrange(len(digits)//2, len(digits)): 
                    if int(digits[i])+1 < k:
                        digits[i] = digits[-1-i] = str(int(digits[i])+1)
                        break
                    digits[i] = digits[-1-i] = '0'
                else:
                    digits.insert(0, '1')
                    digits[-1] = '1'
                yield "".join(digits)
        
        def mirror_num(gen):
            while True:
                x = int(next(gen, k), k)
                if str(x) == str(x)[::-1]:
                    break
            return x

        gen = num_gen(k)
        return sum(mirror_num(gen) for _ in xrange(n))
