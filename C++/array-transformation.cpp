// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {    
        while (is_changable(arr)) {
            auto new_arr = arr;
            for (int i = 1; i + 1 < arr.size(); ++i) {
                new_arr[i] += int(arr[i - 1] > arr[i] && arr[i] < arr[i + 1]);
                new_arr[i] -= int(arr[i - 1] < arr[i] && arr[i] > arr[i + 1]);
            }
            arr = move(new_arr);
        }
        return arr;
    }

private:
    bool is_changable(const vector<int>& arr) {
        for (int i = 1; i + 1 < arr.size(); ++i) {
            if ((arr[i - 1] > arr[i] && arr[i] < arr[i + 1]) ||
                (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])) {
                return true;
            }
        }
        return false;
    }
};
