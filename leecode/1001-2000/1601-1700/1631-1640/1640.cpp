/*
1640. �ܷ������γ�����
����һ���������� arr �������е�ÿ������ ������ͬ ������һ�����������鹹�ɵ����� pieces�����е�����Ҳ ������ͬ �������� ����˳�� ���� pieces �е��������γ� arr �����ǣ������� ��ÿ������ pieces[i] �е�������������

����������� pieces �е������γ� arr ������ true �����򣬷��� false ��



ʾ�� 1��

���룺arr = [15,88], pieces = [[88],[15]]
�����true
���ͣ��������� [15] �� [88]
ʾ�� 2��

���룺arr = [49,18,16], pieces = [[16,18,49]]
�����false
���ͣ��������������Ҳ������������ pieces[0]
ʾ�� 3��

���룺arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
�����true
���ͣ��������� [91]��[4,64] �� [78]


��ʾ��

1 <= pieces.length <= arr.length <= 100
sum(pieces[i].length) == arr.length
1 <= pieces[i].length <= arr.length
1 <= arr[i], pieces[i][j] <= 100
arr �е����� ������ͬ
pieces �е����� ������ͬ��Ҳ����˵������� pieces ��ƽ����һά���飬�����е���������������ͬ��
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
		bool res = false;
		for (int i = 0; i < pieces.size(); i++)
		{
			res = false;
			for (int k = 0; k < arr.size(); k++)
			{
				if (pieces[i][0] == arr[k]) {
					for (int j = 1; j < pieces[i].size(); j++)
					{
						k++;
						if (pieces[i][j] != arr[k]) {
							return false;
						}
					}
					res = true;
					break;
				}
				
			}
			if (!res) {
				return res;
			}
		}
		return res;
    }
};
int main() {
	vector<int> arr = { 3, 4, 8 };
	vector<vector<int>> spiecs = { {3},{5,8} };
	Solution s;
	cout<<s.canFormArray(arr, spiecs);
}