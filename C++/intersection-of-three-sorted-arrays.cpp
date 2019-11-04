// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> result;
        int i = 0, j = 0, k = 0;
        while (i != arr1.size() && j != arr2.size() && k != arr3.size()) {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                result.emplace_back(arr1[i]);
                ++i, ++j, ++k;
            } else {
                int curr = max(max(arr1[i], arr2[j]), arr3[k]);
                for (; i != arr1.size() && arr1[i] < curr; ++i);
                for (; j != arr2.size() && arr2[j] < curr; ++j);
                for (; k != arr3.size() && arr3[k] < curr; ++k);
            }
        }
        return result;
    }
};
