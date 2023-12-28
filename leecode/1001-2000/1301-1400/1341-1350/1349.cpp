#include <functional>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int maxStudents(vector<vector<char>>& seats)
    {
        int m = seats.size();/*座位的排数*/
        int n = seats[0].size();/*座位的列数*/
        unordered_map<int, int> memo;// 排号|落座情况，对应的最大人数
        // 判断第 row\textit{row}row 排的落座情况是否可能为 status\textit{status}status
        auto isSingleRowCompliant = [&](int status, int row) -> bool {
            for (int j = 0; j < n; j++) {
                if ((status >> j) & 1) {
                    if (seats[row][j] == '#') {// 当前座位损坏
                        return false;
                    }
                    if (j > 0 && ((status >> (j - 1)) & 1)) {// 当前座位的前一个座位有人
                        return false;
                    }
                }
            }
            return true;
        };
        // 当前行与左上右上之间的冲突
        auto isCrossRowsCompliant = [&](int status, int upperRowStatus) -> bool {
            for (int j = 0; j < n; j++) {
                if ((status >> j) & 1) {
                    if (j > 0 && ((upperRowStatus >> (j - 1)) & 1)) {
                        return false;
                    }
                    if (j < n - 1 && ((upperRowStatus >> (j + 1)) & 1)) {
                        return false;
                    }
                }
            }
            return true;
        };
        // 第 row\textit{row}row 排学生落座情况为 status\textit{status}status 时，第 row\textit{row}row 排及其之前所有座位能够容纳最多的学生数
        function<int(int, int)> dp = [&](int row, int status) -> int {
            int key = (row << n) + status;// 排号|落座情况
            if (!memo.count(key)) {
                if (!isSingleRowCompliant(status, row)) {
                    memo[key] = INT_MIN;
                    return INT_MIN;
                }
                int students = __builtin_popcount(status);//当前排的人数
                if (row == 0) {
                    memo[key] = students;
                    return students;
                }
                int mx = 0;
                for (int upperRowStatus = 0; upperRowStatus < 1 << n; upperRowStatus++) {
                    if (isCrossRowsCompliant(status, upperRowStatus)) {
                        mx = max(mx, dp(row - 1, upperRowStatus));
                    }
                }
                memo[key] = students + mx;
            }
            return memo[key];
        };

        int mx = 0;
        for (int i = 0; i < (1 << n); i++) {
            mx = max(mx, dp(m - 1, i));
        }
        return mx;
    }
};