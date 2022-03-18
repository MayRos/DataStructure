#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int minimumOperations(string leaves) {
        int length = leaves.length();
        int str = 0;
        int num_of_1 = 0;
        for (int i = 0; i < length; i++)
        {
            if (leaves[i] == 'r') {
                uint64_t ii = 1;
                str =str + (ii << i);
                num_of_1++;
            }
        }
        int sum = 0;
        // 左[0,i]中(i,j)右[j,n-1]
        for (int i = 0; i < length; i++)
        {
            int y1 = 0;                                // 左侧1的个数
            int left = str >> (length - 1 - i);        // 左侧的值
            while (left) {                             // 求left中1的个数y1
                y1 += left % 2;
                left = left >> 1;
            }
            for (int j = length-1; j >i+1; j--) {
                int y2 = 0;                             // 右侧1的个数
                int right = str;
                for (int k = 0; k < (length - j); k++) {
                    y2 += right % 2;
                    right = right >> 1;
                }
                int r1 = j - i - 1 - (num_of_1 - y1 - y2);
                int temp = y1 + y2 + r1;
                sum = temp > sum ? temp : sum;
            }
            
        }
        return length-sum;
    }
};
int main() {
    string str = "ryyryyyrryyyyyryyyrrryyyryryyyyryyrrryryyyryrryrrrryyyrrrrryryyrrrrryyyryyryrryryyryyyyryyrryrryryy";
    cout << Solution().minimumOperations(str);

}