class NumArray {
private:
    vector<int> prefix_;

public:
    NumArray(vector<int>& nums) {
        setPrefix(nums);
    }
    
    void setPrefix(vector<int> nums) {
        int total = 0;
        prefix_.push_back(total);
        for (auto num : nums) {
            total += num;
            prefix_.push_back(total);
        }
    }

    int sumRange(int left, int right) {
        return prefix_[right + 1] - prefix_[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */