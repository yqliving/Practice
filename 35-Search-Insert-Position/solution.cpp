class Solution {
public:
    int searchInsert(vector<int>& A, int target) {
    int i = 0, j = A.size() - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (A[mid] == target)
                return mid;
            if (A[mid] < target)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return i;
    }
};
//search from the mid