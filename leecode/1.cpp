//<<<<<<< HEAD
/*
1. 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。



示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]


提示：

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？

*/
#include <iostream>
#include <vector>
using namespace std;
/*class Solution {
public:
    // 暴力
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
    void quickSort(vector<int>& nums,vector<int>& position,int start,int end){
        int tag = nums.at(position.at(end));
        int i = start;
        int j = end-1;
        {

        }
    }
    vector<int> sort(vector<int>& nums,int target){
        vectot<int> position;
        for(int i =0;i<nums.size();i++){
            position.push_back(i);
        }
        quickSort(nums,position,0,nums.size()-1);
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        
    }
};
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index(nums.size()) ;
        for(int i = 0; i<nums.size();i++){
            index[i] = i;
        }
        vector<int> res(2);
        quickSort(nums,index,0,nums.size()-1);
        for(int i = 0; i<nums.size();i++){
            cout<<nums[index[i]];
        }
        int left = 0;
        int right =nums.size()-1;
        while(nums[index[left]]+nums[index[right]]!= target){
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
    void quickSort(const vector<int>& nums , vector<int>& index,int start,int end){
        if(start >= end){
            return;
        }
        int base = nums.at(index.at(end));
        int left = start;
        int right =end-1;
        while(left<right){
            while(nums.at(index.at(left))<base&&left<right){
                left++;
            }
            while(nums.at(index.at(right))>base&&left<right){
                right++;
            }
            int item = index.at(left);
             index.at(left) =  index.at(right);
             index.at(right) = item;
        }
        if(nums.at(index.at(right))>base){
            int item = index.at(end);
            index.at(end) =  index.at(right);
            index.at(right)= item;
        }
        quickSort(nums,index,start,left);
        quickSort(nums,index,left+2,end);
    }
};
