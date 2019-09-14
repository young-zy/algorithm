#include <bits/stdc++.h>
using namespace std;
const int maxn=200010;
int n,q;
string a;

int _lower_bound(string s,char c)
{
 int _l=0,_r=s.size()-1;
 while(_l<=_r)
 {
  int mid=_l+(_r-_l)/2;
  if(s[mid]==c)  return mid;
  else if(s[mid]<c) _l++;
  else _r--;
 }
 return -1;
}

int main()
{
 ios::sync_with_stdio(false);
 cin>>n>>q>>a;
 int l,r;
 while(q--)
 {
  cin>>l>>r;
  string num=a.substr(l-1,r);
        sort(num.begin(),num.end());
        int id0=_lower_bound(num,'0');
        int id1=_lower_bound(num,'1');
        int id2=_lower_bound(num,'2');
     if(num[id0]=='0' && num[id1]=='1' && num[id2]=='2')
     {
      int id8=_lower_bound(num,'8');
      int id9=_lower_bound(num,'9');
      if(id8==-1 && num[id9]==9) cout<<0<<'\n';
      else if(num[id8]=='8' && id9==-1) cout<<-1<<'\n';
   else if(num[id8]=='8' && num[id9]=='9') cout<<id9-id8<<'\n';
   else if(id8==-1 && id9==-1) cout<<-1<<'\n';
  }
  else printf("-1\n");  
 }
 return 0;
}