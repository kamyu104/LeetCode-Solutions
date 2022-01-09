// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        auto bitmask = [](const auto& w) {
            int mask = 0;
            for (int i = 0; i < size(w); ++i) {
                mask |= 1 << (w[i] - 'a');
            }
            return mask;
        };
        unordered_set<int> lookup;
        for (const auto& w : startWords) {
            lookup.emplace(bitmask(w));
        }
        int result = 0;
        for (const auto& w : targetWords) {
            const int mask = bitmask(w);
            for (const auto& c : w) {
                if (lookup.count(mask ^ (1 << (c - 'a')))) {
                    ++result;
                    break;
                }
            }
        }
        return result;
    }
};
