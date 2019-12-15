// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        for (const auto& x : {arr[arr.size() / 4], arr[arr.size() / 2], arr[arr.size() * 3 / 4]}) {
            if (distance(lower_bound(arr.cbegin(), arr.cend(), x),
                         upper_bound(arr.cbegin(), arr.cend(), x)) * 4 > arr.size()) {
                return x;
            }
        }
        return -1;
    }
};
