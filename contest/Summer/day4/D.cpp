#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define Maxn 200005
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

class Segtree{
    public:
        long long n;
        long long ans[Maxn * 4];        //树
        long long a[Maxn];              //数据数组
        long long tag[Maxn * 4];        //懒标记

        inline long long left_son(long long p){
            return p << 1;          //p*2
        }

        inline long long right_son(long long p){
            return p << 1 | 1;      //p * 2 + 1
        }

        inline void upward_update(long long p){         //向上更新
            ans[p] = ans[left_son(p)] + ans[right_son(p)];
        }

        inline void build(long long p , long long l ,long long r){       //建树
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
        inline void tag_update(long long p, long long l,long long r,long long k){
            tag[p] += k;                                //标记这个节点每个子节点均被加k，但未被更新
            ans[p] += k * (r - l + 1);                  //更新该节点结果值
        }
        inline void downward_update(long long p,long long l,long long r){
            long long mid = (l + r) >> 1;
            tag_update(left_son(p),l,mid,tag[p]);       //更新左子节点的tag和值
            tag_update(right_son(p),mid+1,r,tag[p]);    //更新右子节点的tag和值
            tag[p] = 0;                                 //将懒标记清零
        }
        inline void update(long long p,long long l0, long long r0, long long l, long long  r,long long k){
            //l0,r0 为需要更改的区间范围
            //l,r   为当前所在的区间范围
            long long mid = (l + r) >> 1;
            if(l0 <= l && r <= r0){         //范围完全覆盖
                tag_update(p,l,r,k);        
                return;
            }
            downward_update(p,l,r);         //范围未完全覆盖，向下更新
            if(l0 <= mid){
                update(left_son(p),l0,r0,l,mid,k);
            }
            if(r0 > mid){
                update(right_son(p),l0,r0,mid+1,r,k);
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

class Segtree seg;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	for(int i = 1; i<=n ; i++){
		cin>>seg.a[i];
	}
	seg.build(1,1,n);
	for(int i = 0; i< q; i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a == 1){
			seg.update(1,b,b,1,n,c);
		}else{
			cout<<seg.query(b,c,1,n,1)<<endl;
		}
	}
	return 0;
}