class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=triangle.size()-2;i>=0;i--)
            for(int j=0;j<=i;j++)
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        return triangle[0][0];
    }
};
/*
从下向上
This problem is quite well-formed in my opinion. The triangle has a tree-like structure, which would lead people to think about traversal algorithms such as DFS. However, if you look closely, you would notice that the adjacent nodes always share a 'branch'. In other word, there are overlapping subproblems. Also, suppose x and y are 'children' of k. Once minimum paths from x and y to the bottom are known, the minimum path starting from k can be decided in O(1), that is optimal substructure. Therefore, dynamic programming would be the best solution to this problem in terms of time complexity.

