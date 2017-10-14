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
        for (const auto& kvp : counts) {
            p.emplace_back(-kvp.second, kvp.first);
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


// Time:  O(n + klogk) ~ O(n + nlogn)
// Space: O(n)
// Bucket Sort Solution
class Solution3 {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counts;
        for (const auto& word : words) {
            ++counts[word];
        }
        vector<vector<string>> buckets(words.size() + 1);
        for (const auto& kvp : counts) {
            buckets[kvp.second].emplace_back(kvp.first);
        }

        vector<pair<int, string>> p;
        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (const auto& word : buckets[i]) {
                p.emplace_back(-i, word);
            }
            if (p.size() >= k) {
                break;
            }
        }
        sort(p.begin(), p.end());
        vector<string> result;
        for (int i = 0; i < k; ++i) {
            result.emplace_back(p[i].second);
        }
        return result;
    }
};
