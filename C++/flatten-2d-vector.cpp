// Time:  O(1)
// Space: O(1)

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        it1 = vec2d.begin();
        it1_end = vec2d.end();
        if (it1 != it1_end) {
            it2 = it1->begin();
            it2_end = it1->end();
            adjustNextIter();
        }
    }

    int next() {
        const auto ret = *it2;
        ++it2;
        adjustNextIter();
        return ret;
    }

    bool hasNext() {
        return it1 != it1_end && it2 != it2_end;
    }
    
    void adjustNextIter() {
        while (it1 != it1_end && it2 == it2_end) { 
            ++it1;
            if (it1 != it1_end) {
                it2 = it1->begin();
                it2_end = it1->end();
            }
        }
    }

private:
    vector<vector<int>>::iterator it1;
    vector<vector<int>>::iterator it1_end;
    vector<int>::iterator it2;
    vector<int>::iterator it2_end;
};
