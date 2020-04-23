#include <iostream>

#include <cmath>

using namespace std;



int main()

{

    int a1,a2,a3,a4,a5,a6;

    int L,R,count=0;;

    cin>>L>>R;

    for(a1=0;a1<=2;a1++)

     for(a2=0;a2<=2;a2++)

      for(a3=0;a3<=2;a3++)

       for(a4=0;a4<=2;a4++)

        for(a5=0;a5<=2;a5++)

         for(a6=0;a6<=2;a6++)

         {

         int sum=a1+a2+a3+a4+a5+a6;

if(sum>=L && sum<=R || sum==2 || sum==3 || sum==5 || sum==7 || sum==11) count++;

         }

         cout<<count;

return 0;

}