// Time:  O(m + r * logn), m = len(groups), n = len(elements), r = max(groups)
// Space: O(r)

// hash table, number theory
class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        const int mx = ranges::max(groups);
        vector<int> lookup(mx, -1);
        for (int i = 0; i < size(elements); ++i) {
            if (elements[i] > mx || lookup[elements[i] - 1] != -1) {
                continue;
            }
            for (int x = elements[i]; x <= mx; x += elements[i]) {
                if (lookup[x - 1] == -1) {
                    lookup[x - 1] = i;
                }
            }
        }
        vector<int> result(size(groups));
        for (int i = 0; i < size(result); ++i) {
            result[i] = lookup[groups[i] - 1];
        }
        return result;
    }
};
