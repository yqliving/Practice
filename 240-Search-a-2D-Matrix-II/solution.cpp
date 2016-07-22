class Solution {
public:
   // O(m+n) solution

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
 int i = 0;
 int j = matrix[0].size() - 1;
 
 while(i < matrix.size() && j >= 0) {
     if(matrix[i][j] == target)
         return true;
     
     if(matrix[i][j] < target)
         i++;
     else
         j--;
 }
 
 return false;
 }

};

/*
O(mlogn) solution

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
return searchMatrix(matrix, target, 0, matrix.size() - 1);
 }

 bool searchMatrix(vector<vector<int>>& matrix, int target, int top, int bottom) {
if (top > bottom)
	return false;

int mid = top + (bottom - top) / 2;
if (matrix[mid].front() <= target && target <= matrix[mid].back())
	if (searchVector(matrix[mid], target)) return true;

if (searchMatrix(matrix, target, top, mid - 1)) return true;
if (searchMatrix(matrix, target, mid + 1, bottom)) return true;

return false;
 }

 bool searchVector(vector<int>& v, int target) {
int left = 0, right = v.size() - 1;

while (left <= right) {
	int mid = left + (right - left) / 2;
	if (v[mid] == target)
		return true;
	if (v[mid] < target)
		left = mid + 1;
	else
		right = mid - 1;
}

return false;
 }