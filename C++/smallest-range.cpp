// Time:  O(nlogk)
// Space: O(k)

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using VIT = vector<int>::iterator;
        
        const auto comp = [](const pair<VIT, VIT>& p1, const pair<VIT, VIT>& p2) {
                              return *p1.first > *p2.first;
                          };
        
        int left = numeric_limits<int>::max(), right = numeric_limits<int>::min();
        priority_queue<pair<VIT, VIT>, vector<pair<VIT, VIT>>, decltype(comp)> min_heap(comp);
        for (const auto &row : nums) {
            left = min(left, row[0]);
            right = max(right, row[0]);
            min_heap.emplace(row.begin(), row.end());
        }
        
        vector<int> result = {left, right};
        while (!min_heap.empty()) {
            auto p = min_heap.top();
            min_heap.pop();
            ++p.first;
            if (p.first == p.second) {
                break;
            }
            min_heap.emplace(p);
            
            left = *min_heap.top().first;
            right = max(right, *p.first);
            if (right - left < result[1] - result[0]) {
                result = {left, right};
            }
        }
        return result;
    }
};

