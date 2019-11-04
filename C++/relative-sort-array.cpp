// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < arr2.size(); ++i) {
            lookup[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(),
             [&lookup, l = arr2.size()](const auto& a, const auto& b) {
                 int i = lookup.count(a) ? lookup[a] : l + a;
                 int j = lookup.count(b) ? lookup[b] : l + b;
                 return i < j;
             });
        return arr1;
    }
};
