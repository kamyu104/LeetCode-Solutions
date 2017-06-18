// Time:  O(1)
// Space: O(1)

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> lookup({ dist(p1, p2), dist(p1, p3),
                                    dist(p1, p4), dist(p2, p3),
                                    dist(p2, p4), dist(p3, p4) });
        return !lookup.count(0) && lookup.size() == 2;
    }

private:
    int dist(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) +
               (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};
