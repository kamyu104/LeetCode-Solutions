// Time:  O(n + klogk)
// Space: O(n)

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counts;
        for (int i = 0; i < words.size(); ++i) {
            ++counts[words[i]];
        }
        vector<pair<int, string>> p;
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            p.emplace_back(-(it->second), it->first);
        }
        nth_element(p.begin(), p.begin() + k - 1, p.end());  // O(n) time.
        sort(p.begin(), p.begin() + k);  // O(klogk) time.
        vector<string> result;
        for (int i = 0; i < k; ++i) {
            result.emplace_back(p[i].second);
        }
        return result;
    }
};
