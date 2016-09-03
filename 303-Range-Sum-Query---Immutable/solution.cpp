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

/*
提示：数组不会发生变化；大量sumRange函数调用。

题目本身非常简单，只需要遍历 i 到 j ，累计得到和即可。但是，这样是TLE的，所给提示也就没有意义了。

所以，题目考察的是效能，换一个方向思考，我们可以存储子序列和，每个下标处的值为[0,i]的所有元素和;

那么[i,j]子序列和 =sum[j]−sum[i−1]；
