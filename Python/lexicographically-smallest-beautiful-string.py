# Time:  O(n)
# Space: O(n)

# greedy
class Solution(object):
    def smallestBeautifulString(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        def check(i):
            return (i-1 < 0 or arr[i-1] != arr[i]) and (i-2 < 0 or arr[i-2] != arr[i])

        arr = map(lambda x: ord(x)-ord('a'), s)
        for i in reversed(xrange(len(arr))):
            arr[i] += 1
            while not check(i):
                arr[i] += 1
            if arr[i] < k:
                break
        else:
            return ""
        for j in xrange(i+1, len(arr)):
            arr[j] = 0
            while not check(j):
                arr[j] += 1
        return "".join(map(lambda x: chr(ord('a')+x), arr))
