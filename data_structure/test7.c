#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Maxn 100005
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
    struct heap* he;
    for(int i = 0;i<length;i++){
        insert(he,a[i]);
    }
    while(he->length > 0){
        printf("%d ",top(he));
        top(he);
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
        int maxindex = 0;
        for(int j = i;j<length;j++){
            if(a[maxindex] < a[j]){
                maxindex = j;
            }
        }
        swap(&a[i],&a[maxindex]);
    }
}

int main(){
    return 0;

}
