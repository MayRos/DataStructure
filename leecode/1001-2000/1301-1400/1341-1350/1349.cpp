#include <functional>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int maxStudents(vector<vector<char>>& seats)
    {
        int m = seats.size();/*��λ������*/
        int n = seats[0].size();/*��λ������*/
        unordered_map<int, int> memo;// �ź�|�����������Ӧ���������
        // �жϵ� row\textit{row}row �ŵ���������Ƿ����Ϊ status\textit{status}status
        auto isSingleRowCompliant = [&](int status, int row) -> bool {
            for (int j = 0; j < n; j++) {
                if ((status >> j) & 1) {
                    if (seats[row][j] == '#') {// ��ǰ��λ��
                        return false;
                    }
                    if (j > 0 && ((status >> (j - 1)) & 1)) {// ��ǰ��λ��ǰһ����λ����
                        return false;
                    }
                }
            }
            return true;
        };
        // ��ǰ������������֮��ĳ�ͻ
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
        // �� row\textit{row}row ��ѧ���������Ϊ status\textit{status}status ʱ���� row\textit{row}row �ż���֮ǰ������λ�ܹ���������ѧ����
        function<int(int, int)> dp = [&](int row, int status) -> int {
            int key = (row << n) + status;// �ź�|�������
            if (!memo.count(key)) {
                if (!isSingleRowCompliant(status, row)) {
                    memo[key] = INT_MIN;
                    return INT_MIN;
                }
                int students = __builtin_popcount(status);//��ǰ�ŵ�����
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