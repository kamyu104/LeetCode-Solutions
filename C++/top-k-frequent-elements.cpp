// Time:  O(n)
// Space: O(n)

// Bucket Sort Solution
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (const auto& i : nums) {
            ++counts[i];
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& kvp : counts) {
            buckets[kvp.second].emplace_back(kvp.first);
        }

        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (int j = 0; j < buckets[i].size(); ++j){
                result.emplace_back(buckets[i][j]);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};

// Time:  O(n) ~ O(n^2), O(n) on average.
// Space: O(n)
// Quick Select Solution
class Solution2 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (const auto& i : nums) {
            ++counts[i];
        }

        vector<pair<int, int>> p;
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            p.emplace_back(-(it->second), it->first);
        }
        nth_element(p.begin(), p.begin() + k - 1, p.end());

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.emplace_back(p[i].second);
        }
        return result;
    }
};

// Time:  O(nlogk)
// Space: O(n)
// Heap solution.
class Solution3 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int i = 0; i < nums.size(); ++i) {
            ++counts[nums[i]];
        }
        priority_queue<pair<int, int>> heap;
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            heap.emplace(-(it->second), it->first);
            if (heap.size() == k + 1) {
                heap.pop();
            }
        }
        vector<int> result;
        while (!heap.empty()) {
            result.emplace_back(heap.top().second);
            heap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
