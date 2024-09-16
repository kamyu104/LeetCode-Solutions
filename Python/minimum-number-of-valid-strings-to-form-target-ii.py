# Time:  O(n + w * l)
# Space: O(n + w * l)

# rolling hash, prefix sum, hash table, greedy
class Solution(object):
    def minValidStrings(self, words, target):
        """
        :type words: List[str]
        :type target: str
        :rtype: int
        """
        MOD, P = 10**9+7, 131
        def hash(l, r):
            return (prefix[r+1]-prefix[l]*power[r-l+1])%MOD            
        
        power = [1]
        prefix = [0]
        for x in target:
            power.append(power[-1]*P%MOD)
            prefix.append((prefix[-1]*P+(ord(x)-ord('a')+1))%MOD)
        lookup = set()
        for w in words:
            h = 0
            for x in w:
                h = (h*P+(ord(x)-ord('a')+1))%MOD
                lookup.add(h)
        result = r = 0
        left = right = -1
        while r != right:
            left, right = right+1, r
            result += 1
            for l in xrange(left, right+1):
                while hash(l, r) in lookup:
                    if r == len(target)-1:
                        return result
                    r += 1
        return -1
