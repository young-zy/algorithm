#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

int a[100005],f[100005];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=0x7fffffff;
        //初始值要设为INF
        /*原因很简单，每遇到一个新的元素时，就跟已经记录的f数组当前所记录的最长
        上升子序列的末尾元素相比较：如果小于此元素，那么就不断向前找，直到找到
        一个刚好比它大的元素，替换；反之如果大于，么填到末尾元素的下一个q，INF
                就是为了方便向后替换啊！*/ 
    }
    f[1]=a[1];
    int len=1;//通过记录f数组的有效位数，求得个数 
    /*因为上文中所提到我们有可能要不断向前寻找，
    所以可以采用二分查找的策略，这便是将时间复杂
    度降成nlogn级别的关键因素。*/ 
    for(int i=2;i<=n;i++){
        int l=0,r=len,mid;
        if(a[i]>f[len]){
            f[++len]=a[i];
        //如果刚好大于末尾，暂时向后顺次填充 
        } else {
        while(l<r){   
            mid=(l+r)/2;
            if(f[mid]>a[i]) r=mid;
            //如果仍然小于之前所记录的最小末尾，那么不断
            //向前寻找(因为是最长上升子序列，所以f数组必
            //然满足单调) 
            else l=mid+1; 
        }
        f[l]=min(a[i],f[l]);//更新最小末尾 
        }
    }
    cout<<len;
    return 0;
}
    