/*
1. ����֮��
����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�

����԰�����˳�򷵻ش𰸡�



ʾ�� 1��

���룺nums = [2,7,11,15], target = 9
�����[0,1]
���ͣ���Ϊ nums[0] + nums[1] == 9 ������ [0, 1] ��
ʾ�� 2��

���룺nums = [3,2,4], target = 6
�����[1,2]
ʾ�� 3��

���룺nums = [3,3], target = 6
�����[0,1]


��ʾ��

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
ֻ�����һ����Ч��
���ף���������һ��ʱ�临�Ӷ�С�� O(n2) ���㷨��

*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }
        return res;
    }
};

