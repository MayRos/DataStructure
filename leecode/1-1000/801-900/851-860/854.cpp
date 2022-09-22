/*
对于某些非负整数 k ，如果交换 s1 中两个字母的位置恰好 k 次，能够使结果字符串等于 s2 ，则认为字符串 s1 和 s2 的 相似度为 k 。

给你两个字母异位词 s1 和 s2 ，返回 s1 和 s2 的相似度 k 的最小值。

 

示例 1：

输入：s1 = "ab", s2 = "ba"
输出：1
示例 2：

输入：s1 = "abc", s2 = "bca"
输出：2
 

提示：

1 <= s1.length <= 20
s2.length == s1.length
s1 和 s2  只包含集合 {'a', 'b', 'c', 'd', 'e', 'f'} 中的小写字母
s2 是 s1 的一个字母异位词
*/
#include <string>
using namespace std;
class Solution {
public:
    int kSimilarity(string s1, string s2) {
		int equal_num = 0;
		int not_equal_num = 0;

		int first = -1;
		int second = -1;
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] == s2[i])
			{
				equal_num++;
			}
			else
			{
				not_equal_num++;
				if (not_equal_num % 2) {
					int temp = s1[first];
					s1[first] = s1[second];
					s1[second] = temp;
					if(s1[second])
				}
			}
		}
    }
};