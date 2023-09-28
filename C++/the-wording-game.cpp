// Time:  O(m + n), m = sum(len(w) for w in a), n = sum(len(w) for w in b)
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
        for (int _ = 0; _ < 26 * 2; ++_) {  // at most 1(begin)+26*2+1(end) turns by best strategy
            for (++j; j < size(b); ++j) {
                if (is_closely_greater(b[j], a[i])) {
                    break;
                }
            }
            if (j == size(b)) {
                break;
            }
            while (j + 1 < size(b) && b[j + 1][0] == b[j][0]) {  // play the lexicographically greatest word with the same beginning letter
                ++j;
            }
            swap(a, b);
            swap(i, j);
            result = !result;
        }
        return result;
    }
};
