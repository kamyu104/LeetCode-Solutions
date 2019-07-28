// Time:  O(klogk)
// Space: O(k)

class Solution {
public:
    bool isArmstrong(int N) {
        const auto& n_str = to_string(N);
        return accumulate(n_str.cbegin(), n_str.cend(), 0,
                          [&](const auto& x, const auto& y) {
                              return x + pow(y - '0', n_str.length());
                          }) == N;
    }
};
