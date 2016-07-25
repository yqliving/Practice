
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    for (int i=nums.size()-1, j=0, k=i/2+1; i>=0; i--)
        nums[i] = sorted[i&1 ? k++ : j++];    //奇数，偶数的判断，好！  val&1
}
};
/*
Sort and then write the smaller half of the numbers on the even indexes and the larger half of the numbers on the odd indexes, both from the back. Example:

Small half:    4 . 3 . 2 . 1 . 0 .
Large half:    . 9 . 8 . 7 . 6 . 5
----------------------------------
Together:      4 9 3 8 2 7 1 6 0 5


/*
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        threeWayPartition(nums, nums[mid]);
        vector<int> res(n);
        int largeStart = n-1;
        int smallStart = (n%2) ? mid : (mid-1);
        for (int i = 0; i < n; i+=2)
            res[i] = nums[smallStart--];
        for (int i = 1; i < n; i+=2)
            res[i] = nums[largeStart--];
        nums = res;
    }
    
    // this ensures all values equal to the median is in the middle
    void threeWayPartition(vector<int> &nums, int val) {
        int i = 0, j = 0;
        int n = nums.size()-1;
        while (j <= n){
            if (nums[j] < val)
                swap(nums[i++], nums[j++]);
            else if (nums[j] > val)
                swap(nums[j], nums[n--]);
            else
                j++;
        }
    }
};
    