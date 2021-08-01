# Time:  O(1)
# Space: O(1)

import math


class Solution(object):
    def minimumPerimeter(self, neededApples):
        """
        :type neededApples: int
        :rtype: int
        """
        # find min r, s.t. 4r^3+6r^2+2r-neededApples >= 0
        # => by depressed cubic (https://en.wikipedia.org/wiki/Cubic_equation#Depressed_cubic)
        #    let x = r+(6/(3*4)), r = x-(1/2)
        #    4(x-(1/2))^3+6(x-(1/2))^2+2(x-(1/2))-neededApples
        #    = 4(x^3-3/2x^2+3/4x-1/8)
        #      + 6(x^2-x+1/4)
        #      + 2(x-1/2)
        #    = 4x^3-x-neededApples >= 0
        #
        # find x, s.t. 4x^3-x-neededApples = 0 <=> x^3+(-1/4)x+(-neededApples/4) = 0
        # => by Cardano's formula (https://en.wikipedia.org/wiki/Cubic_equation#Cardano's_formula)
        #    x^3 + px + q = 0, p = (-1/4), q = (-neededApples/4)
        #    since (q/2)^2+(p/3)^3 = neededApples^2/64-1/1728 > 0 => only one real root
        #    => x = (-q/2 + ((q/2)^2+(p/3)^3)^(1/2)) + (-q/2 - ((q/2)^2+(p/3)^3)^(1/2))
        #       r = x-(1/2)
        # => min r = ceil(r)

        a, b, c, d = 4.0, 6.0, 2.0, float(-neededApples)
        p = (3*a*c-b**2)/(3*a**2)  # -1/4.0
        q = (2*b**3-9*a*b*c+27*a**2*d)/(27*a**3)  # -neededApples/4.0
        assert((q/2)**2+(p/3)**3 > 0)  # case of only one real root
        x = (-q/2 + ((q/2)**2+(p/3)**3)**0.5)**(1.0/3) + \
            (-q/2 - ((q/2)**2+(p/3)**3)**0.5)**(1.0/3)
        return 8*int(math.ceil(x - b/(3*a)))
                             

# Time:  O(1)
# Space: O(1)
class Solution2(object):
    def minimumPerimeter(self, neededApples):
        """
        :type neededApples: int
        :rtype: int
        """
        # r+r    , (r-1)+r, ..., 1+r, 0+r    , 1+r, ..., (r-1)+r, r+r
        # r+(r-1),                    0+(r-1),                    r+(r-1)
        #  .                           .                           .    
        #  .                           .                           .    
        #  .                           .                           .    
        # r+1    , (r-1)+1, ..., 1+1, 1+0    , 1+1, ..., (r-1)+1, r+1
        # r+0    , (r-1)+0, ..., 1+0, 0+0    , 1+0, ..., (r-1)+0, r+0
        # r+1    , (r-1)+1, ..., 1+1, 1+0    , 1+1, ..., (r-1)+1, r+1
        #  .                           .                           .    
        #  .                           .                           .    
        #  .                           .                           .       
        # r+(r-1),                    0+(r-1),                    r+(r-1)
        # r+r    , (r-1)+r, ..., 1+r, 0+r    , 1+r, ..., r+(r-1), r+r
        #
        # each up/down direction forms an arithmetic sequence, there are 2r+1 columns
        # => 2*(1+r)*r/2 * (2r+1)
        #
        # each left/right direction forms an arithmetic sequence, there are 2r+1 rows
        # => 2*(1+r)*r/2 * (2r+1)
        #
        # => total = 2 * 2*(1+r)*r/2 * (2r+1) = r*(2r+1)*(2r+2) = 4r^3+6r^2+2r
        # => find min r, s.t. (2r)(2r+1)*(2r+2) >= 2*neededApples
        # => find min x = 2r+2, s.t. (x-2)(x-1)(x) >= 2*neededApples

        x = int((2*neededApples)**(1.0/3))
        x -= x%2
        assert((x-2)*(x-1)*x < 2*neededApples < (x+2)**3)
        x += 2
        if (x-2)*(x-1)*x < 2*neededApples:
            x += 2
        return 8*(x-2)//2


# Time:  O(logn)
# Space: O(1)
class Solution3(object):
    def minimumPerimeter(self, neededApples):
        """
        :type neededApples: int
        :rtype: int
        """
        # 2r  , 2r-1, ..., r+1, r  , r+1, ..., 2*r-1, 2*r
        # 2r-1,                 r-1,                  2r-1
        # .                     .                     .    
        # .                     .                     .    
        # .                     .                     .    
        # r+1 ,    r, ...,   2, 1  ,   2, ...,   r  , r+1
        # r   ,  r-1, ...,   1, 0  ,   1, ...,   r-1, r
        # r+1 ,    r, ...,   2, 1  ,   2, ...,   r  , r+1
        # .                     .                     .    
        # .                     .                     .    
        # .                     .                     .    
        # 2r-1,                 r-1,                  2r-1
        # 2r  , 2r-1, ..., r+1, r  , r+1, ..., 2*r-1, 2*r
        #
        # the sum of each row/col forms an arithmetic sequence
        # => let ai = (((r + (r-1) + ... + r + 0) + (0 + 1 + 2 + ... + r)) - 0) + i*(2r+1)
        #           = (2*(0+r)*(r+1)/2-0) + i*(2r+1)
        #           = r*(r+1) + i*(2r+1)
        # => total  = 2*(a0 + a1 + ... ar) - a0
        #           = 2*(r*(r+1) + r*(r+1) + r*(2r+1)))*(r+1)/2 - r*(r+1)
        #           = r*(4r+3)*(r+1)-r*(r+1)
        #           = 4r^3+6r^2+2r
        # => find min r, s.t. 4r^3+6r^2+2r >= neededApples

        def check(neededApples, x):
            return r*(2*r+1)*(2*r+2) >= neededApples

        left, right = 1, int((neededApples/4.0)**(1.0/3))
        while left <= right:
            mid = left + (right-left)//2
            if check(neededApples, mid):
                right = mid-1
            else:
                left = mid+1
        return 8*left
