// Time:  O(nlogn + nlogk) = O(nlogn), k is the length of the result.
// Space: O(1)

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        vector<int> result;

        sort(envelopes.begin(), envelopes.end());  // O(nlogn)
        for (int i = 0; i < envelopes.size();) {
            const auto w = envelopes[i].first;
            auto same_count = 0;
            while (i < envelopes.size() && envelopes[i].first == w) {
                ++i, ++same_count;
            }

            for (int j = i - 1; j >= i - same_count; --j) {  // Insert from larger h.
                const auto target = envelopes[j].second;
                auto it = lower_bound(result.begin(), result.end(), target);  // O(logk)
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
