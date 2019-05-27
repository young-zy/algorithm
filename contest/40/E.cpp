#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define Maxn 200005

using namespace std;

class Segtree{
    public:
        long long n;
        long long ans[Maxn * 4];        //?
        long long a[Maxn];              //????
        long long tag[Maxn * 4];        //???

        inline long long left_son(long long p){
            return p << 1;          //p*2
        }

        inline long long right_son(long long p){
            return p << 1 | 1;      //p * 2 + 1
        }

        inline void upward_update(long long p){         //????
            ans[p] = ans[left_son(p)] + ans[right_son(p)];
        }

        inline void build(long long p, long long l,long long r){       //??
            tag[p] = 0;                                     //???????0
            if(l == r){                                     //?????????????????
                ans[p] = a[l];
                return;
            }
            long long mid = (l + r) >> 1;                   //????
            build(left_son(p),l,mid);                       //????
            build(right_son(p), mid+1,r);                   //????
            upward_update(p);                               //????p
        }
        inline void tag_update(long long p, long long l,long long r,long long k){
            tag[p] += k;                                //??????????????k??????
            ans[p] += k * (r - l + 1);                  //????????
        }
        inline void downward_update(long long p,long long l,long long r){
            long long mid = (l + r) >> 1;
            tag_update(left_son(p),l,mid,tag[p]);       //???????tag??
            tag_update(right_son(p),mid+1,r,tag[p]);    //???????tag??
            tag[p] = 0;                                 //??????
        }
        inline void update(long long p,long long l0, long long r0, long long l, long long  r,long long k){
            //l0,r0 ??????????
            //l,r   ??????????
            long long mid = (l + r) >> 1;
            if(l0 <= l && r <= r0){         //??????
                tag_update(p,l,r,k);        
                return;
            }
            downward_update(p,l,r);         //????????????
            if(l0 <= mid){
                update(left_son(p),l0,r0,l,mid,k);
            }
            if(r0 > mid){
                update(right_son(p),l0,r0,mid+1,r,k);
            }
            upward_update(p);
        }

        long long query(long long l0,long long r0,long long l, long long r,long long p){
            //l0,r0 ??????????
            //l,r   ??????????
            long long mid = (l + r) >> 1;
            long long res = 0;
            if(l0 <= l && r0 >=r){              //?????????????
                return ans[p];          
            }
            downward_update(p,l,r);             //???????
            if(l0 <= mid){
                res += query(l0,r0,l,mid,left_son(p));
            }
            if(r0 > mid){
                res += query(l0,r0,mid+1,r,right_son(p));
            }
            return res;
        }

};

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    return 0;
}