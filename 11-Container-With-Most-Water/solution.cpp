class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0;
        int l = 0, r = height.size()-1;
        while (l < r)
        {
            if (height[l] <= height[r])
            {
                res = max(res, (r-l) * height[l]);
                l++;
            }
            else
            {
                res = max(res, (r-l) * height[r]);
                r--;
            }
        }
        return res;
    }
};
/*用两个 pointer：start 和 end 从两头夹逼，同时分别记录 left max hight (lmh) 和 right max hight (rmh)；
当 lmh < rmh 时，start 上最多可以存放的 water 为 lmh - A[start]；
当 lmh > rmh 时，end 上最多可以存放的 water 为 rmh - A[end]；
这样扫完一遍，累加即可得到总的存放 water 的量