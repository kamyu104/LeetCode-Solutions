# Time:  O(n)
# Space: O(1)

# two pointers, sliding window, freq table
class Solution(object):
    def countOfSubstrings(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        VOWELS = set("aeiou")
        def update(i, d):
            if word[i] not in VOWELS:
                curr2[0] += d
                return
            x = ord(word[i])-ord('a')
            if cnt1[x] == 0:
                curr1[0] += 1
            cnt1[x] += d
            if cnt1[x] == 0:
                curr1[0] -= 1

        result = 0
        cnt1, cnt2 = [0]*26, [0]*26
        curr1, curr2 = [0], [0]
        mid = left = 0
        for right in xrange(len(word)):
            update(right, +1)
            while curr2[0] > k:
                update(left, -1)
                if left < mid:
                    assert(word[left] in VOWELS)
                    cnt2[ord(word[left])-ord('a')] -= 1
                left += 1
                mid = max(mid, left)
            if not (curr1[0] == len(VOWELS) and curr2[0] == k):
                continue
            while word[mid] in VOWELS and cnt1[ord(word[mid])-ord('a')]-(cnt2[ord(word[mid])-ord('a')]+1) >= 1:
                cnt2[ord(word[mid])-ord('a')] += 1
                mid += 1
            result += mid-left+1
        return result


# Time:  O(n)
# Space: O(1)
# two pointers, sliding window, freq table
class Solution2(object):
    def countOfSubstrings(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        VOWELS = set("aeiou")
        def count(k):
            def update(i, d):
                if word[i] not in VOWELS:
                    curr2[0] += d
                    return
                x = ord(word[i])-ord('a')
                if cnt[x] == 0:
                    curr1[0] += 1
                cnt[x] += d
                if cnt[x] == 0:
                    curr1[0] -= 1

            result = 0
            cnt = [0]*26
            curr1, curr2 = [0], [0]
            left = 0
            for right in xrange(len(word)):
                update(right, +1)
                while curr1[0] == len(VOWELS) and curr2[0] >= k:
                    result += len(word)-right
                    update(left, -1)
                    left += 1
            return result

        return count(k)-count(k+1)
