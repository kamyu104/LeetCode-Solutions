# Time:  O(n)
# Space: O(n)

# mono stack, prefix sum
class Solution(object):
    def totalStrength(self, strength):
        """
        :type strength: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        prefix, prefix2 = [0]*(len(strength)+1), [0]*(len(strength)+1)
        for i in xrange(len(strength)):
            prefix[i+1] = (prefix[i]+strength[i])%MOD
            prefix2[i+1] = (prefix2[i]+strength[i]*(i+1))%MOD
        suffix, suffix2 = [0]*(len(strength)+1), [0]*(len(strength)+1)
        for i in reversed(xrange(len(strength))):
            suffix[i] = (suffix[i+1]+strength[i])%MOD
            suffix2[i] = (suffix2[i+1]+strength[i]*(len(strength)-i))%MOD
        stk, result = [-1], 0
        for i in xrange(len(strength)+1):
            while stk[-1] != -1 and (i == len(strength) or strength[stk[-1]] >= strength[i]):
                # strength[j] >= strength[y] for j in [x, y]
                # strength[j] < strength[y] for j in [y+1, z]
                x, y, z = stk[-2]+1, stk.pop(), i-1
                result = (result+(strength[y]*((z-y+1)*((prefix2[y+1]-prefix2[x])-x*(prefix[y+1]-prefix[x]))+
                                               (y-x+1)*((suffix2[y+1]-suffix2[z+1])-(len(strength)-(z+1))*(suffix[y+1]-suffix[z+1])))))%MOD
            stk.append(i)
        return result
