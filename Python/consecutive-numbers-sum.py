# Time:  O(sqrt(n))
# Space: O(1)

class Solution(object):
    def consecutiveNumbersSum(self, N):
        """
        :type N: int
        :rtype: int
        """
        # x + x+1 + x+2 + ... + x+l-1 = N = 2^k * M, where k >= 0 and M is odd
        # => l*x + (l-1)*l/2 = 2^k * M
        # => x = (2^k * M - (l-1)*l/2) / l = 2^k * M/l - (l-1)/2 is a positive integer
        # => l is either 2^(k+1)*M/f or f (f is factors of M)
        # => the answer is the number of all odd factors of M
        # if prime factorization of N is 2^k * p1^a * p2^b * ...
        # => answer is the number of all odd factors = (a+1) * (b+1) * ...
        result = 1
        while N % 2 == 0:
            N /= 2
        i = 3
        while i*i <= N:
            count = 0
            while N % i == 0:
                N /= i
                count += 1
            result *= count+1
            i += 2
        if N != 1:  # N is the last prime if N != 1
            result *= 1+1
        return result

