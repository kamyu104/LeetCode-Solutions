// Time:  O(n)
// Space: O(n)

// Counting sort.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        const auto n = citations.size();
        vector<int> count(n + 1, 0);
        for (const auto& x : citations) {
            if (x >= n) {
                ++count[n];
            } else {
                ++count[x];
            }
        }

        int h = 0;
        for (int i = n; i >= 0; --i) {
            h += count[i];
            if (h >= i) {
                return i;
            }
        }
        return h;
    }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution2 {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int h = 0;
        for (const auto& x : citations) {
            if (x >= h + 1) {
                ++h;
            } else {
                break;
            }
        }
        return h;
    }
};
