#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Maxn 100

typedef int Elemtype;

struct ArcNode{ //边
    int adjvex;
    struct ArcNode* next;
    int data;
};

struct VNode{   //顶点
    Elemtype data;  
    struct ArcNode* edgenext;  
};

typedef struct Graph{
    struct VNode verticles[Maxn];
    int vexnum,arcnum;   //顶点，弧数量
    int kind;            //种类
};

struct Graph * Init_Graph(int a,int b){  //a：顶点数 b：边数
    struct VNode *vnode;
    struct Graph *res;
    res->arcnum = a;
    res->arcnum = b;
    for(int i = 0 ; i< a; i ++){
        scanf("%d",&res->verticles[i].data);
        res->verticles[i].edgenext = NULL;
    }
    for(int i = 0; i< b;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        struct ArcNode *arcNode = (struct ArcNode *)malloc(sizeof(struct ArcNode) );
        arcNode->adjvex = b;
        arcNode->data = c;
        arcNode->next = res->verticles[a].edgenext;
        res->verticles[a].edgenext = arcNode;

        arcNode = (struct ArcNode *)malloc(sizeof(struct ArcNode) );
        arcNode->adjvex = a;
        arcNode->data = c;
        arcNode->next = res->verticles[b].edgenext;
        res->verticles[b].edgenext = arcNode;
    }
    return res;
}

void dfs(struct Graph *g){

}

void bfs(struct Graph *g){
    
}

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    struct Graph *g = Init_Graph(a,b);

    return 0;
}