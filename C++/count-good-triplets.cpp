// Time:  O(n^3)
// Space: O(1)

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int result = 0;
        for (int i = 0; i + 2 < arr.size(); ++i) {
            for (int j = i + 1; j + 1 < arr.size(); ++j) {
                for (int k = j + 1; k < arr.size(); ++k) {
                    if (abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b &&
                        abs(arr[k] - arr[i]) <= c) {
                        ++result;
                    }
                }
            }
        }
        return result;
    }
};
