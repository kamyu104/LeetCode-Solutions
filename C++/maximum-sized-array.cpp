// Time:  precompute: O(max_s^(2/5))
//        runtime:    O(log(max_s))
// Space: O(max_s^(1/5))

// precompute, binary search
int i = 1;
int64_t area = 0;
vector<int64_t> vol = {0};

class Solution {
public:
    int maxSizedArray(long long s) {
        for (; vol.back() <= s; ++i) {
            int line = 0;
            for (int j = 0; j < i; ++j) {
                line += (i - 1) | j;
            }
            area += 2 * line - ((i - 1) | (i - 1));
            vol.emplace_back(((0 + (i - 1)) * i / 2) * area);
        }
        return distance(cbegin(vol), upper_bound(cbegin(vol), cend(vol), s)) - 1;
    }
};
