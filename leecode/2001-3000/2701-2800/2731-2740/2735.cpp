#include <vector>
using namespace std;
class Solution
{
public:
    long long minCost(vector<int>& nums, int x)
    {
        int n = nums.size();
        long long minValue = LLONG_MAX;
        vector<int> nums_op = nums; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[(j + i) % n] < nums_op[j]) {
                    nums_op[j] = nums[(j + i) % n];
                }
            }
            long long value = (long long)i*x;
            for (int j = 0; j < n; j++) {
                value += nums_op[j];
            }
            if (value < minValue) {
                minValue = value;
            }
        }
        return minValue;
    }
};