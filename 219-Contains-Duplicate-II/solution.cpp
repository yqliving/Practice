class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)  {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.count(nums[i]) && i - mp[nums[i]] <= k) return true;
        mp[nums[i]] = i;
    }
    return false;
    }
};

/*=========
定义一个长度最大为k的滑动窗口，用一个unordered_set维护窗口内的数字判断是否出现重复，使用两个指针start和end标记滑动窗口的两端，初始都是0，然后end不断进行扩展，扫描元素判断是否出现重复元素，直到发现end−start>k, 就开始移动start，并且在set中移除对应的元素。如果以为扫描到数组末尾还没有发现重复元素，那就可以返回false。时间复杂度和空间复杂度都是O（N）。

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty())
            return false;

        int sz = nums.size();
        //使用容器unordered_set 其查找性能为常量
        unordered_set<int> us;
        int start = 0, end = 0;
        for (int i = 0; i < sz; ++i)
        {
            if (us.count(nums[i]) == 0)
            {
                us.insert(nums[i]);
                ++end;
            }
            else{
                return true;
            }

            if (end - start > k)
            {
                us.erase(nums[start]);
                ++start;
            }
        }//for
        return false;

    }
};