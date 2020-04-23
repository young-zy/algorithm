#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}

class LRUCache {
private:
    int _capacity;
    unordered_map<int, int> _ma;
    unordered_map<int, list<int>::iterator > _ma2;
    list<int> _li;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if(_ma.count(key)){
            _li.erase(_ma2[key]);
            _li.push_front(key);
            _ma2[key] = _li.begin();
            return _ma[key];
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(_ma2.count(key)){
            _li.erase(_ma2[key]);
        }
        if(_li.size() == _capacity){
            _ma2.erase(_li.back());
            _ma.erase(_li.back());
            _li.pop_back();
        }
        _li.push_front(key);
        _ma2[key] = _li.begin();
        _ma[key] = value;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */