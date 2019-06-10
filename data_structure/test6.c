#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int binary_search(int *a,int l,int r,int target){
    if(l >= r && a[l] != target){
        return -1;
    }else{
        int mid = ((l+r) >> 1);
        if(a[mid] == target){
            return mid;
        }else if(a[mid] < target){
            return binary_search(a,mid+1,r,target);
        }else{
            return binary_search(a,l,mid-1,target);
        }
    }
}

int linear_search(int *a,int length,int target){
    for(int i = 0; i< length;i++){
        if(a[i] == target){
            return i;
        }
    }
    return -1;
}


int main(){

    return 0;
}
