// Time:  O(n!)
// Space: O(n)

class Solution {
public:
    int countArrangement(int N) {
        vector<int> arrangement(N);
        iota(arrangement.begin(), arrangement.end(), 1);
        return countArrangementHelper(N, &arrangement);
    }

private:
    int countArrangementHelper(int n, vector<int> *arrangement) {
        if (n <= 0) {
            return 1;
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if ((*arrangement)[i] % n == 0 || n % (*arrangement)[i] == 0) {
                swap((*arrangement)[i], (*arrangement)[n - 1]);
                count += countArrangementHelper(n - 1, arrangement);
                swap((*arrangement)[i], (*arrangement)[n - 1]);
            }
        }
        return count;
    }
};
