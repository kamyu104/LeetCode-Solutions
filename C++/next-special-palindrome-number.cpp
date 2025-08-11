// Time:  precompute: O(9 * 2^9 + 16 * p + plogp), p = len(PALINDROMES)
//        runtime:    O(logp)
// Space: O(p)

// precompute, bitmasks, binary search
const int MAX_LEN = 16;

const auto& precompute = []() {
    const auto& f = [](int mask) {
        string result, mid;
        for (int i = 0; i < 9; ++i) {
            if ((mask & (1 << i)) == 0) {
                continue;
            }
            if ((i + 1) % 2) {
                if (!empty(mid)) {
                    return tuple(result, mid, false);
                }
                mid = to_string(i + 1);
            }
            for (int _ = 0; _ < (i + 1) / 2; ++_) {
                result.push_back('0' + (i + 1));
            }
        }
        return tuple(result, mid, true);
    };

    vector<int64_t> result;
    for (int mask = 1; mask < (1 << 9); ++mask) {
        auto [left, mid, ok] = f(mask);
        if (!ok) {
            continue;
        }
        do {
            string right = left;
            reverse(begin(right), end(right));
            string p = left;
            p += mid;
            p += right;
            if (size(p) > MAX_LEN) {
                break;
            }
            result.emplace_back(stoll(p));
        } while (next_permutation(begin(left), end(left)));
    }
    sort(begin(result), end(result));
    return result;
};

const auto& PALINDROMES = precompute();
class Solution {
public:
    long long specialPalindrome(long long n) {
        return *upper_bound(begin(PALINDROMES), end(PALINDROMES), n);
    }
};
