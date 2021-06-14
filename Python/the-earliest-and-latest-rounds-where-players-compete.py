# Time:  O(n^2) states * O(n^2) per states = O(n^4)
# Space: O(n^2 + (n/2)^2 + (n/4)^2 + ... ) = O(n^2)

class Solution(object):
    def earliestAndLatest(self, n, firstPlayer, secondPlayer):
        """
        :type n: int
        :type firstPlayer: int
        :type secondPlayer: int
        :rtype: List[int]
        """
        def memoization(t, l, r, lookup):
            # t: total number of players,
            # l: number of players left to first player,
            # r: number of players right to second player
            if (t, l, r) not in lookup:
                if l == r:
                    return (1, 1)
                if l > r:  # memoization(t, l, r, lookup) is the same as memoization(t, r, l, lookup), just compute one of them
                    l, r, = r, l
                result = [float("inf"), 0]
                for i in xrange(l+1):
                    l_lose_cnt, nt = l-i, (t+1)//2
                    min_j = max(l_lose_cnt, r-((t-nt)-l_lose_cnt))  # j >= l_lose_cnt and j >= r-((t-nt)-l_lose_cnt)
                    max_j = min(r-(i+1), (nt-(i+1))-1)  # j <= r-(i+1) and j <= (nt-(i+1))-1
                    for j in xrange(min_j, max_j+1):
                        assert(l_lose_cnt <= j <= r-(i+1) and
                               r-((t-nt)-l_lose_cnt) <= j <= (nt-(i+1))-1)
                        tmp = memoization(nt, i, j, lookup)
                        result = min(result[0], tmp[0]+1), max(result[1], tmp[1]+1)
                lookup[t, l, r] = result
            return lookup[t, l, r]
        
        return memoization(n, firstPlayer-1, n-secondPlayer, {})
