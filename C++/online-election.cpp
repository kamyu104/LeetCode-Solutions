// Time:  ctor: O(n)
//        q:    O(logn)
// Space: O(n)

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int lead = -1;
        unordered_map<int, int> count;
        for (int i = 0; i < persons.size(); ++i) {
            if (++count[persons[i]] >= count[lead]) {
                lead = persons[i];
                lookup_.emplace_back(times[i], persons[i]);
            }
        }
    }

    int q(int t) {
        return prev(upper_bound(lookup_.cbegin(), lookup_.cend(),
                                make_pair(t, numeric_limits<int>::max())))->second;
    }

private:
     vector<pair<int, int>> lookup_;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
