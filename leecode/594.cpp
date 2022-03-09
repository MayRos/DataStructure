#include <vector>

using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxLength = 0;
        int thisLength = 0;
        vector<int> beFound;
        for (int i = 0; i < nums.size();i++)
        {
            int iItem = nums[i];
            if ((std::count (beFound.begin(), beFound.end(), iItem) )!= 0) {
                break;
            }
            else {
                beFound.push_back(iItem);
            }
            bool bigger = false;
            thisLength=0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == iItem) {
                    thisLength++;
                }
                if (1==(nums[j]-iItem))
                {
                    thisLength++;
                    bigger = true;
                }
            }
            if (bigger) {
                maxLength = (thisLength > maxLength) ? thisLength : maxLength;
            }

        }
        return maxLength;
    }
    int main() {
        vector<int> nums = { -3, -1, -1, -1, -3, -2 };
        findLHS(nums);
    }
};