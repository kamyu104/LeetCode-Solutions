// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        set<int> intersect{A[0], B[0]};
        for (int i = 1; i < A.size(); ++i) {
            const set<int> s1{A[i], B[i]};
            const auto s2 = move(intersect);
            set_intersection(s1.cbegin(), s1.cend(),
                             s2.cbegin(), s2.cend(),
                             inserter(intersect, intersect.begin()));
        }
        if (intersect.empty()) {
            return -1;
        }
        auto x = *intersect.begin();
        return min(A.size() - count(A.begin(), A.end(), x),
                   B.size() - count(B.begin(), B.end(), x));
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        unordered_set<int> intersect{A[0], B[0]};
        for (int i = 1; i < A.size(); ++i) {
            const unordered_set<int> s1{A[i], B[i]};
            const auto s2 = move(intersect);
            copy_if(s1.cbegin(), s1.cend(),
                    inserter(intersect, intersect.begin()),
                    [&s2](const int x) {
                        return s2.count(x) > 0;
                    });
        }
        if (intersect.empty()) {
            return -1;
        }
        auto x = *intersect.begin();
        return min(A.size() - count(A.begin(), A.end(), x),
                   B.size() - count(B.begin(), B.end(), x));
    }
};
