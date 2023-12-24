# Time:  O(h^2 + v^2)
# Space: O(h^2 + v^2)

# hash table
class Solution(object):
    def maximizeSquareArea(self, m, n, hFences, vFences):
        """
        :type m: int
        :type n: int
        :type hFences: List[int]
        :type vFences: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        def diff(arr, x):
            arr.append(1)
            arr.append(x)
            return {abs(arr[i]-arr[j]) for i in xrange(len(arr)) for j in xrange(i+1, len(arr))}

        lookup = diff(hFences, m)
        result = -1
        for x in diff(vFences, n):
            if x in lookup:
                result = max(result, x**2)
        return result%MOD if result != -1 else -1


# Time:  O(h^2 + v^2)
# Space: O(min(h, v)^2)
# hash table
class Solution2(object):
    def maximizeSquareArea(self, m, n, hFences, vFences):
        """
        :type m: int
        :type n: int
        :type hFences: List[int]
        :type vFences: List[int]
        :rtype: int
        """
        MOD = 10**9+7
        def diff(arr, x, check):
            arr.append(1)
            arr.append(x)
            for i in xrange(len(arr)):
                for j in xrange(i+1, len(arr)):
                    if not check:
                        lookup.add(abs(arr[i]-arr[j]))
                        continue
                    if abs(arr[i]-arr[j]) in lookup:
                        result[0] = max(result[0], (arr[i]-arr[j])**2)

        if len(hFences) > len(vFences):
            hFences, vFences = vFences, hFences
            m, n = n, m
        result = [-1]
        lookup = set()
        diff(hFences, m, False)
        diff(vFences, n, True)
        return result[0]%MOD if result[0] != -1 else -1
