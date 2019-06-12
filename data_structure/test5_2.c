#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
#define Maxn 105
#define INF 0x3f3f3f3f

typedef int Elemtype;

struct Graph{
    int data[Maxn];
    int conn[Maxn][Maxn];
    int nodenum;
};

typedef int Elemtype;

struct Data{
    Elemtype num;
};

struct Node{
    struct Data * data;
    struct Node * next;
};

struct Stack{
    struct Node * head;
    long long size;
};

struct Queue{
    struct Node * head;
    struct Node * back;
    long long size;
};

struct Stack * Stack(){
    struct Stack* ans = (struct Stack *)malloc(sizeof(struct Stack));
    ans->head = (struct Node*)malloc(sizeof(struct Node));
    ans->head->data = NULL;
    ans->size = 0;
    ans->head->next = NULL;
    return ans;
}

struct Queue * Queue(){
    struct Queue* ans = (struct Queue *)malloc(sizeof(struct Queue));
    ans->head = (struct Node*)malloc(sizeof(struct Node));
    ans->head->data = NULL;
    ans->head->next = NULL;
    ans->back = ans->head;
    ans->size = 0;
    return ans;
}

void stack_pop(struct Stack* st){
    if(st->size > 0){
        struct Node* temp = st->head->next;
        st->head->next = temp->next;
        free(temp->data);
        free(temp);
        st->size--;
    }else{
        return;
    }
    
}

void queue_pop(struct Queue* qu){
    if(qu->size > 0){
        struct Node *temp = qu->head->next;
        qu->head->next = temp->next;
        free(temp->data);
        free(temp);
        qu->size--;
        if(qu->size == 0){
            qu->back = qu->head;
        }
    }
}

void stack_push(struct Stack *st,Elemtype num){
    struct Node *temp = st->head->next->next;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->next = temp;
    newnode->data = (struct Data *)malloc(sizeof(struct Data));
    newnode->data->num = num;
    st->head->next = newnode;
    st->size++;
}

void queue_push(struct Queue *qu, Elemtype num){
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->next = NULL;
    newnode->data = (struct Data *)malloc(sizeof(struct Data));
    newnode->data->num = num;
    qu->back->next = newnode;
    qu->back = newnode;
    qu->size++;
}

Elemtype top(struct Stack *st){
    return st->head->next->data->num;
}

Elemtype front(struct Queue *qu){
    return qu->head->next->data->num;
}

int queue_isempty(struct Queue * qu){
    if(qu->size == 0){
        return 1;
    }else{
        return 0;
    }
}

int stack_isempty(struct Stack * st){
    if(st->size == 0){
        return 1;
    }else{
        return 0;
    }
}

int visited[Maxn];

void dfs(struct Graph *g,int node){
    visited[node] = 1;
    printf("%d ",g->data[node]);
    for(int i = 1; i<=g->nodenum;i++){
        if(visited[i] != 1 && g->conn[node][i] != INF){
            dfs(g,i);
        }
    }
}

void bfs(struct Graph *g,int startnode){
    struct Queue* qu = Queue();
    memset(visited , 0 , sizeof(visited));
    queue_push(qu,startnode);
    while(!queue_isempty(qu)){
        int node = front(qu);
        visited[node] = 1;
        queue_pop(qu);
        printf("%d ",g->data[node]);
        for(int i = 1; i<=g->nodenum; i++){
            if(visited[i] != 1 && g->conn[node][i] != INF){
                queue_push(qu,i);
            }
        }
    }
    printf("\n");
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);       //n为节点数，m为边数
    struct Graph graph;
    struct Graph *g = &graph;
    g->nodenum = n;
    for(int i = 0; i<n ; i++){
        scanf("%d",&g->data[i]);
    }
    memset(g->conn,INF,sizeof(g->conn));
    for(int i = 0; i<m ; i++){
        int x,y,z;
        scanf("%d %d",&x,&y);
        g->conn[x][y] = 1;
        g->conn[y][x] = 1;
    }
    int start;
    scanf("%d",&start);
    dfs(g,start);
    printf("\n");
    bfs(g,start);
    return 0;
}
