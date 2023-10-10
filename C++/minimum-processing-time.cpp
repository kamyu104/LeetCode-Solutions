// Time:  O(nlogn)
// Space: O(1)

// sort, greedy
class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        static const int K = 4;

        sort(begin(processorTime), end(processorTime));
        sort(rbegin(tasks), rend(tasks));
        int result = 0;
        for (int i = 0; i < size(processorTime); ++i) {
            for (int j = 0; j < K; ++j) {
                result = max(result, processorTime[i] + tasks[i * K + j]);
            }
        }
        return result;
    }
};
