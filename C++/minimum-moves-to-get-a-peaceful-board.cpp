// Time:  O(n)
// Space: O(n)

// counting sort, greedy
class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        const auto& count = [](const auto& cnt) {
            int result = 0;
            for (int x = 0, i = 0; x < size(cnt); ++x) {
                for (int _ = 0; _ < cnt[x]; ++_) {
                    result += abs((i++) - x);
                }
            }
            return result;
        };

        vector<int> cnt1(size(rooks)), cnt2(size(rooks));
        for (const auto& x : rooks) {
            ++cnt1[x[0]];
            ++cnt2[x[1]];
        }
        return count(cnt1) + count(cnt2);
    }
};

// Time:  O(n)
// Space: O(n)
// prefix sum, greedy
class Solution2 {
public:
    int minMoves(vector<vector<int>>& rooks) {
        const auto& count = [](const auto& cnt) {
            int result = 0;
            for (int i = 0, bal = 0; i < size(cnt); ++i) {
                bal += cnt[i] - 1;
                result += abs(bal);
            }
            return result;
        };

        vector<int> cnt1(size(rooks)), cnt2(size(rooks));
        for (const auto& x : rooks) {
            ++cnt1[x[0]];
            ++cnt2[x[1]];
        }
        return count(cnt1) + count(cnt2);
    }
};
