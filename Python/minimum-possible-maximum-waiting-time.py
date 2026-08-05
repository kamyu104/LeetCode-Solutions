# Time:  O(n * rlogr * (f / 64)) = O(n * rlogr), r = max(demand), f = fuel[0]
# Space: O(r * (f / 64)) = O(r)

# binary search, dp, bitmasks
class Solution(object):
    def minMaxWaitingTime(self, demand, fuel):
        """
        :type demand: List[int]
        :type fuel: List[int]
        :rtype: int
        """
        FULLMASK = ((1<<64)-1)
        def binary_search(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def low(x):
            return FULLMASK if x >= 63 else ((1<<(x+1))-1) if x >= 0 else 0

        def high(x):
            return FULLMASK^low(x-1)

        def find_max_served():
            mask = 1
            total = 0
            for i, x in enumerate(demand):
                mask = ((mask<<x)&low(fuel[0]))|(mask&high(total+x-fuel[1]))
                if not mask:
                    return i
                total += x
            return len(demand)

        def check(w):
            def update(last, gap, mask):
                if last == 0:
                    mask = (mask<<demand[i])&low(fuel[0])
                else:
                    mask &= high(total+demand[i]-fuel[1])
                new_dp[last][gap] |= mask

            # dp[last][gap] = bit used0 is set if the state (last, gap, used0) is reachable.
            # - last: which dispenser serving the previous car
            # - gap: remaining busy time of the other dispenser
            # - used0: total fuel consumed by dispenser 0
            dp = [[0]*(mx+1) for _ in xrange(2)]
            dp[0][0] = 1
            total = 0
            for i in xrange(l):
                new_dp = [[0]*(mx+1) for _ in xrange(2)]
                for last in xrange(len(dp)):
                    for gap in xrange(len(dp[0])):
                        if not dp[last][gap]:
                            continue
                        if (demand[i-1] if i-1 >= 0 else 0) <= w:
                            update(last, max(gap-(demand[i-1] if i-1 >= 0 else 0), 0), dp[last][gap])
                        if gap <= w:
                            update(last^1, max((demand[i-1] if i-1 >= 0 else 0)-gap, 0), dp[last][gap])
                dp = new_dp
                total += demand[i]
            return any(x for row in dp for x in row)

        l = find_max_served()
        mx = max(demand)
        return binary_search(0, mx, check) if l else -1


# Time:  O(n * rlogr * f),  r = max(demand), f = fuel[0]
# Space: O(r * f)
# binary search, dp
class Solution2(object):
    def minMaxWaitingTime(self, demand, fuel):
        """
        :type demand: List[int]
        :type fuel: List[int]
        :rtype: int
        """
        def binary_search(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def find_max_served():
            dp = [False]*(fuel[0]+1)  # dp[used0] = whether the current prefix can be served with state (used0).
            dp[0] = True
            total = 0
            for i, x in enumerate(demand):
                new_dp = [False]*(fuel[0]+1)
                for used0 in xrange(len(dp)):
                    if not dp[used0]:
                        continue
                    if used0+x <= fuel[0]:
                        new_dp[used0+x] = True
                    if (total-used0)+x <= fuel[1]:
                        new_dp[used0] = True
                if not any(new_dp):
                    return i
                dp = new_dp
                total += x
            return len(demand)

        def check(w):
            def update(last, gap, used0):
                if last == 0:
                    if used0+demand[i] <= fuel[0]:
                        new_dp[last][gap][used0+demand[i]] = True
                else:
                    if (total-used0)+demand[i] <= fuel[1]:
                        new_dp[last][gap][used0] = True

            # dp[last][gap][used0] = whether the current prefix can be served with state (last, gap, used0).
            # - last: which dispenser serving the previous car
            # - gap: remaining busy time of the other dispenser
            # - used0: total fuel consumed by dispenser 0
            dp = [[[False]*(fuel[0]+1) for _ in xrange(mx+1)] for _ in xrange(2)]
            dp[0][0][0] = True
            total = 0
            for i in xrange(l):
                new_dp = [[[False]*(fuel[0]+1) for _ in xrange(mx+1)] for _ in xrange(2)]
                for last in xrange(len(dp)):
                    for gap in xrange(len(dp[0])):
                        for used0 in xrange(len(dp[0][0])):
                            if not dp[last][gap][used0]:
                                continue
                            if (demand[i-1] if i-1 >= 0 else 0) <= w:
                                update(last, max(gap-(demand[i-1] if i-1 >= 0 else 0), 0), used0)
                            if gap <= w:
                                update(last^1, max((demand[i-1] if i-1 >= 0 else 0)-gap, 0), used0)
                dp = new_dp
                total += demand[i]
            return any(x for matrix in dp for row in matrix for x in row)

        l = find_max_served()
        mx = max(demand)
        return binary_search(0, mx, check) if l else -1
