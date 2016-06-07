// Time:  O(nlogn)
// Space: O(k),  k is the max size of heights with the same width.

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        vector<int> result;

        sort(envelopes.begin(), envelopes.end());
        for (int i = 0; i < envelopes.size();) {
            stack<int> same_hs;
            int w, h;
            tie(w, h) = envelopes[i];
            while (i < envelopes.size() && envelopes[i].first == w) {
                same_hs.emplace(distance(result.cbegin(),
                                lower_bound(result.cbegin(), result.cend(), envelopes[i++].second)));
            }
            int k = 0;
            while (!same_hs.empty()) {
                const auto target = envelopes[i - 1 - k++].second;
                auto j = same_hs.top();
                same_hs.pop();
                if (j == result.size()) {
                    result.emplace_back(target);
                } else {
                    result[j] = target;
                }
            }
        }

        return result.size();
    }
};
