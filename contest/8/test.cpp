#include <bits/stdc++.h>

using namespace std;

int zhao(set<int> s,int n)
{
    set<int>::iterator it;
    it=s.begin();
    int shu=0;
    while(shu!=n)
    {
        it++;
        shu++;
    }
    return (*it);
}

int main()
{
    int n;
    int jishu=1;
    set<int> s;
    s.insert(1);
    cout<<*(s.begin())<<endl;
    set<int>::iterator it;
    it=s.begin();
    while(s.size()<6000)
    {
        s.insert(2*(*it));
        s.insert(3*(*it));
        s.insert(5*(*it));
        s.insert(7*(*it));
        cout<<*it<<endl;
        it++;
    }
    it = s.begin();
    cout<<*(s.begin())<<endl;
    while(cin>>n)
    {
        if(n==0)
            break;
        else if(n%10==1)
            printf("The %dst humble number is %d\n",n,zhao(s,n));
        else if(n%10==2)
            printf("The %dnd humble number is %d\n",n,zhao(s,n));
        else if(n%10==3)
            printf("The %drd humble number is %d\n",n,zhao(s,n));
        else
            printf("The %dth humble number is %d\n",n,zhao(s,n));
    }
    return 0;
}