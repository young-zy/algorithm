#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int 
int arr[27][100005];
int main()
{
    
    ll n;
    ll c=0;
    cin>>n;
    if(n<10)
    {
        cout<<"9";
        return 0;
    }
    while(n!=1)
    {
        c++;
        n=n+1;
        while(n%10==0)
        {
            n=n/10;
        }
    }
    cout<<c+1;
    return 0;
}