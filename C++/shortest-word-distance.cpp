// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int dist = INT_MAX;
        for (int i = 0, index1 = -1, index2 = -1; i < words.size(); ++i) {
            if (words[i] == word1) {
                index1 = i;
            } else if (words[i] == word2) {
                index2 = i;
            }
            if (index1 != -1 && index2 != -1) {
                dist = min(dist, abs(index1 - index2));
            }
        }
        return dist;
    }
};
