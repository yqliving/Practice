class Solution {
public:
    void sortColors(vector<int>& A) {
        sort(A.begin(), A.end());
        return A;
    }
/*class Solution {
public:
    void sortColors(vector<int>& A) {
     int n = A.size();
     int red = 0, blue = n-1;
        int i = 0;
        while (i <= blue)
        {
            switch(A[i])
            {
            case 0:
                swap(A[i++], A[red++]);
                break;
            case 1:
                i++;
                break;
            case 2:
                swap(A[i], A[blue--]);
            }
        }
    }
};   
/*swap函数，作用是交换两个元素的值
Use two pointers (one-pass): Time ~ O(N), Space ~ O(1) 
因为只有三种颜色，可以设 red (0) 和 blue (2) 两个 index，从两头向中间逼近。
同时用 curr index 从头到尾扫描 array，有三种情况：
A[curr] == 0: swap(curr, red); curr++; red++;
A[curr] == 1: curr++;
A[curr] == 2: swap(curr, blue); blue--.