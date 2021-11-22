# Time:  O(10^6), the most times of finding x is 665502 (k = 7, n = 30)
# Space: O(1)

class Solution(object):
    def kMirror(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: int
        """
        def mirror(n, base, odd):
            result = n
            if odd:
                n //= base
            while n:
                result = result*base+n%base
                n //= base
            return result

        def num_gen(base):
            prefix_num, total = [1]*2, [base]*2
            odd = 1
            while True:
                x = mirror(prefix_num[odd], base, odd)
                prefix_num[odd] += 1
                if prefix_num[odd] == total[odd]:
                    total[odd] *= base
                    odd ^= 1
                yield x

        def reverse(n, base):
            result = 0
            while n:
                result = result*base+n%base
                n = n//base
            return result

        def mirror_num(gen, base):
            while True:
                x = next(gen)
                if x == reverse(x, base):
                    break
            return x

        base1, base2 = k, 10  # (10, k) is slower
        gen = num_gen(base1)
        return sum(mirror_num(gen, base2) for _ in xrange(n))


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
