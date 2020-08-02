// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int result = arr[0];
        for (int i = 1, count = 0; i < arr.size(); ++i) {
            if (arr[i] > result) {
                result = arr[i];
                count = 0;
            }
            if (++count == k) {
                break;
            }
        }
        return result;
    }
};
