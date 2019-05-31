#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Maxn 100

typedef int Elemtype;

typedef struct ArcNode{ //边
   int adjvex;
   struct ArcNode* next;
   int data;
}ArcNode;

typedef struct VNode{   //顶点
   Elemtype data;  
   ArcNode* edgenext;  
}VNode,AdjList[Maxn];

typedef struct Graph{
   AdjList verticles;
   int vexnum,arcnum;   //顶点，弧数量
   int kind;            //种类
};





int main(){
    
    return 0;
}