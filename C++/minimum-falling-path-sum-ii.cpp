// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        for (int i = 1; i < arr.size(); ++i) {
            const auto& smallest_two = nsmallest(2, arr[i - 1]);
            for (int j = 0; j < arr[0].size(); ++j) {
                arr[i][j] += (arr[i - 1][j] == smallest_two[0]) ? smallest_two[1] : smallest_two[0];
            }
        }
        return *min_element(arr.back().cbegin(), arr.back().cend());
    }

private:
    vector<int> nsmallest(int k, const vector<int>& arr) {
        priority_queue<int> max_heap;
        for (const auto& x : arr) {
            max_heap.emplace(x);
            if (max_heap.size() > k) {
                max_heap.pop();
            }
        }
        vector<int> result;
        while (!max_heap.empty()) {
            result.emplace_back(max_heap.top()); max_heap.pop();
        }
        return {result.crbegin(), result.crend()};
    }
};
