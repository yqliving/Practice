class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size();
        int k1 = k - 1;
        int j, d;

        do {
            j = start;
            d = nums[start];
            for (int i = start + 1; i < end; i++) {
                if (nums[i] > d) {
                    nums[j] = nums[i];
                    nums[i] = nums[j+1];
                    j++;
                }
            }
            nums[j] = d;

            if (j < k1) {
                start = j+1;
            } else if (j > k1) {
                end = j;
            }
        } while (j != k1);

        return nums[k1];
    }
};

/*
class Solution { 
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++; 
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
};





/*class Solution {
    public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};