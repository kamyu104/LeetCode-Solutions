// Time:  O(nlogn)
// Space: O(k),  k is the max size of heights with the same width.

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        vector<int> result;

        sort(envelopes.begin(), envelopes.end());
        for (int i = 0; i < envelopes.size();) {
            int w = envelopes[i].first;
            int same_count = 0;
            while (i < envelopes.size() && envelopes[i].first == w) {
                ++i, ++same_count;
            }

            for (int j = i - 1; j >= i - same_count; --j) {
                const auto target = envelopes[j].second;
                auto it = lower_bound(result.begin(), result.end(), target);
                if (it == result.end()) {
                    result.emplace_back(target);
                } else {
                    *it = target;
                }
            }
        }

        return result.size();
    }
};
