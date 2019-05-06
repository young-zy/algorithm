#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main(){
    int n;
    cin >> n;
    deque<int> a(n, 0);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<char> moves;
    int last = 0;
    if( a[0] < a[a.size() -1]){
        moves.push_back('L');
        last = a.front();
        a.pop_front();
    }
    else{
        moves.push_back('R');
        last = a.back();
        a.pop_back();
    }
    while( a.size() > 0){
        int front = a.front();
        int back = a.back();        
        // cout << "front " << front << " back " << back << " last " << last <<  endl;
        if( front <= last && back <= last) break;
        else if ( front == back && front <= last) break;
        else if (front == back && front > last){
            int left_count = 0;
            int right_count = 0;
            for(int i = 1; i< a.size(); ++i){
                if ( a[i-1] < a[i]) ++left_count;
            }
            for(int i= a.size()-2; i>= 0; --i){
                if ( a[i] > a[i+1]) ++right_count;
            }
            // cout << "leftcount " << left_count << " rightcount "<< right_count << endl;
            if (left_count >= right_count){
                moves.push_back('L');
                last = front;
                a.pop_front();
            }
            else{
                moves.push_back('R');
                last = back;
                a.pop_back();
            }
        }
        else if ( front <= last){
            if ( back > last){
                moves.push_back('R');
                last = back;
                a.pop_back();
            }
            else{
                break;
            }

        }
        else if ( back <= last){
            if ( front > last){
                moves.push_back('L');
                last = front;
                a.pop_front();
            }
            else{
                break;
            }

        }
        else{
            int min = front;
            if ( back < front) min = back;
            if (min == front){
                moves.push_back('L');
                last = front;
                a.pop_front();
            }
            else{
                moves.push_back('R');
                last = back;
                a.pop_back();
            }
        }
    }
    cout << moves.size() << endl;
    for(int i=0;i<moves.size();++i){
        cout << moves[i] ;
    }
    cout << endl;
    
}