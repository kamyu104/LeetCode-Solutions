// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> result(seq.length());
        for (int i = 0; i < seq.length(); ++i) {
            result[i] = (i & 1) ^ (seq[i] == '(');
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int A = 0, B = 0;
        vector<int> result(seq.length());
        for (int i = 0; i < seq.length(); ++i) {
            int point = seq[i] == '(';
            if ((point > 0 && A <= B) ||
                (point < 0 && A >= B)) {
                A += point;
            } else {
                B += point;
                result[i] = 1;
            }
        }
        return result;
    }
};
