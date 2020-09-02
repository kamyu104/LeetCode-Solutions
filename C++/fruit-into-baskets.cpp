// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> count;
        int result = 0;
        for (int i = 0, j = 0; j < tree.size(); ++j) {
            ++count[tree[j]];
            while (count.size() > 2) {
                --count[tree[i]];
                if (count[tree[i]] == 0) {
                    count.erase(tree[i]);
                }
                ++i;
            }
            result = max(result, j - i + 1);
        }
        return result;
    }
};
