#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define Maxn 100000
#define N 100000
#pragma comment(linker, "/STACK:10240000000,10240000000")

using namespace std;

class Segtree{
    public:
        int ans[Maxn * 4];        //树
        int a[Maxn];              //数据数组
        int tag[Maxn * 4];        //懒标记

        inline long long left_son(long long p){
            return p << 1;          //p*2
        }

        inline long long right_son(long long p){
            return p << 1 | 1;      //p * 2 + 1
        }

        inline void upward_update(long long p){         //向上更新
            ans[p] = ans[left_son(p)] + ans[right_son(p)];
        }

        inline void build(long long p, long long l,long long r){       //建树
            tag[p] = 0;                                     //初始化懒标记为0
            if(l == r){                                     //若左标记等于右标记，说明为叶子节点
                ans[p] = a[l];
                return;
            }
            long long mid = (l + r) >> 1;                   //计算中值
            build(left_son(p),l,mid);                       //建左子树
            build(right_son(p), mid+1,r);                   //建右子树
            upward_update(p);                               //更新节点p
        }

        inline void tag_add_update(long long p, long long l,long long r,long long k){
            tag[p] += k;                                //标记这个节点每个子节点均被加k，但未被更新
            ans[p] += k * (r - l + 1);                  //更新该节点结果值
        }

        inline void tag_minus_update(long long p, long long l,long long r,long long k){
            tag[p] -= k;                                //标记这个节点每个子节点均被加k，但未被更新
            ans[p] -= k * (r - l + 1);                  //更新该节点结果值
        }

        inline void downward_update(long long p,long long l,long long r){
            long long mid = (l + r) >> 1;
            tag_add_update(left_son(p),l,mid,tag[p]);       //更新左子节点的tag和值
            tag_add_update(right_son(p),mid+1,r,tag[p]);    //更新右子节点的tag和值
            tag[p] = 0;                                 //将懒标记清零
        }

        inline void add_update(long long p,long long l0, long long r0, long long l, long long  r,long long k){
            //l0,r0 为需要更改的区间范围
            //l,r   为当前所在的区间范围
            long long mid = (l + r) >> 1;
            if(l0 <= l && r <= r0){         //范围完全覆盖
                tag_add_update(p,l,r,k);        
                return;
            }
            downward_update(p,l,r);         //范围未完全覆盖，向下更新
            if(l0 <= mid){
                add_update(left_son(p),l0,r0,l,mid,k);
            }
            if(r0 > mid){
                add_update(right_son(p),l0,r0,mid+1,r,k);
            }
            upward_update(p);
        }

        inline void minus_update(long long p,long long l0, long long r0, long long l, long long  r,long long k){
            //l0,r0 为需要更改的区间范围
            //l,r   为当前所在的区间范围
            long long mid = (l + r) >> 1;
            if(l0 <= l && r <= r0){         //范围完全覆盖
                tag_minus_update(p,l,r,k);
                return;
            }
            downward_update(p,l,r);         //范围未完全覆盖，向下更新
            if(l0 <= mid){
                minus_update(left_son(p),l0,r0,l,mid,k);
            }
            if(r0 > mid){
                minus_update(right_son(p),l0,r0,mid+1,r,k);
            }
            upward_update(p);
        }

        

        long long query(long long l0,long long r0,long long l, long long r,long long p){
            //l0,r0 为需要更改的区间范围
            //l,r   为当前所在的区间范围
            long long mid = (l + r) >> 1;
            long long res = 0;
            if(l0 <= l && r0 >=r){              //若完全覆盖则直接返回节点值
                return ans[p];          
            }
            downward_update(p,l,r);             //向下更新懒标记
            if(l0 <= mid){
                res += query(l0,r0,l,mid,left_son(p));
            }
            if(r0 > mid){
                res += query(l0,r0,mid+1,r,right_son(p));
            }
            return res;
        }

};

struct node{
    long long x1;
    long long y1;
    long long x2;
    long long y2;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;      
    cin>>n;
    Segtree segx;
    Segtree segy;
    segx.build(1,1,N);
    segy.build(1,1,N);
    stack<struct node> st;
    for(int i =0 ; i< n; i++){
        int type;
        cin>>type;
        if(type == 1){
            long long x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            struct node temp;
            temp.x1 = x1;
            temp.x2 = x2;
            temp.y1 = y1;
            temp.y2 = y2;
            st.push(temp);
            segx.add_update(1,min(x1,x2),max(x1,x2),1,N,1);
            segy.add_update(1,min(y1,y2),max(y1,y2),1,N,1);
        }else if(type == 2){
            long long x;
            cin>>x;
            cout<<segx.query(x,x,1,N,1)<<endl;
        }else if(type == 3){
            long long y;
            cin>>y;
            cout<<segy.query(y,y,1,N,1)<<endl;
        }else if(type == 4){
            if(!st.empty()){
                struct node temp = st.top();
                st.pop();
                segx.minus_update(1,min(temp.x1,temp.x2),max(temp.x1,temp.x2),1,N,1);
                segy.minus_update(1,min(temp.y1,temp.y2),max(temp.y1,temp.y2),1,N,1);
            }
        }
    }
    return 0;
}