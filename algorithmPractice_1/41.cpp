#include<bits/stdc++.h>

using namespace std;

int main(){
    int num;
    scanf("%d",&num);
    int data[num];
    for(int i =0;i<num;i++){
        scanf("%d",&data[i]);
    }
    for(int i = 0; i < num-1;i++){
        int max = data[i];
        for(int j = i+1;j<num;j++){
            if(data[j] > max){
                int temp = max;
                max = data[j];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    for(int i =0;i<num;i++){
        if(i!=0){
            printf(" ");
        }
        printf("%d",data[i]);
    }
    system("pause");
    return 0;
}