// Time:  O(n + klogk) on average
// Space: O(n)

// Quick Select Solution
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counts;
        for (const auto& word : words) {
            ++counts[word];
        }
        vector<pair<int, string>> p;
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            p.emplace_back(-(it->second), it->first);
        }
        nth_element(p.begin(), p.begin() + k - 1, p.end());  // O(n) time on average.
        sort(p.begin(), p.begin() + k);  // O(klogk) time.
        vector<string> result;
        for (int i = 0; i < k; ++i) {
            result.emplace_back(p[i].second);
        }
        return result;
    }
};


// Time:  O(nlogk)
// Space: O(n)
// Heap Solution
class Solution2 {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counts;
        for (const auto& word : words) {
            ++counts[word];
        }
        priority_queue<pair<int, string>> heap;
        for (const auto& kvp : counts) {
            heap.emplace(-kvp.second, kvp.first);
            if (heap.size() == k + 1) {
                heap.pop();
            }
        }
        vector<string> result;
        while (!heap.empty()) {
            result.emplace_back(heap.top().second);
            heap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
