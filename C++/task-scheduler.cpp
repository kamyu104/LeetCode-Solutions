// Time:  O(n)
// Space: O(26) = O(1)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> count;
        int max_count = 0;
        for (const auto& task : tasks) {
            ++count[task];
            max_count = max(max_count, count[task]);
        }
        
        auto result = (max_count - 1) * (n + 1);
        for (const auto& kvp : count) {
            if (kvp.second == max_count) {
                ++result;
            }
        }
        return max(result, static_cast<int>(tasks.size()));
    }
};
