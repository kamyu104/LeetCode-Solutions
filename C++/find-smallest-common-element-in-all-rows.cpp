// Time:  O(m * n)
// Space: O(n)

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        // values could be duplicated in each row
        unordered_set<int> intersections(mat[0].cbegin(), mat[0].cend());
        for (int i = 1; i < mat.size(); ++i) {
            const auto a = move(intersections);
            const unordered_set<int> b(mat[i].cbegin(), mat[i].cend());
            copy_if(a.cbegin(), a.cend(),
                    inserter(intersections, intersections.begin()),
                    [&b](const int x){ return b.count(x); });
            if (intersections.empty()) {
                return -1;
            }
        }
        return *min_element(intersections.cbegin(), intersections.cend());
    }
};

// Time:  O(m * n)
// Space: O(n)
class Solution2 {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        // assumed value is unique in each row
        unordered_map<int, int> counter;
        for (const auto& row : mat) {
            for (const auto& c : row) {
                ++counter[c];
                if (counter[c] == mat.size()) {
                    return c;
                }
            }
        }
        return -1;
    }
};
