//
// Created by ft on 2018/9/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char * argv[]){
    vector<int> v={2, 3, 8, -2, 0};

    // 求vector中的最小值
    auto m = min_element(v.begin(), v.end());
    cout << *m << endl;

    // 求vector中的最大值
    m = max_element(v.begin(), v.end());
    cout << *m << endl;
    return 0;
}