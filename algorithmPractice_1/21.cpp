#include<bits/stdc++.h>


using namespace std;

struct node{
    struct data * data;
};

struct data{
    int stunum;
    char name[9];
    int score;
};

bool cmpscore(node a, node b);

bool cmpstunum(node a, node b);

bool cmpname(node a, node b);

//int fastsort(struct node * a, int left, int right,int type);

// int exchange(struct node * a,struct node * b);

int main(){
    int N,C;
    scanf("%d %d",&N,&C);
    node a[N];
    for(int i = 0; i < N; i++){
        a[i].data = (struct data *)malloc(sizeof(struct data));
        scanf("%d",&a[i].data -> stunum);
        scanf("%s",&a[i].data -> name);
        scanf("%d",&a[i].data -> score);
    }
    if(C == 1){
        sort(a,&a[N],cmpstunum);
    }else if(C == 2){
        sort(a,&a[N],cmpname);
    }else{
        sort(a,&a[N],cmpscore);
    }
    
    for(int i = 0; i<N; i++){
        printf("%.6d ",a[i].data -> stunum);
        printf("%s ",a[i].data -> name);
        printf("%d",a[i].data -> score);
        if(i != N-1){
            printf("\n");
        }
    }
    system("pause");
    return 0;
}

bool cmpscore(node a, node b){ 
    if (a.data->score != b.data->score) {
        return a.data->score < b.data->score; 
    }
    return a.data -> stunum < b.data->stunum;
}

bool cmpstunum(node a, node b){ 
    return a.data -> stunum < b.data->stunum;
}

bool cmpname(node a, node b){ 
    if(strcmp(a.data -> name , b.data->name)){
        return (strcmp(a.data -> name , b.data->name) < 0);
    }
    return a.data -> stunum < b.data->stunum;
}


// int exchange(struct node * a,struct node * b){
//     struct data * temp;
//     temp = a -> data;
//     a -> data = b -> data;
//     b -> data = temp;
//     return 0;
// }

// int fastsort(struct node * a, int left, int pivot,int type){
//     if(left == pivot){
//         return 0;
//     }
//     if(type == 1){
//         int right = pivot - 1;
//         for(int i = left;i <= pivot; i++){
//             if(a[i].data -> stunum > a[pivot].data -> stunum){
//                 for(int j = right; j >= left ; j--){
//                     if(a[j].data -> stunum < a[pivot].data -> stunum){
//                         exchange(&a[i], &a[j]);
//                         continue;       
//                     }
//                     if(i == j){
//                         exchange(&a[i], &a[pivot]);
//                         fastsort(a, left, i - 1, type);
//                         fastsort(a, i + 1, right, type);
//                     }
//                 }
//             }
//             if(i == pivot){
//                 fastsort(a, left, i - 1, type);
//             }
//         }
//     }else if(type == 2){
//         int right = pivot - 1;
//         for(int i = left;i <= pivot; i++){
//             if(strcmp(a[i].data -> name , a[pivot].data -> name) > 0){
//                 for(int j = right; j >= left ; j--){
//                     if(strcmp(a[j].data -> name , a[pivot].data -> name) < 0){
//                         exchange(&a[i], &a[j]);
//                         continue;       
//                     }
//                     if(i == j){
//                         exchange(&a[i], &a[pivot]);
//                         fastsort(a, left, i - 1, type);
//                         fastsort(a, i + 1, right, type);
//                     }
//                 }
//             }
//             if(i == pivot){
//                 fastsort(a, left, i - 1, type);
//             }
//         }
//     }else{
//         int right = pivot - 1;
//         for(int i = left;i <= pivot; i++){
//             if(a[i].data -> score > a[pivot].data -> score){
//                 for(int j = right; j >= left ; j--){
//                     if(a[j].data -> score < a[pivot].data -> score){
//                         exchange(&a[i], &a[j]);
//                         continue;       
//                     }
//                     if(i == j){
//                         exchange(&a[i], &a[pivot]);
//                         fastsort(a, left, i - 1, type);
//                         fastsort(a, i + 1, right, type);
//                     }
//                 }
//             }
//             if(i == pivot){
//                 fastsort(a, left, i - 1, type);
//             }
//         }
//     }
// }