// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int result = numeric_limits<int>::max(), total = 0, curr = 0, left = 0;
        for (int right = 0; right < cardPoints.size(); ++right) {
            total += cardPoints[right];
            curr += cardPoints[right];
            if (right - left + 1 > cardPoints.size() - k) {
                curr -= cardPoints[left++];
            }
            if (right - left + 1 == cardPoints.size() - k) {
                result = min(result, curr);
            }
        }
        return total - result;
    }
};
