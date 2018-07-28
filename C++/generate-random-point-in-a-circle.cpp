// Time:  O(1)
// Space: O(1)

class Solution {
public:
    Solution(double radius, double x_center, double y_center) :
        radius_(radius),
        x_center_(x_center),
        y_center_(y_center), 
        gen_((random_device())()),
        uni_(0.0, 1.0) {
        
    }
    
    vector<double> randPoint() {
        const auto r = radius_ * sqrt(uni_(gen_));
        const auto theta = (2 * M_PI) * uni_(gen_);
        return {r * cos(theta) + x_center_,
                r * sin(theta) + y_center_};
    }
    
private:
    double radius_;
    double x_center_;
    double y_center_;
    default_random_engine gen_;
    uniform_real_distribution<double> uni_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */
