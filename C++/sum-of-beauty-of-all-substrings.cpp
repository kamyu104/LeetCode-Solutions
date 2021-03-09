// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    int beautySum(string s) {
        int result = 0;
        for (int i = 0; i < size(s); ++i) {
            array<int, 26> lookup = {0};
            for (int j = i; j < size(s); ++j) {
                ++lookup[s[j] - 'a'];
                result += *max_element(cbegin(lookup), cend(lookup)) -
                          *min_element(cbegin(lookup), cend(lookup),
                                       [](const auto& a, const auto& b) {
                                           if (a == 0) {
                                               return false;
                                           }
                                           if (b == 0) {
                                               return true;
                                           }
                                           return a < b;
                                       });
            }
        }
        return result;
    }
};
