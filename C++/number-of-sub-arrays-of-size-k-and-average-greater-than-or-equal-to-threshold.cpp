// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int result = 0, curr = accumulate(arr.cbegin(), arr.cbegin() + k - 1, 0);
        for (int i = k - 1; i < arr.size(); ++i) {
            curr += arr[i] - ((i - k >= 0) ? arr[i - k]: 0);
            result += int(curr >= k * threshold);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        vector<int> accu(arr.size() + 1);
        for (int i = 0; i < arr.size(); ++i) {
            accu[i + 1] = accu[i] + arr[i];
        }
        int result = 0;
        for (int i = 0; i + k - 1 < arr.size(); ++i) {
            result += int(accu[i + k] - accu[i] >= k * threshold);
        }
        return result;
    }
};
