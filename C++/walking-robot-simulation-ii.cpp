// Time:  O(1)
// Space: O(1)

class Robot {
public:
    Robot(int width, int height) : w_(width), h_(height) {
        
    }
    
    void move(int num) {
        curr_ += num;
    }
    
    vector<int> getPos() {
        int n = curr_ % (2 * ((w_ - 1) + h_ - 1));
        if (n < w_) {
            return {n, 0};
        }
        n -= (w_ - 1);
        if (n < h_) {
            return {w_ - 1, n};
        }
        n -= (h_ - 1);
        if (n < w_) {
            return {(w_ - 1) - n, h_ - 1};
        }
        n -= (w_ - 1);
        return {0, (h_ - 1) - n};
    }
    
    string getDir() {
        int n = curr_ % (2 * ((w_ - 1) + h_ - 1));
        if (n < w_) {
            return n == 0 && curr_ ? "South" : "East";
        }
        n -= (w_ - 1);
        if (n < h_) {
            return "North";
        }
        n -= (h_ - 1);
        if (n < w_) {
            return "West";
        }
        n -= (w_ - 1);
        return "South";
    }

    const int w_;
    const int h_;
    int curr_ = 0;
};

// Time:  O(1)
// Space: O(1)
class Robot2 {
public:
    Robot2(int width, int height) : w_(width), h_(height) {
        
    }
    
    void move(int num) {
        curr_ += num;
    }
    
    vector<int> getPos() {
        return getPosDir().first;
    }
    
    string getDir() {
        return getPosDir().second;
    }

private:
    pair<vector<int>, string> getPosDir() {
        int n = curr_ % (2 * ((w_ - 1) + h_ - 1));
        if (n < w_) {
            return {{n, 0}, (n == 0 && curr_) ? "South" : "East"};
        }
        n -= (w_ - 1);
        if (n < h_) {
            return {{w_ - 1, n}, "North"};
        }
        n -= (h_ - 1);
        if (n < w_) {
            return {{(w_ - 1) - n, h_ - 1}, "West"};
        }
        n -= (w_ - 1);
        return {{0, (h_ - 1) - n}, "South"};
    }

    const int w_;
    const int h_;
    int curr_ = 0;
};
