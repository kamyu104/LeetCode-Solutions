// Time:  O(2^n)
// Space: O(2^n)

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> curr(10);
        iota(curr.begin(), curr.end(), 0);
        for (int i = 0; i < N - 1; ++i) {
            vector<int> next;
            for (const auto& x : curr) {
                int y = x % 10;
                if (x > 0 && y + K < 10) {
                    next.emplace_back(x * 10 + y + K);
                }
                if (x > 0 && K > 0 && y - K >= 0) {
                    next.emplace_back(x * 10 + y - K);
                }
            }
            curr = move(next);
        }
        return curr;
    }
};
