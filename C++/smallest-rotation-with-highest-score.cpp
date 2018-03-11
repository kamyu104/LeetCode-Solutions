// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int bestRotation(vector<int>& A) {
        const int N = A.size();
        vector<int> change(N);
        for (int i = 0; i < N; ++i) {
            --change[(i - A[i] + 1 + N) % N];
        }
        for (int i = 1; i < N; ++i) {
            change[i] += change[i - 1] + 1;
        }
        return distance(change.begin(), max_element(change.begin(), change.begin() + N));
    }
};
