// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int checkRecord(int n) {
        static const long long M = 1000000007;
        long long a0l0 = 1, a0l1 = 0, a0l2 = 0, a1l0 = 0, a1l1 = 0, a1l2 = 0;
        for (int i = 0; i <= n; ++i) {
            auto new_a0l0 = (a0l0 + a0l1 + a0l2) % M;
            a0l2 = a0l1;
            a0l1 = a0l0;
            a0l0 = new_a0l0;
            auto new_a1l0 = (a0l0 + a1l0 + a1l1 + a1l2) % M;
            a1l2 = a1l1;
            a1l1 = a1l0;
            a1l0 = new_a1l0;
        }
        return static_cast<int>(a1l0);
    }
};
