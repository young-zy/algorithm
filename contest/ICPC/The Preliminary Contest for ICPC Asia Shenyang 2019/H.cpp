#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f

using namespace std;

struct node{
    string name;
    string card;
    int state = INF;//0: Royal Straight. 
                    //1: Straight.
                    //2: Four of a kind.
                    //3: Full House.
                    //4: Three of a Kind.
                    //5: Two Pairs.
                    //6: Pair.
                    //7: High Card.
    int head1 = 0;
    int head2 = 0;
    int head3 = 0;
    bool operator < (node n) const{
        if(card == n.card){
            return name < n.name;
        }
        if(state == n.state){
            if(state == 7){
                if(head3 == n.head3){
                    return name < n.name;
                }
                return head3 >n.head3;
            }else if(state == 6){
                if(head1 == n.head1){
                    if(head3 == n.head3){
                        return name < n.name;
                    }
                    return head3 > n.head3;
                }
                return head1 > n.head1;
            }else{
                if(head1 == n.head1){
                    if(head2 == n.head2){
                        if(head3 == n.head3){
                            return name < n.name;
                        }
                        return head3 > n.head3;
                    }
                    return head2 > n.head2;
                }
                return head1 > n.head1;
            }
        }
        return state < n.state;
    }
};

char check_straight(string card){
    int flag = 1;
    int ma[14];
    for(int i = 0; i<card.length();i++){
        if(card[i] == 'J'){
            ma[11]++;
        }else if(card[i] == 'Q'){
            ma[12]++;
        }else if(card[i] == 'K'){
            ma[13]++;
        }else if(card[i] == '0'){
            ma[10]++;
        }else{
            ma[card[i]-'0']++;
        }
    }
    for(int i = 1; i<14 ; i++){
        
    }
    if(flag == 1){
        return card[0];
    }else{
        return 'n';
    }
}



node no[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n){
    for(int i = 0; i<n ; i++){
        cin>>no[i].name>>no[i].card;
        while(no[i].card.find("10") != string::npos){
            no[i].card.erase(no[i].card.find("10"),1);
        }
        while(no[i].card.find("A") != string::npos){
            no[i].card.insert(no[i].card.find("A"),"1");
            no[i].card.erase(no[i].card.find("A"),1);
        }
        sort(no[i].card.begin(),no[i].card.end());
        if(no[i].card.find("01JKQ") != string::npos){
            no[i].state = 0;
        }else{
            char ch = check_straight(no[i].card);
            if(ch != 'n'){
                no[i].state = 1;
                no[i].head1 = ch;
                if(no[i].head1 == 'J'){
                    no[i].head1 = 11;
                }else if(no[i].head1 == 'Q'){
                    no[i].head1 = 12;
                }else if(no[i].head1 == 'K'){
                    no[i].head1 = 13;
                }else if(no[i].head1 == '0'){
                    no[i].head1 = 10;
                }else{
                    no[i].head1 -= '0';
                }
            }else{
                map<char,int> ma;
                for(int j = 0; j< no[i].card.length();j++){
                    ma[no[i].card[j]]++;
                }
                for(auto it:ma){
                    if(it.second == 4){
                        no[i].state = 2;
                        no[i].head1 = it.first;
                        if(no[i].head1 == 'J'){
                            no[i].head1 = 11;
                        }else if(no[i].head1 == 'Q'){
                            no[i].head1 = 12;
                        }else if(no[i].head1 == 'K'){
                            no[i].head1 = 13;
                        }else if(no[i].head1 == '0'){
                            no[i].head1 = 10;
                        }else{
                            no[i].head1 -= '0';
                        }
                        if(it == *ma.begin()){
                            no[i].head2 = ma.rbegin()->first;
                        }else{
                            no[i].head2 = ma.begin()->first;
                        }
                        if(no[i].head2 == 'J'){
                            no[i].head2 = 11;
                        }else if(no[i].head2 == 'Q'){
                            no[i].head2 = 12;
                        }else if(no[i].head2 == 'K'){
                            no[i].head2 = 13;
                        }else if(no[i].head2 == '0'){
                            no[i].head2 = 10;
                        }else{
                            no[i].head2 -= '0';
                        }
                    }
                    if(it.second == 3){
                        no[i].head1 = it.first;
                        if(no[i].head1 == 'J'){
                            no[i].head1 = 11;
                        }else if(no[i].head1 == 'Q'){
                            no[i].head1 = 12;
                        }else if(no[i].head1 == 'K'){
                            no[i].head1 = 13;
                        }else if(no[i].head1 == '0'){
                            no[i].head1 = 10;
                        }else{
                            no[i].head1 -= '0';
                        }
                        int flag = 0;
                        int sum = 0;
                        for(auto _it:ma){
                            if(_it.second == 2){
                                flag =1;
                                no[i].head2 = _it.first;
                                if(no[i].head2 == 'J'){
                                    no[i].head2 = 11;
                                }else if(no[i].head2 == 'Q'){
                                    no[i].head2 = 12;
                                }else if(no[i].head2 == 'K'){
                                    no[i].head2 = 13;
                                }else if(no[i].head2 == '0'){
                                    no[i].head2 = 10;
                                }else{
                                    no[i].head2 -= '0';
                                }
                                no[i].state = 3;
                                break;
                            }else if(_it.second == 1){
                                if(_it.first == 'J'){
                                    sum += 11;
                                }else if(_it.first == 'Q'){
                                    sum += 12;
                                }else if(_it.first == 'K'){
                                    sum += 13;
                                }else if(_it.first == '0'){
                                    sum += 10;
                                }else{
                                    sum += _it.first-'0';
                                }
                            }
                        }
                        if(flag == 0){
                            no[i].state = 4;
                            no[i].head2 = sum;
                        }
                        break;
                    }
                }
                if(no[i].state == INF){
                    int count = 0;
                    int sum = 0;
                    for(auto it = ma.rbegin();it != ma.rend();it++){
                        if(it->second == 2){
                            count++;
                            if(count == 1){
                                no[i].head1 = it->first;
                            }else{
                                no[i].head2 = it->first;
                            }
                        }else{
                            if(it->first == 'J'){
                                sum += 11;
                            }else if(it->first == 'Q'){
                                sum += 12;
                            }else if(it->first == 'K'){
                                sum += 13;
                            }else if(it->first == '0'){
                                sum += 10;
                            }else{
                                sum += it->first-'0';
                            }
                        }
                    }
                    if(no[i].head1 == 'J'){
                        no[i].head1 = 11;
                    }else if(no[i].head1 == 'Q'){
                        no[i].head1 = 12;
                    }else if(no[i].head1 == 'K'){
                        no[i].head1 = 13;
                    }else if(no[i].head1 == '0'){
                        no[i].head1 = 10;
                    }else{
                        no[i].head1 -= '0';
                    }
                    if(no[i].head2 == 'J'){
                        no[i].head2 = 11;
                    }else if(no[i].head2 == 'Q'){
                        no[i].head2 = 12;
                    }else if(no[i].head2 == 'K'){
                        no[i].head2 = 13;
                    }else if(no[i].head2 == '0'){
                        no[i].head2 = 10;
                    }else{
                        no[i].head2 -= '0';
                    }
                    no[i].head3 = sum;
                    if(count == 0){
                        no[i].state = 7;
                    }else if(count == 1){
                        no[i].state = 6;
                    }else{
                        no[i].state = 5;
                    }
                }
            }
        }
    }
    sort(no,no+n);
    for(int i = 0; i<n ; i++){
        cout<<no[i].name<<endl;
    }
    }
    return 0;
}

/*
15
a A2345
b 10JQKA
aa 23456
bb 910JQK
c 22345
d 22334
e 22335
f 22446
ff 33446
g 33345
h 33355
hh 33366
hhh 44411
i 33356
j 44441
k 4444K

*/