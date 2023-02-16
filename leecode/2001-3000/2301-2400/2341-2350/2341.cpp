#include<vector>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> res = {0,0};
        set<int> set;

        for (int i = 0; i < nums.size(); i++) {
            if (set.find(nums[i]) != set.end()) {
                set.erase(nums[i]);
                res[0] += 1;
            }
            else {
                set.insert(nums[i]);
            }
        }
        res[1] = nums.size() - 2 * res[0];
        return res;
    }
};
int main() {
    vector<int> nums = { 1,3,2,1,3,2,2 };
    Solution s;
    vector<int> res =s.numberOfPairs(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << "\t";
    }
}