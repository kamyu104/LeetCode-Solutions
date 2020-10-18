// Time:  O(n)
// Space: O(1)

class Solution {
public:
    double trimMean(vector<int>& arr) {
        static const int P = 20;
        const int k = size(arr) / P;
        nth_element(begin(arr), begin(arr) + k - 1, end(arr));
        nth_element(begin(arr) + k, end(arr) - k, end(arr));
        return accumulate(begin(arr) + k, end(arr) - k, 0.0) / (size(arr) - 2 * k);
    }
};
