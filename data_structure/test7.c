#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxn 105
#define INF 0x3f3f3f3f

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

struct heap{
    int a[Maxn];
    int length;
};

int top (struct heap* he){
    return he->a[1];
}

void downward_update(struct heap *he,int num){
    int temp = he->a[num];
    if(temp < he->a[num<<1] && temp < he->a[(num << 1) + 1]){
        return;
    }else if((num << 1) < Maxn){
        if(he->a[num<<1] < he->a[(num << 1) + 1]){
            he->a[num] = he->a[num<<1]; 
            he->a[num<<1] = temp;
            downward_update(he,num<<1);
        }else{
            he->a[num] = he->a[(num << 1) + 1]; 
            he->a[(num << 1) + 1] = temp;
            downward_update(he,(num<<1)+1);
        }
    }
}

void pop(struct heap *he){
    he->a[1] = he->a[he->length];
    he->a[he->length] = INF;
    he->length--;
    downward_update(he,1);
}

void upward_update(struct heap *he,int num){
    if(num < 1){
        return;
    }else if((num << 1) < Maxn){
        int temp = he->a[num];
        if(he->a[num<<1] < he->a[(num << 1) + 1]){
            he->a[num] = he->a[num<<1]; 
            he->a[num<<1] = temp;
        }else{
            he->a[num] = he->a[(num << 1) + 1]; 
            he->a[(num << 1) + 1] = temp;
        }
        upward_update(he,num >> 1);
    }
}

void insert(struct heap* he,int num){
    he->length++;
    he->a[he->length] = num;
    upward_update(he,he->length >> 1);
}

void heap_sort(int *a,int length){
    struct heap hea;
    hea.length = 0;
    memset(hea.a,INF,sizeof(hea.a));
    struct heap* he = &hea;
    for(int i = 0;i<length;i++){
        insert(he,a[i]);
    }
    int i = 0;
    while(he->length > 0){
        //printf("%d ",top(he));
        a[i] = top(he);
        pop(he);
        i++;
    }
}

void insertion_sort(int *a,int length){
    for(int i = 1; i< length;i++){
        int num = a[i];
        int j;
        for(j = i-1;j >= 0;j--){
            if(a[j]>num){
                a[j+1] = a[j];
            }else{
                break;
            }
        }
        a[j+1] = num;
    }
}

void selection_sort(int *a,int length){
    for(int i = 0; i<length-1;i++){
        int minindex = i;
        for(int j = i;j<length;j++){
            if(a[minindex] > a[j]){
                minindex = j;
            }
        }
        swap(&a[i],&a[minindex]);
    }
}

int main(){
    int a[] = {7,6,5,4,3,2,1};
    int b[] = {7,6,5,4,3,2,1};
    int c[] = {7,6,5,4,3,2,1};
    heap_sort(a,7);
    for(int i = 0; i< 7; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    insertion_sort(b,7);
    for(int i = 0; i< 7; i++){
        printf("%d ",b[i]);
    }
    printf("\n");
    selection_sort(c,7);
    for(int i = 0; i< 7; i++){
        printf("%d ",c[i]);
    }
    printf("\n");
    return 0;
}
