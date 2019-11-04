// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int, vector<int>, greater<int>>> min_heaps;
        for (const auto& item: items) {
            min_heaps[item[0]].emplace(item[1]);
            if (min_heaps[item[0]].size() > 5) {
                min_heaps[item[0]].pop();
            }
        }
        
        vector<vector<int>> result;
        for (auto& [i, min_heap] : min_heaps) {
            int total = 0, count = min_heap.size();
            while (!min_heap.empty()) {
                total += min_heap.top(); min_heap.pop();
            }
            result.push_back({i, total / count});
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
class Solution2 {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> result;
        map<int, vector<int>> students;
        for (const auto& item : items) {
            students[item[0]].push_back(item[1]);
        }
        for (auto& [i, scores] : students) {
          partial_sort(scores.begin(), scores.begin() + 5, scores.end(), greater<int>());
          result.push_back({i, accumulate(scores.cbegin(), scores.cbegin() + 5, 0) / 5});
       }
       return result;
    }
};
