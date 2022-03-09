// leetcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <vector>
#include <iostream>
using namespace std;

    int findLHS(vector<int>& nums) {
        int maxLength = 0;
        int thisLength = 0;
        int higher = 0;
        int lower = 0;
        vector<int> beFound;
        for (int i = 0; i < nums.size(); i++)
        {
            int iItem = nums[i];

            if ((std::count(beFound.begin(), beFound.end(), iItem)) != 0) {
                continue;
            }
            else {
                beFound.push_back(iItem);
            }
           
            higher = 0;
            lower = 0;
            thisLength = 0;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] == iItem) {
                    thisLength++;
                }
                else if (1 == (nums[j] - iItem))
                {
                    higher++;
                    
                }
                else if (1 == (iItem - nums[j])) {
                    lower++;
                }
            }
            if (higher!=0||lower!=0) {
                thisLength += (higher > lower) ? higher : lower;
                maxLength = (thisLength > maxLength) ? thisLength : maxLength;
            }

        }
        return maxLength;
    }

int main() {
        vector<int> nums = { -3, -1, -1, -1, -3, -2 };
       cout<< findLHS(nums);
    }