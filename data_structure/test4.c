#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INF 0x3f3f3f3f

typedef int Elemtype;

struct Data{
    char num;
};

struct Node{
    struct Data * data;
    struct Node * left_child;
    struct Node * right_child;
};

struct binary_tree{
    struct Node * head;
};

int temp_data[10000000];

struct Node* build_tree(int root){
    struct Node *res = (struct Node*)malloc(sizeof(struct Node) );
    res->data = (struct Data*)malloc(sizeof(struct Data));
    res->data->num = temp_data[root];
    if(temp_data[root <<1 ]!= INF){
        res->left_child = build_tree(root<<1);
    }else{
        res->left_child = NULL;
    }
    if(temp_data[root<<1 | 1 ]!= INF){
        res->right_child = build_tree(root << 1 | 1);
    }else{
        res->right_child = NULL;
    }
}

void swap_child(struct Node * node){
    if(node->left_child != NULL){
        swap_child(node->left_child);
    }
    if(node->right_child != NULL){
        swap_child(node->right_child);
    }
    struct Node * temp;
    temp = node->left_child;
    node->left_child = node->right_child;
    node->right_child = temp;
};

void pre_order(struct Node * node){
    printf("%c ",node->data->num);
    if(node->left_child != NULL){
        pre_order(node->left_child);
    }
    if(node->right_child != NULL){
        pre_order(node->right_child);
    }
}

int main(){
    memset(temp_data,INF,sizeof(temp_data));
    int num;
    scanf("%d",&num);
    for(int i = 0; i<num;i++){
        int a,b;
        scanf("%d %C",&a,&b);
        temp_data[a] = b;
    }
    struct binary_tree tree;
    tree.head = build_tree(1);
    pre_order(tree.head);
    swap_child(tree.head);
    printf("\n");
    pre_order(tree.head);
}

