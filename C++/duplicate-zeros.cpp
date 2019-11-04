// Time:  O(n)
// Space: O(1)

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int shift = 0, i;
        for (i = 0; i + shift < arr.size(); ++i) {
            shift += int(arr[i] == 0);
        }
        for (i = i - 1; shift > 0; --i) {
            if (i + shift < arr.size()) {
                arr[i + shift] = arr[i];
            }
            if (arr[i] == 0) {
                --shift;
                arr[i + shift] = arr[i];
            }
        }
    }
};
