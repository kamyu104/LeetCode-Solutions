// Time:  ctor: O(n)
//        q:    O(logn)
// Space: O(n)

class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int lead = -1;
        unordered_map<int, int> count;
        for (int i = 0; i < persons.size(); ++i) {
            lookup_[times[i]] = persons[i];
        }
        for (auto& kvp : lookup_) {
            if (++count[kvp.second] >= count[lead]) {
                lead = kvp.second;
            }
            kvp.second = lead;
        }
    }

    int q(int t) {
        return prev(lookup_.upper_bound(t))->second;
    }

private:
     map<int, int> lookup_;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
 
