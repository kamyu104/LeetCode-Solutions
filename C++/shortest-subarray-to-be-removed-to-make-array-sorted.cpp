// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int j;
        for (j = arr.size() - 1; j >= 1; --j) {
            if (arr[j - 1] > arr[j]) {
                break;
            }
        }
        if (j == 0) {
            return 0;
        }
        int result = j;
        for (int i = 0; i < arr.size(); ++i) {
            if (i && arr[i - 1] > arr[i]) {
                break;
            }
            while (j < arr.size() && arr[i] > arr[j]) {
                ++j;
            }
            result = min(result, (j - i + 1) - 2);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int result = 0;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i - 1] <= arr[i]) {
                continue;
            }
            int j = arr.size() - 1;
            while (j > i && (j == arr.size() - 1 || arr[j] <= arr[j + 1]) && arr[i - 1] <= arr[j]) {
                --j;
            }
            result = j - i + 1;
            break;
        }
        for (int j = arr.size() - 2; j >= 0; --j) {
            if (arr[j] <= arr[j + 1]) {
                continue;
            }
            int i = 0;
            while (i < j && (i == 0 || arr[i - 1] <= arr[i]) && arr[i] <= arr[j + 1]) {
                ++i;
            }
            result = min(result, j - i + 1);
            break;
        }
        return result;
    }
};
