/*
2319. 判断矩阵是否是一个 X 矩阵
如果一个正方形矩阵满足下述 全部 条件，则称之为一个 X 矩阵 ：

矩阵对角线上的所有元素都 不是 0
矩阵中所有其他元素都是 0
给你一个大小为 n x n 的二维整数数组 grid ，表示一个正方形矩阵。
如果 grid 是一个 X 矩阵 ，返回 true ；否则，返回 false 。
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int size = grid.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
				if ((i == j || i + j + 1 == size) && grid[i][j] != 0) {
                    ;
                }
                else if ((i != j &&i + j + 1 != size) && grid[i][j]==0)
                {
                    ;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
int main() {
    vector<vector<int>> grid = { {0, 0, 0, 1},{0, 3, 1, 0},{0, 5, 2, 0},{4, 0, 0, 2} };
    Solution s;
    bool res = s.checkXMatrix(grid);
    cout << res;
}