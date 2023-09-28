// Time:  O(n + m)
// Space: O(1)

// greedy
class Solution {
public:
    bool canAliceWin(vector<string>& a, vector<string>& b) {
        const auto& is_closely_greater = [](const auto& a, const auto& b) {
            return a[0] - b[0] <= 1 && a > b;
        };

        bool result = true;
        int i = 0, j = -1;
        while (true) {
            for (++j; j < size(b); ++j) {
                if (is_closely_greater(b[j], a[i])) {
                    break;
                }
            }
            if (j == size(b)) {
                break;
            }
            while (j + 1 < size(b) && b[j + 1][0] == b[j][0]) {
                ++j;
            }
            swap(a, b);
            swap(i, j);
            result = !result;
        }
        return result;
    }
};
