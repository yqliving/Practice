/*The idea is fairly straightforward: create an array accu that stores the accumulated sum for nums such that accu[i] = nums[0] + ... + nums[i - 1] in the initializer of NumArray. Then just return accu[j + 1] - accu[i] in sumRange. You may try the example in the problem statement to convince yourself of this idea.

The code is as follows.

C++*/

class NumArray {
public:
    NumArray(vector<int> &nums) {
        accu.push_back(0);
        for (int num : nums)
            accu.push_back(accu.back() + num);
    }

    int sumRange(int i, int j) {
        return accu[j + 1] - accu[i];
    }
private:
    vector<int> accu;
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);