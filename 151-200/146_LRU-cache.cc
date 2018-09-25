//
// Created by ft on 2018/9/4.
//
/**
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。
 * 它应该支持以下操作： 获取数据 get 和 写入数据 put 。
 * 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
 * 写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。
 * 当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。
 *
 * 进阶:
 * 你是否可以在 O(1) 时间复杂度内完成这两种操作？
 *
 * 示例:
 * LRUCache cache = new LRUCache( 2  缓存容量 )
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // 返回  1
 * cache.put(3, 3);    // 该操作会使得密钥 2 作废
 * cache.get(2);       // 返回 -1 (未找到)
 * cache.put(4, 4);    // 该操作会使得密钥 1 作废
 * cache.get(1);       // 返回 -1 (未找到)
 * cache.get(3);       // 返回  3
 * cache.get(4);       // 返回  4
 */
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        int r = -1;
        if(m.count(key) == 0)
            return r;

        auto itr = m[key];
        r = (*itr).second;
        l.push_front(*itr);
        m[key] = l.begin();
        l.erase(itr);

        return r;
    }

    void put(int key, int value) {
        if(m.count(key)){
            (*m[key]).second = value;
            l.push_front(*m[key]);
            l.erase(m[key]);
            m[key] = l.begin();
            return;
        }

        if(capacity > m.size()){
            l.emplace_front(key, value);
            m[key] = l.begin();
            return;
        }

        auto itr = --l.end();
        m.erase((*itr).first);
        l.erase(itr);
        l.emplace_front(key, value);
        m[key] = l.begin();
    }

private:
    int capacity;
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(int argc, char * argv[]){
    LRUCache cache(2);

    int val;

    cache.put(2, 1);
    cache.put(1, 1);
    cache.put(2, 3);
    cache.put(4, 1);
    val = cache.get(1);
    cout << val << endl;
    val = cache.get(2);
    cout << val << endl;
    return 0;
}