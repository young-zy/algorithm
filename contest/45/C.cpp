#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
//#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

int a[500005];

int n,m;

int count2 = 0;
int count3 = 0;

struct node {
    int index;
    int last;
};

int ma[500005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<m; j++){
            cin>>a[i*m+j +1];
            ma[i*m+j +1] += a[i*m+j +1];
        }
    }
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<m; j++){
            if(a[i*m+j + 1] == 0){
                stack<struct node> st;
                struct node no;
                no.index = i*m+j + 1;
                no.last = 3;
                st.push(no);
                ma[i*m+j+1]++;
                while(!st.empty()){
                    struct node temp = st.top();
                    st.pop();
                    int index = temp.index;
                    int last = temp.last;
                    if(last == 2){
                        a[index] = 3;
                        last = 3;
                        count3++;
                    }else{
                        a[index] = 2;
                        last = 2;
                        count2++;
                    }
                    struct node newnode;
                    if(index > m && ma[index-m] == 0){
                        newnode.last = last;
                        newnode.index = index - m;
                        st.push(newnode);
                        ma[index-m]++;
                    }
                    if(index % m != 1 && ma[index -1] == 0){
                        newnode.last = last;
                        newnode.index = index - 1;
                        st.push(newnode);
                        ma[index-1]++;
                    }
                    if(index % m != 0 && ma[index +1] == 0){
                        newnode.last = last;
                        newnode.index = index + 1;
                        st.push(newnode);
                        ma[index+1]++;
                    }
                    if(index <= n*(m-1) && ma[index + m] == 0){
                        newnode.last = last;
                        newnode.index = index + m;
                        st.push(newnode);
                        ma[index+m]++;
                    }
                }
            }
        }
    }
    if(count2 == count3){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}