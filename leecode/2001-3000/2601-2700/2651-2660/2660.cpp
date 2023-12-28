#include <vector>
using namespace std;
class Solution
{
public:
    int isWinner(vector<int>& player1, vector<int>& player2)
    {
        int score_1 = 0;
        int score_2 = 0;
        for (int i = 0; i < player1.size(); i++) {
            if ((i >= 1 && player1[i - 1] == 10 )|| (i >= 2 && player1[i - 2] == 10)) {
                score_1 += player1[i] * 2;
            }
            else {
                score_1 += player1[i];
            }
            if ((i >= 1 && player2[i - 1] == 10) || (i >= 2 && player2[i - 2] == 10)) {
                score_2 += player2[i] * 2;
            }
            else {
                score_2 += player2[i];
            }
        }
        if (score_1 > score_2) {
            return 1;
        }
        else if (score_1 < score_2) {
            return 2;
        }
        return 0;
    }
};
int main()
{
    vector<int> player1 = {10,2,2,3};
    vector<int> player2 = {3,8,4,5};
    Solution s;
    s.isWinner(player1, player2);
}