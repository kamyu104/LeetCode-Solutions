// Time:  O(logn + k)
// Space: O(1)

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto i = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), x));
        int left = i - 1, right = i;                                    
        while (k--) {
            (right >= arr.size() || (left >= 0 && abs(arr[left] - x) <= abs(arr[right] - x) )) ? --left : ++right;
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};
