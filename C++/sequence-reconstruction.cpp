// Time:  O(n * s), n is the size of org, s is the size of seqs
// Space: O(n)

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if (seqs.empty()) {
            return false;
        }
        vector<int> pos(org.size() + 1);
        for (int i = 0; i < org.size(); ++i) {
            pos[org[i]] = i;
        }

        vector<bool> is_matched(org.size() + 1);
        int cnt_to_match = org.size() - 1;
        for (const auto& seq : seqs) {
            for (int i = 0; i < seq.size(); ++i) {
                if (seq[i] <= 0 || seq[i] > org.size()) {
                    return false;
                }
                if (i == 0) {
                    continue;
                }
                if (pos[seq[i - 1]] >= pos[seq[i]]) {
                    return false;
                }
                if (is_matched[seq[i - 1]] == false && pos[seq[i - 1]] + 1 == pos[seq[i]]) {
                    is_matched[seq[i - 1]] = true;
                    --cnt_to_match;
                }
            }
        }
        return cnt_to_match == 0;
    }
};
