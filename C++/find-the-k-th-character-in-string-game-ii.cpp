// Time:  O(logr) = O(1)
// Space: O(1)

// bitmasks
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        const auto& bit_length = [](int64_t x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        int result = 0;
        --k;
        for (int i = 0; i < min(static_cast<int64_t>(size(operations)), bit_length(k)); ++i) {
            if (k & (1ll << i)) {
                result = (result + operations[i]) % 26;
            }
        }
        return 'a' + result;
    }
};
