//<<<<<<< HEAD
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
#include <unordered_map>
using namespace std;
class Solution {
public:
    // ����
    vector<int> twoSum_bruce(vector<int>& nums, int target) {
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
    // ����� ���
    void quickSort(const vector<int>& nums , vector<int>& index,int start,int end){
        if(start >= end){
            return;
        }
        int base = nums.at(index.at(end));
        int left = start;
        int right = end-1;
        while(left<right){
            while (nums.at(index.at(left)) <= base && left < right) {
                left++;
            }
            while (nums.at(index.at(right)) >= base && left < right) {
                right--;
            }
            int item = index.at(left);
            index.at(left) = index.at(right);
            index.at(right) = item;
        }
        if(nums.at(index.at(right))>base){
            int item = index.at(end);
            index.at(end) =  index.at(right);
            index.at(right)= item;
            quickSort(nums,index,start,left-1);
            quickSort(nums,index,left+1,end);
        }
        else {
            quickSort(nums, index, start, left);
        }
        
    }
    vector<int> twoSum_sort(vector<int>& nums, int target) {
        vector<int> index(nums.size()) ;
        for(int i = 0; i<nums.size();i++){
            index[i] = i;
        }
        vector<int> res(2);
        quickSort(nums,index,0,nums.size()-1);
        for (int i = 0; i <  nums.size()-1; i++) {
            if (nums[index[i]] > nums[index[i + 1]]) {
                cout << index[i]<<"  " << nums[index[i]] << endl;// = i;
            }
            
        }
        int left = 0;
        int right =nums.size()-1;
        while(nums[index[left]]+nums[index[right]]!= target &&left<right){
            while(nums[index[left]]+nums[index[right]]<target){
                left++;
            }
            while(nums[index[left]]+nums[index[right]]>target){
                right--;
            }
        }
        res[0] = index[left];
        res[1] = index[right];
        return res;
    }
    // hash
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashT;
        for (int i = 0; i < nums.size(); i++) {
            auto j = hashT.find(target - nums[i]);
            if (j != hashT.end()) {
                return {j->second,i };
            }
            hashT[nums[i]] = i;
        }
        return {};
    }
};
