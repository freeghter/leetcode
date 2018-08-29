//
// Created by ft on 2018/8/29.
//
/**
 * 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 你可以对一个单词进行如下三种操作：
 * 1.插入一个字符
 * 2.删除一个字符
 * 3.替换一个字符
 *
 * 输入: word1 = "horse", word2 = "ros"
 * 输出: 3
 * 解释:
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 */
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty())
            return word2.size();
        if(word2.empty())
            return word1.size();
        // word1.size()行 word2.size()列
        vector<vector<int> > dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for(int i=0; i<=word2.size(); i++)
            dp[0][i] = i;
        for(int i=0; i<=word1.size(); i++)
            dp[i][0] = i;

        for(int i=1; i <= word1.size(); i++){
            for(int j=1; j <= word2.size(); j++){
                int min = dp[i-1][j] > dp[i][j-1] ? dp[i][j-1] + 1 : dp[i-1][j] + 1;
                int t = word1[i-1] == word2[j-1] ? dp[i-1][j-1] : dp[i-1][j-1] + 1;
                min = min < t ? min : t;
                dp[i][j]=min;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main(int argc, char * argv[]){
    Solution s;
    string s1 = "pneumonoultramicroscopicsilicovolcanoconiosis";
    string s2 = "ultramicroscopically";
    int r = s.minDistance(s1, s2);
    cout << r << endl;
    return 0;
}