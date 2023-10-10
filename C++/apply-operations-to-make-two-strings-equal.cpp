// Time:  O(n)
// Space: O(1)

// dp
class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        static const int INF = numeric_limits<int>::max();

        int parity = 0, curr = 0, prev = 0;
        for (int i = 0, j = -1; i < size(s1); ++i) {
            if (s1[i] == s2[i]) {
                continue;
            }
            tie(curr, prev) = pair(min(curr + x, j != -1 ? prev + (i - j) * 2 : INF), curr);
            j = i;
            parity ^= 1;
        }
        return parity == 0 ? curr / 2 : -1;
    }
};
