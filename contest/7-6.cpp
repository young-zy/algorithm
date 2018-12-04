#include<bits/stdc++.h>

using namespace std;

int main(){
    set<unsigned int> s;
    priority_queue<unsigned int,deque<unsigned int>,greater<unsigned int>> pq;
    s.insert(1);
    pq.push(1);
    while(1){
        int num;
        int flag = 0;
        char ch[4][3] = {"th","st","nd","rd"};
        scanf("%d",&num);
        if(num == 0){
            break;
        }
        flag = num % 10;
        if(flag > 3){
            flag = 0;
        }
        if(num /10 %10 == 1 && flag != 0){
            flag = 0;
        }
        unsigned int temp = 0;
        while(s.size()<(unsigned int)num){
            unsigned int a = pq.top();
            pq.pop();
            if(a == temp){
                continue;   
            }
            s.insert(a);
            pq.push(a*2);
            pq.push(a*3);
            pq.push(a*5);
            pq.push(a*7);
            temp = a;
        }
        set<unsigned int>::iterator it = s.begin();
        for(int i =1; i< num;i++){
            it++;
        }
        printf("The %d%s humble number is %u.",num,ch[flag],*it);
        //cout<<"The "<<num<<ch[flag]<<" humble number is "<<*it<<"."<<endl;
    }
    return 0;
}