/*
2319. �жϾ����Ƿ���һ�� X ����
���һ�������ξ����������� ȫ�� ���������֮Ϊһ�� X ���� ��

����Խ����ϵ�����Ԫ�ض� ���� 0
��������������Ԫ�ض��� 0
����һ����СΪ n x n �Ķ�ά�������� grid ����ʾһ�������ξ���
��� grid ��һ�� X ���� ������ true �����򣬷��� false ��
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