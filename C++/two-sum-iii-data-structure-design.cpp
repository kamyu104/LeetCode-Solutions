// Time:  O(n)
// Space: O(n)

class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    ++lookup_[number];
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (const auto& kvp : lookup_) {
	        const auto num = value - kvp.first;
	        if (lookup_.count(num) && (num != kvp.first || kvp.second > 1)) {
	            return true;
	        }
	    }
	    return false;
	}

private:
    unordered_map<int, int> lookup_;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
