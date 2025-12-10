// Time:  precompute: O(sqrt(r) * logr + r) = O(sqrt(r) * logr), r = max(nums)
//        runtime:    O(n)
// Space: O(r)

// precompute, bitmasks, two pointers
const auto& precompute = [](int n) {
    const auto& bit_length = [](int x) {
        return (x ? std::__lg(x) : -1) + 1;
    };

    const auto& l = bit_length(n);
    vector<int> palindromes;
    for (int d = 1; d <= l; ++d) {
        const auto& h = (d + 1) / 2;
        for (int prefix = (1 << (h - 1)); prefix < (1 << h); ++prefix) {
            int p = prefix, t = prefix;
            t >>= d % 2;
            for (int i = 0; i < h - d % 2; ++i) {
                p = (p << 1) | (t & 1);
                t >>= 1;
            }
            if (p <= n) {
                palindromes.emplace_back(p);
            }
        }
    }
    vector<int> lookup(n + 1, numeric_limits<int>::max());
    for (int x = 1, i = 0; x <= n; ++x) {
        for (; i < size(palindromes); ++i) {
            if (palindromes[i] > x) {
                break;
            }
        }
        if (i < size(palindromes)) {
            lookup[x] = min(lookup[x], palindromes[i] - x);
        }
        if (i - 1 >= 0) {
            lookup[x] = min(lookup[x], x - palindromes[i - 1]);
        }
    }
    return lookup;
};

const auto& MAX_NUM = 5000;
const auto& LOOKUP = precompute(MAX_NUM);
class Solution {
public:
    vector<int> minOperations(vector<int>& nums) {
        vector<int> result;
        result.reserve(size(nums));
        for (const auto& x : nums) {
            result.emplace_back(LOOKUP[x]);
        }
        return result;
     }
};
