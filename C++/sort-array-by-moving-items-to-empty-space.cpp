// Time:  O(n)
// Space: O(n)

// greedy
class Solution {
public:
    int sortArray(vector<int>& nums) {
        const auto& min_moves = [&](int d) {
            const auto& index = [&](int x) {
                return (x == 0) ? d * (size(nums) - 1) : x - d;
            };
            vector<int> a(nums);
            int result = 0;
            for (int i = 0; i < size(a); ++i) {
                int l = 1;
                bool has_zero = (a[i] == 0);
                for (; index(a[i]) != i; has_zero |= (a[i] == 0), ++l) {
                    swap(a[i], a[index(a[i])]);
                }
                if (l >= 2) {
                    result += has_zero ? l - 1 : l + 1;
                }
            }
            return result;
        };

        return min(min_moves(0), min_moves(1));
    }
};
