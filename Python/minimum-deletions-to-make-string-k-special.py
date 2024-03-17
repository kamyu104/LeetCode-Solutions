# Time:  O(n + 26)
# Space: O(n + 26)

# freq table, counting sort, two pointers
class Solution(object):
    def minimumDeletions(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        def counting_sort(arr, key=lambda x:x, reverse=False):  # Time: O(n), Space: O(n)
            count = [0]*(max(arr, key=key)+1)
            for x in arr:
                count[key(x)] += 1
            for i in xrange(1, len(count)):
                count[i] += count[i-1]
            result = [0]*len(arr)
            if not reverse:
                for x in reversed(arr):  # stable sort
                    count[key(x)] -= 1
                    result[count[key(x)]] = x
            else:
                for x in arr:  # stable sort
                    count[key(x)] -= 1
                    result[count[key(x)]] = x
                result.reverse()
            return result
    
        cnt = [0]*26
        for x in word:
            cnt[ord(x)-ord('a')] += 1
        arr = counting_sort([x for x in cnt if x])
        result = float("inf")
        right = prefix = 0
        suffix = len(word)
        prev = -1
        for left in xrange(len(arr)):
            if left+1 < len(arr) and arr[left+1] == arr[left]:
                continue
            while right < len(arr) and arr[right] <= arr[left]+k:
                suffix -= arr[right]
                right += 1
            result = min(result, prefix+(suffix-(arr[left]+k)*(len(arr)-right)))
            prefix += arr[left]*(left-prev)
            prev = left
        return result


# Time:  O(n + 26 * log(26))
# Space: O(26)
# freq table, sort, two pointers
class Solution2(object):
    def minimumDeletions(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        cnt = [0]*26
        for x in word:
            cnt[ord(x)-ord('a')] += 1
        arr = sorted(x for x in cnt if x)
        result = float("inf")
        right = prefix = 0
        suffix = len(word)
        prev = -1
        for left in xrange(len(arr)):
            if left+1 < len(arr) and arr[left+1] == arr[left]:
                continue
            while right < len(arr) and arr[right] <= arr[left]+k:
                suffix -= arr[right]
                right += 1
            result = min(result, prefix+(suffix-(arr[left]+k)*(len(arr)-right)))
            prefix += arr[left]*(left-prev)
            prev = left
        return result


# Time:  O(n + 26^2)
# Space: O(26)
# freq table
class Solution3(object):
    def minimumDeletions(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        cnt = [0]*26
        for x in word:
            cnt[ord(x)-ord('a')] += 1
        return min(sum(y if y < x else max(y-(x+k), 0) for y in cnt if y) for x in cnt if x)
