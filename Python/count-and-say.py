from __future__ import print_function
# Time:  O(n * 2^n)
# Space: O(2^n)

class Solution:
    # @return a string
    def countAndSay(self, n):
        seq = "1"
        for i in xrange(n - 1):
            seq = self.getNext(seq)
        return seq

    def getNext(self, seq):
        i, next_seq = 0, ""
        while i < len(seq):
            cnt = 1
            while i < len(seq) - 1 and seq[i] == seq[i + 1]:
                cnt += 1
                i += 1
            next_seq += str(cnt) + seq[i]
            i += 1
        return next_seq

if __name__ == "__main__":
    for i in xrange(1, 4):
        print(Solution().countAndSay(i))

