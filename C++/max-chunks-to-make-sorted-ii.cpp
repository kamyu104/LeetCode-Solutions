// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> idxs(arr.size());
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(),
             [&](int i1, int i2) {
                 return arr[i1] != arr[i2] ? arr[i1] < arr[i2] : i1 < i2;
             });

        int result = 0;
        for (auto i = 0, max_i = 0; i < idxs.size(); ++i) {
            max_i = max(max_i, idxs[i]);
            if (max_i == i) ++result;
        }
        return result;
    }
};
