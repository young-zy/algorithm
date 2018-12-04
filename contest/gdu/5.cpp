#include<bits/stdc++.h>

using namespace std;

struct node{
    string number;
    int num;
};

bool cmp(struct node a,struct node b);

int main(){
    int n;
    while(~scanf("%d",&n)){
        string a;
        map<string,int> m;
        for(int i = 0; i < n; i++){
            cin>>a;
            string result;
            int c = 0;
            for(int j = 0 ; j<a.length();j++){
                if(a[j] == 'A' || a[j] == 'B' || a[j] == 'C'){
                    result.append(1,'2');
                }else
                if(a[j] == 'D' || a[j] == 'E' || a[j] == 'F'){
                    result.append(1,'3');
                }else
                if(a[j] == 'G' || a[j] == 'H' || a[j] == 'I'){
                    result.append(1,'4');
                }else
                if(a[j] == 'J' || a[j] == 'K' || a[j] == 'L'){
                    result.append(1,'5');
                }else
                if(a[j] == 'M' || a[j] == 'N' || a[j] == 'O'){
                    result.append(1,'6');
                }else
                if(a[j] == 'P' || a[j] == 'R' || a[j] == 'S'){
                    result.append(1,'7');
                }else
                if(a[j] == 'T' || a[j] == 'U' || a[j] == 'V'){
                    result.append(1,'8');
                }else
                if(a[j] == 'W' || a[j] == 'X' || a[j] == 'Y'){
                    result.append(1,'9');
                }else if(a[j] == '-'){
                    continue;
                }else{
                    result.append(1,a[j]);
                }
                if(c == 2){
                    result.append(1,'-');
                }
                c++;
            }
            m[result]++;
        }
        map<string,int>::iterator it;
        int count = 0;
        struct node no[m.size()];
        for(it = m.begin();it!=m.end();it++){
            if(it->second > 1){
                no[count].number = it->first;
                no[count].num = it->second;
                count++;
            }
        }
        if(count == 0){
            cout<<"No duplicates.\n";
        }else{
            sort(no,no+count,cmp);
        }
        for(int i = 0;i<count;i++){
            cout<<no[i].number<<" "<<no[i].num<<endl;
        }
    }
    return 0;
}

bool cmp(struct node a,struct node b){
    return a.number < b.number;
}