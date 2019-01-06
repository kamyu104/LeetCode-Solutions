# Time:  O(1)
# Space: O(1)

from fractions import Fraction


class Solution(object):
    def isRationalEqual(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        def frac(S):
            if '.' not in S:
                return Fraction(int(S), 1)

            i = S.index('.')
            result = Fraction(int(S[:i]), 1)
            non_int_part = S[i+1:]
            if '(' not in non_int_part:
                if non_int_part:
                    result += Fraction(int(non_int_part), 10**len(non_int_part))
                return result

            i = non_int_part.index('(')
            if i:
                result += Fraction(int(non_int_part[:i]), 10**i)
            repeat_part = non_int_part[i+1:-1]
            result += Fraction(int(repeat_part), 10**i * (10**len(repeat_part)-1))
            return result

        return frac(S) == frac(T)
