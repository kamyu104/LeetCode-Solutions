// Time:  O(nlogn)
// Space: O(n)

// sort
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> order(size(names));
        iota(begin(order), end(order), 0);
        sort(begin(order), end(order), [&](const auto& x, const auto& y) { return heights[x] > heights[y]; });
        vector<string> result(size(names));
        for (int i = 0; i < size(order); ++i) {
            result[i] = names[order[i]];
        }
        return result;
    }
};
