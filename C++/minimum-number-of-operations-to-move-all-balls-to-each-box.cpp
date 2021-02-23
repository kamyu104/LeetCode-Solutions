// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> result(size(boxes)); 
        for (int i = 0, accu = 0, cnt = 0; i < size(boxes); ++i) {
           result[i] += accu;
           cnt += (boxes[i] == '1') ? 1 : 0;
           accu += cnt;
        }
        for (int i = size(boxes) - 1, accu = 0, cnt = 0; i >= 0; --i) {
            result[i] += accu;
            cnt += (boxes[i] == '1') ? 1 : 0;
            accu += cnt;
        }
        return result;
    }
};
