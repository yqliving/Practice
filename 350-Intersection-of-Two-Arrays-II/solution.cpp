/*hashtable (using unordered_map).

time complexity: max(O(m), O(n))
space complexity: choose one O(m) or O(n) <--- So choose the
smaller one if you can*/
class Solution {
    public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> map1;
        for (int num : nums1) map1[num]++;
        
        for (int num : nums2) {
            if (map1.find(num) != map1.end() && map1[num] > 0) {
                ret.push_back(num);
                map1[num]--;
            }
        }
        return ret;
    }
};

/*
Sort and two pointers Solution:
Time: O(max(m, n) log(max(m, n))) Space: O(m + n)
O(mlgm) <-- sort first array
O(nlgn) <--- sort second array
O(mlgn) <--- for each element in nums1, do binary search in nums2
O(nlgm) <--- for each element in nums2, do binary search in nums1
space complexity: depends on the space complexity used in your
sorting algorithm, bounded by max(O(m), O(n))


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = (int)nums1.size(), n2 = (int)nums2.size();
        int i1 = 0, i2 = 0;
        vector<int> res;
        while(i1 < n1 && i2 < n2){
            if(nums1[i1] == nums2[i2]) {
                res.push_back(nums1[i1]);
                i1++;
                i2++;
            }
            else if(nums1[i1] > nums2[i2]){
                i2++;
            }
            else{
                i1++;
            }
        }
        return res;
    }
};