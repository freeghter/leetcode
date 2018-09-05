//
// Created by ft on 2018/8/30.
//
/**
 * 现在你总共有 n 门课需要选，记为 0 到 n-1。
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
 * 给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？
 *
 * 输入: 2, [[1,0]]
 * 输出: true
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
 *
 * 输入: 2, [[1,0],[0,1]]
 * 输出: false
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。
 * 这是不可能的。
 *
 * 说明:
 * 输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
 * 你可以假定输入的先决条件中没有重复的边。
 * 提示:
 * 这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
 * 通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
 * 拓扑排序也可以通过 BFS 完成。
 */
#include <iostream>
#include <stack>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> v(numCourses, 0);
        map<int, vector<int>> m;

        // 构建图
        for (auto p: prerequisites){
            v[p.second]++;
            if(m.count(p.first) < 1)
                m[p.first] = vector<int>();
            if(m.count(p.second) < 1)
                m[p.second] = vector<int>(0);
            m[p.first].push_back(p.second);
        }

        stack<int> s;
        // 入度为0的节点入栈
        for (int i = 0; i < numCourses; ++i) {
            if(v[i] == 0)
                s.push(i);
        }

        while (!s.empty()){
            auto p = s.top();
            s.pop();
            if(m.count(p)){ // 从map里面移除并删除边
                for (int i:m[p]){
                    --v[i];
                    if(v[i] == 0)
                        s.push(i);
                }
                m.erase(p);
            }
        }
        return m.empty();
    }
};

int main(int argc, char * argv[]){
    Solution s;
    vector<pair<int,int>> v={{0,1},{0,2},{1,2}};
    bool r = s.canFinish(3,v);
    if(r)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
