// Time:  O(nlogn)
// Space: O(1)

// greedy, sort
class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        const auto& cost = [&]() {
            long long result = 0;
            for (int i = 0; i < size(arr); ++i) {
                result += abs(arr[i] - brr[i]);
            }
            return result;
        };

        long long result = cost();
        sort(begin(arr), end(arr));
        sort(begin(brr), end(brr));
        result = min(result, k + cost());
        return result;
    }
};
