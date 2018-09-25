//
// Created by ft on 2018/9/4.
//
/**
 * 实现一个基本的计算器来计算一个简单的字符串表达式的值。
 * 字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格。
 *
 * 示例 1:
 * 输入: "1 + 1"
 * 输出: 2
 *
 * 示例 2:
 * 输入: " 2-1 + 2 "
 * 输出: 3
 *
 * 示例 3:
 * 输入: "(1+(4+5+2)-3)+(6+8)"
 * 输出: 23
 */

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<string> st;
        queue<string> q;

        trim(s);

        string t;
        q.push("(");
        for(auto c: s){
            if(isdigit(c))
                t+=c;
            if(c == '+' || c == '-' || c=='(' || c==')'){
                if(!t.empty()){
                    q.push(t);
                    t.clear();
                }
                q.push(string(1, c));
            }
        }
        if(!t.empty())
            q.push(t);
        q.push(")");

        while (!q.empty()){
            string t = q.front();
            q.pop();
            if(t != ")")
                st.push(t);
            else{
                string i;
                stringstream ss;
                int sum = 0;
                do{
                    int t;
                    ss.clear();
                    ss << st.top(); st.pop();
                    ss >> t;
                    i = st.top(); st.pop();
                    if(i == "-")
                        t = -t;
                    sum += t;
                }while(i != "(");
                st.push(to_string(sum));
            }
        }
        stringstream ss(st.top());
        int r;
        ss >> r;
        return r;
    }

private:
    void trim(string &s){
        decltype(s.size()) index = 0;
        if( !s.empty())
        {
            while( (index = s.find(' ',index)) != string::npos)
            {
                s.erase(index,1);
            }
        }
    }
};

int main(int argc, char * argv[]){

    vector<pair<string, int>> test_cases={
            {"1 + 1", 2},
            {" 2-1 + 2 ", 3},
            {"(1+(4+5+2)-3)+(6+8)", 23}
    };

    Solution s;
    for (auto p: test_cases){
        if(s.calculate(p.first) == p.second){
            cout << "true: " << p.first << ": " << p.second << endl;
        } else
            cout << "false: " << p.first << ": " << p.second << endl;
    }

    return 0;
}
