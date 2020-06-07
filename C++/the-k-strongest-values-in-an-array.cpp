// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        nth_element(begin(arr), begin(arr) + (arr.size() - 1) / 2, end(arr));
        const auto m = arr[(arr.size() -1) / 2];
        nth_element(begin(arr), begin(arr) + k, end(arr), [&](int a, int b) { 
            return abs(a - m) != abs(b - m) ?  abs(a - m) > abs(b - m) : a > b; 
        });
        arr.resize(k);
        return arr;
    }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution2 {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(begin(arr), end(arr));
        const auto m = arr[(arr.size() -1) / 2];
        sort(begin(arr), end(arr), [&](int a, int b) { 
            return abs(a - m) != abs(b - m) ?  abs(a - m) > abs(b - m) : a > b; 
        });
        arr.resize(k);
        return arr;
    }
};
