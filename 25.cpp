#include<bits/stdc++.h>

using namespace std;

//int fastsort(struct node * a, int left, int pivot, int type);
//int exchange(struct node * a,struct node * b);

bool cmp(struct node a, struct node b);

struct data{
    int num;
    int value;
    int rnum;
};

struct node {
    struct data * data; 
};

int main(){
    int num;
    scanf("%d",&num);
    struct node people[num];
    for(int i = 0; i< num ; i++){
        people[i].data = (struct data *)malloc(sizeof(struct data));
        people[i].data -> value = 0; 
        people[i].data -> rnum = 0;
    }
    for(int i = 0;i < num; i++){
        int rnum;
        scanf("%d",&rnum);
        people[i].data -> num = i + 1;
        int sum = 0;
        for(int j = 0; j < rnum; j++){
            int N,P;
            scanf("%d %d", &N, &P);
            people[N-1].data -> value += P;
            people[N-1].data -> rnum ++;
            sum += P;
        }
        people[i].data -> value -= sum;
    }
    
    sort(people,people + num,cmp);




    for(int i = 0; i < num; i++){
        printf("%d %.2f\n",people[i].data -> num, (float)people[i].data -> value / 100);
    }
    system("pause");
    return 0;
}

bool cmp(struct node a, struct node b){
    if(a.data->value != b.data->value){
        return a.data->value > b.data->value;
    }
    if(a.data->rnum != b.data->rnum){
        return a.data->rnum > b.data->rnum;
    }
    return a.data->num < b.data->num;
}

/*

int fastsort(struct node * a, int left, int pivot, int type){
    if(type == 1){
        int right = pivot - 1;
        for(int i = left;i <= pivot; i++){
            if(a[i].data -> value < a[pivot].data -> value){
                for(int j = right; j >= left ; j--){
                    if(a[j].data -> value > a[pivot].data -> value){
                        exchange(&a[i], &a[j]);
                        continue;       
                    }
                    if(i == j){
                        exchange(&a[i], &a[pivot]);
                        fastsort(a, left, i - 1, type);
                        fastsort(a, i + 1, right, type);
                    }
                }
            }
            if(i == pivot){
                fastsort(a, left, i - 1, type);
            }
        }
    }else if(type == 2){
        int right = pivot - 1;
        for(int i = left;i <= pivot; i++){
            if(a[i].data -> rnum > a[pivot].data -> rnum){
                for(int j = right; j >= left ; j--){
                    if(a[j].data -> rnum < a[pivot].data -> rnum){
                        exchange(&a[i], &a[j]);
                        continue;       
                    }
                    if(i == j){
                        exchange(&a[i], &a[pivot]);
                        fastsort(a, left, i - 1, type);
                        fastsort(a, i + 1, right, type);
                    }
                }
            }
            if(i == pivot){
                fastsort(a, left, i - 1, type);
            }
        }
    }else{
        int right = pivot - 1;
        for(int i = left;i <= pivot; i++){
            if(a[i].data -> num > a[pivot].data -> num){
                for(int j = right; j >= left ; j--){
                    if(a[j].data -> num < a[pivot].data -> num){
                        exchange(&a[i], &a[j]);
                        continue;       
                    }
                    if(i == j){
                        exchange(&a[i], &a[pivot]);
                        fastsort(a, left, i - 1, type);
                        fastsort(a, i + 1, right, type);
                    }
                }
            }
            if(i == pivot){
                fastsort(a, left, i - 1, type);
            }
        }
    }
}

int exchange(struct node * a,struct node * b){
    struct data * temp;
    temp = a -> data;
    a -> data = b -> data;
    b -> data = temp;
    return 0;
}
*/