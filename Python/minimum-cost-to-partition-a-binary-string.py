# Time:  O(n)
# Space: O(n)

# prefix sum, divide and conquer
class Solution(object):
    def minCost(self, s, encCost, flatCost):
        """
        :type s: str
        :type encCost: int
        :type flatCost: int
        :rtype: int
        """
        def divide_and_conquer(left, right):
            l = right-left+1
            x = prefix[right+1]-prefix[left]
            result = l*x*encCost if x else flatCost
            if x and l%2 == 0:
                result = min(result, divide_and_conquer(left, (left+l//2)-1)+divide_and_conquer(left+l//2, right))
            return result
    
        prefix = [0]*(len(s)+1)
        for i in xrange(len(s)):
            prefix[i+1] = prefix[i]+(1 if s[i] == '1' else 0)
        return divide_and_conquer(0, len(s)-1)


# Time:  O(n)
# Space: O(n)
# queue
class Solution2(object):
    def minCost(self, s, encCost, flatCost):
        """
        :type s: str
        :type encCost: int
        :type flatCost: int
        :rtype: int
        """
        l = len(s)
        while l%2 == 0:
            l //= 2
        result = 0
        q = []
        for left in xrange(0, len(s), l):
            x = sum(s[i] == '1' for i in xrange(left, left+l))
            q.append((l*x*encCost if x else flatCost, x))
        while len(q) != 1:
            new_q = []
            l *= 2
            for i in xrange(0, len(q), 2):
                v = q[i][0]+q[i+1][0]
                x = q[i][1]+q[i+1][1]
                new_q.append((min(l*x*encCost if x else flatCost, v), x))
            q = new_q
        return q[0][0]
