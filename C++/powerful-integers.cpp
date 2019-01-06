// Time:  O((logn)^2), n is the bound
// Space: O(r),        r is the size of the result

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> result;
        int log_x = (x != 1) ? int(floor(log(bound) / log(x))) + 1 : 1;
        int log_y = (y != 1) ? int(floor(log(bound) / log(y))) + 1 : 1;
        for (int i = 0, pow_x = 1; i < log_x; ++i, pow_x *= x) {
            for (int j = 0, pow_y = 1; j < log_y; ++j, pow_y *= y) {
                auto val = pow_x + pow_y;
                if (val <= bound) {
                    result.emplace(val);
                }
            }
        }
        return vector<int>(result.cbegin(), result.cend());
    }
};
