#include<bits/stdc++.h>

using namespace std;

int main(){
    long t;
    cin>>t;
    getchar();
    for(long i = 0; i< t ; i++){
        string a;
        getline(cin,a);
        int sec = (a[17] - '0')*10 + (a[18]-'0'); 
        int min = (a[14] - '0')*10 + (a[15]-'0');
        int hour = (a[11] - '0')*10 + (a[12]-'0');
        int day = (a[8] - '0')*10 + (a[9]-'0');
        int month = (a[5] - '0')*10 + (a[6]-'0');
        int year = (a[0] - '0')*1000 + (a[1]-'0') * 100 + (a[2] - '0')*10 + (a[3]-'0');
        struct tm t1 = {0};
        struct tm t2 = {0};
        t1.tm_year = year - 1900;
        t1.tm_mon = month;
        t1.tm_mday = day;
        t1.tm_hour = hour;
        t1.tm_min = min;
        t1.tm_sec = sec;
        t2.tm_year = 2050-1900;
        t2.tm_mon = 1;
        t2.tm_mday = 1;
        double time = difftime(mktime(&t2),mktime(&t1));
        long long time2 = (long long)time;
        time2 %= 100;
        cout<<time2<<endl;
        //cout<<(hour* 60 *60 +min*60 +sec) % 100<<endl;
    }
    return 0;
}