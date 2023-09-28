// Time:  O(m + n), m = sum(len(w) for w in a), n = sum(len(w) for w in b)
// Space: O(1)

// game, greedy
class Solution {
public:
    bool canAliceWin(vector<string>& a, vector<string>& b) {
        const auto& is_closely_greater = [](const auto& a, const auto& b) {
            return a[0] - b[0] <= 1 && a > b;
        };

        bool result = true;
        int i = 0, j = -1;
        unordered_set<char> alphabet1;
        for (const auto& w : a) {
            alphabet1.emplace(w[0]);
        }
        unordered_set<char> alphabet2;
        for (const auto& w : b) {
            alphabet2.emplace(w[0]);
        }
        const int turn = size(alphabet1) + size(alphabet2);
        for (int _ = 0; _ < turn; ++_) {  // each player takes turns using a word with a different first letter than the last word he played
            for (++j; j < size(b); ++j) {
                if (is_closely_greater(b[j], a[i])) {
                    break;
                }
            }
            if (j == size(b)) {
                break;
            }
            while (j + 1 < size(b) && b[j + 1][0] == b[j][0]) {  // play the lexicographically greatest word with the same first letter
                ++j;
            }
            swap(a, b);
            swap(i, j);
            result = !result;
        }
        return result;
    }
};
