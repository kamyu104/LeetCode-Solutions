// Time:  O(n)
// Space: O(n)

// graph
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int result = -1;
        vector<int> lookup(size(edges), -1);
        for (int i = 0, idx = 0; i < size(edges); ++i) {
            if (lookup[i] != -1) {
                continue;
            }
            const int start = idx;
            int j = i;
            for (; j != -1; j = edges[j]) {
                if (lookup[j] != -1) {
                    break;
                }
                lookup[j] = idx++;
            }
            if (j != -1 && lookup[j] >= start) {
                result = max(result, idx - lookup[j]);
            }
        }
        return result;
    }
};
