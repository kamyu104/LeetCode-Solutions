// Time:  precompute: O(max_s^(1/5) * log(max_s))
//        runtime:    O(log(max_s))
// Space: O(max_s^(1/5))

// precompute, bitmasks, combinatorics, binary search
int i = 1;
int64_t area = 0;
vector<int64_t> vol = {0};
class Solution {
public:
    int maxSizedArray(long long s) {
        const auto& bit_length = [](int x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        for (; vol.back() <= s; ++i) {
            const int l = bit_length(i - 1);
            int line = (i - 1) * i;
            for (int bit = 0; bit < l; ++bit) {
                if (!((i - 1) & (1 << bit))) {
                    line += (((i - 1) >> (bit + 1)) * (1 << bit)) * (1 << bit);
                }
            }
            area += 2 * line - ((i - 1) | (i - 1));
            vol.emplace_back(((0 + (i - 1)) * i / 2) * area);
        }
        return distance(cbegin(vol), upper_bound(cbegin(vol), cend(vol), s)) - 1;
    }
};
