#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define maxn 100000

struct treenode * treehead = NULL;          //树的根节点

int count[11] = {0};                        //成绩分段计数数组
int sum = 0;                                //成绩总和计数
int count_stu = 0;                          //学生数量计数

struct Data{                                //数据结构体
    char name[11];                          //姓名
    char num[11];                           //学号
    int grade;                              //成绩
};

struct Node {                               //链表节点
    struct Data* data;                      //数据部分
    struct Node * next;                     //下一个节点
};

struct treenode{                            //树上节点
    struct treenode * left;                 //左孩子
    struct treenode * right;                //右孩子
    int grade;                              //成绩
    struct Node * head;                     //链表表头
};

/*
参数：当前所在节点t ，要删除的节点target
功能：删除target节点并调整树
 */
int del_node(struct treenode * t,struct treenode *target){      //删除一个树节点
    if(target == treehead){                                     //若目标节点为根节点
        if(t->left == NULL && t->right == NULL){                //若左右孩子均为空
            free(treehead);                                     //释放内存
            treehead = NULL;                                    //清空整棵树
            return 0;
        }else if(t->left != NULL){                              //若左孩子不为空
            struct treenode *p = t->left;                       //查找左子树中最大节点
            while(p->right != NULL){
                p = p -> right;
            }
            int grade = p->grade;                               //暂存
            struct Node * head = p->head;                
            del_node(treehead,p);                               //删除最大的节点
            target->grade = grade;                              //将暂存数据黏贴到目标节点，达到交换的目的
            target->head = head;
        }else{                                                  //目标为非根节点
            struct treenode *p = t->right;
            while(p->left != NULL){
                p = p -> left;
            }
            int grade = p->grade;
            struct Node * head = p->head;                
            del_node(treehead,p);
            target->grade = grade;
            target->head = head;
        }
    }else if(t->left == target){
        if(target->left == NULL && target->right == NULL){
            free(target);
            t->left = NULL;
        }else if(target -> left != NULL && target ->right == NULL){
            t->left = target->left;
            free(target);
        }else if(target -> left == NULL && target ->right != NULL){
            t->left = target->right;
            free(target);
        }else{
            if(target->left->right ==NULL){
                t->left = target->left;
                t->left->right = target->right;
                free(target);
            }else if(target->right->left ==NULL){
                t->left = target->right;
                t->left->left = target->left;
                free(target);
            }else{
                struct treenode *q = target->left;
                while(q->right != NULL){
                    q= q->right;
                }
                int grade = q->grade;
                struct Node * head = q->head;                
                del_node(treehead,q);
                target->grade = grade;
                target->head = head;
            }
        }
    }else if(t->right == target){
        if(target->left == NULL && target->right == NULL){
            free(target);
            t->right = NULL;
        }else if(target -> left != NULL && target ->right == NULL){
            t->right = target->left;
            free(target);
        }else if(target -> left == NULL && target ->right != NULL){
            t->right = target->right;
            free(target);
        }else{
            struct treenode *q = target->left;
            while(q->right != NULL){
                q= q->right;
            }
            int grade = q->grade;
            struct Node * head = q->head;                
            del_node(treehead,q);
            target->grade = grade;
            target->head = head;
        }
    }else{
        if(target->grade < t->grade){
            del_node(t->left,target);
        }else{
            del_node(t->right,target);
        }
    }
}

/*
参数：当前所在节点t ，学号num，成绩grade
功能：删除树上某个学生信息，以学号和成绩为查询条件
返回值：成功返回0，失败返回-1
 */
int del_stu(struct treenode * t,char * num,int grade){                  //删除树上学生信息
    if(t == NULL){                                                      //如果树为空返回-1
        return -1;
    }
    int flag = 0;                                                       //是否成功删除的flag
    if(grade == t->grade){                                              //若果成绩匹配则在节点链表内顺序查找
        struct Node * p = t->head;
        while(p->next != NULL){
            if(!strcmp(num,p->next->data->num)){                        //如果找到则删除节点
                free(p->next->data);                                    //释放data内存
                struct Node *q = p->next;                               //暂存链表下一节点地址
                p->next = q->next;                                      //将下一节点地址赋值给上一节点next
                free(q);                                                //释放目标节点
                flag = 1;                                               //flag置1表示成功删除
                break;                                                  //停止查询
            }
            p = p->next;
        }
        if(t->head->next == NULL){                                      //如果节点链表为空
            del_node(treehead,t);                                       //删除该树节点
        }
        if(flag == 0){                                                  //如果没有找到返回-1
            return -1;
        }else{                                                          //否则返回0
            return 0;
        }
    }else if(grade < t->grade){                                         //如果目标成绩比该节点成绩小，向左递归查询
        int res = del_stu(t->left,num,grade);
    }else{                                                              //否则向右递归查询
        int res = del_stu(t->right,num,grade);
    }
}

/*
参数：当前所在节点t ，学号num，成绩grade，姓名name
功能：在树上选择正确位置插入学生信息
返回值：空
 */
void insert_stu(struct treenode * t,char *num,int grade,char * name){        //在树上插入学生
    if(t == NULL){                                                          //如果树为空中则新建节点
        t = (struct treenode *)malloc(sizeof(struct treenode));
        t->head = (struct Node *)malloc(sizeof(struct Node));
        t->head->next = NULL;
        t->grade = grade;
    }else if(grade == t->grade){                                            //如果成绩匹配则插入到节点链表尾部
        struct Node *p = t->head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = (struct Node * )malloc(sizeof(struct Node));
        p = p->next;
        p->next = NULL;
        p->data = (struct Data*)malloc(sizeof(struct Data));
        strcpy(p->data->name,name);
        strcpy(p->data->num,num);
    }else if(grade < t->grade){                                             //如果成绩小于当前节点成绩则向左孩子递归
        if(t->left == NULL){                                                //若左孩子为空则新建节点
            t->left = (struct treenode *)malloc(sizeof(struct treenode));   
            t->left->head = (struct Node *)malloc(sizeof(struct Node));
            t->left->head->next = NULL;
            t->left->grade = grade;
            t->left->left = NULL;
            t->left->right = NULL;
        }
        t = t->left;
        insert_stu(t,num,grade,name);
    }else{                                                                  //成绩大于当前节点值，向右孩子递归
        if(t->right == NULL){                                               //如果有孩子为空则新建节点
            t->right = (struct treenode *)malloc(sizeof(struct treenode));
            t->right->head = (struct Node *)malloc(sizeof(struct Node));
            t->right->head->next = NULL;
            t->right->grade = grade;
            t->right->left = NULL;
            t->right->right = NULL;
        }
        t = t->right;
        insert_stu(t,num,grade,name);
    }
}

/*
参数：当前所在节点t
功能：递归打印学生成绩
返回值：空
 */
void print_treenode(struct treenode * t){                                   //按成绩从大到小输出学生信息
    if(t == NULL){                                                          //若当前节点为空直接返回
        return;
    }
    if(t -> right != NULL){                                                 //若右子树不为空先递归输出右子树内容
        print_treenode(t->right);
    }
    int grade = t->grade;                                                   //输出该节点链表内所有学生信息
    struct Node * p = t->head;
    int i = grade / 10;
    while(p->next != NULL){
        printf("%s\t%s\t\t%d\n",p->next->data->name,p->next->data->num,grade);
        count[i]++;
        count_stu++;
        sum += grade;
        p = p->next;
    }
    if(t -> left != NULL){                                                  //再递归输出左子树内容
        print_treenode(t->left);
    }
}

/*
参数：当前所在节点t
功能：递归先序遍历树上节点
返回值：空
 */
void pri_print_treenode(struct treenode * t){
    if(t == NULL){
        return;
    }
    struct Node * p = t->head;
    int grade = t->grade;
    while(p->next != NULL){
        printf("%s\t%s\t\t%d\n",p->next->data->name,p->next->data->num,grade);
        p = p->next;
    }
    if(t -> left != NULL){
        pri_print_treenode(t->left);
    }
    if(t -> right != NULL){
        pri_print_treenode(t->right);
    }
}

int main(){
    
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;
    while(1){
        printf("\n请选择操作项目：\n");
        printf("1. 新建一个学生\n");
        printf("2. 删除一个学生\n");
        printf("3. 排序并统计\n");
        printf("4. 先序遍历\n");
        printf("5. 姓名模糊查询\n");
        printf("6. 退出\n");
        printf("请选择：");
        int choice;
        scanf("%d",&choice);
        if(choice == 1){
            char name[11];
            char num[11];
            int grade;
            printf("请输入学号：");
            scanf("%s",num);
            struct Node * p = head;
            int flag = 1;
            while(p->next != NULL){
                if(!strcmp(p->next->data->num,num)){
                    flag = 0;
                    break;
                }
                p = p->next;
            }
            if(flag == 0){
                printf("学号已存在\n\n");
                continue;
            }
            printf("请输入姓名：");
            scanf("%s",name);
            printf("请输入成绩：");
            scanf("%d",&grade);
            if(grade <0 || grade >100){
                printf("输入有误\n");
                continue;
            }
            p->next = (struct Node *)malloc(sizeof(struct Node));
            p = p->next;
            p->data = (struct Data*)malloc(sizeof(struct Data));
            p->next = NULL;
            strcpy(p->data->name,name);
            strcpy(p->data->num,num);
            p->data->grade = grade;
            if(treehead == NULL){
                treehead = (struct treenode *)malloc(sizeof(struct treenode));
                treehead->head = (struct Node *)malloc(sizeof(struct Node));
                treehead->head->next = NULL;
                treehead->grade = grade;
                treehead->left = NULL;
                treehead->right = NULL;
            }
            insert_stu(treehead,num,grade,name);
        }else if(choice  == 2){
            char num[11];
            printf("请输入学号：");
            scanf("%s",num);
            struct Node *p = head;
            int grade = -1;
            while(p->next != NULL){
                if(!strcmp(p->next->data->num,num)){
                    grade = p->next->data->grade;
                    struct Node *q = p->next;
                    p->next = q->next;
                    free(q);
                    break;
                }
                p = p->next;
            }
            del_stu(treehead,num,grade);
        }else if(choice == 3){
            for(int i = 0; i<11; i++){
                count[i] = 0;
            }
            print_treenode(treehead);
            for(int i = 0;i<10;i++){
                if(i < 5){
                    count[i+1] += count[i];
                }else if(i == 5){
                    printf("不及格的有\t\t%d人\n",count[5]);
                }else if(i < 9){
                    printf("%d分到%d分之间有\t%d人\n",i*10,i*10+9,count[i]);
                }else{
                    printf("90分到100分之间有\t%d人\n",count[9]+ count[10]);
                }
            }
            printf("平均分为：%.2lf\n",(double)sum/count_stu);
        }else if(choice == 4){
            pri_print_treenode(treehead);
        }else if(choice == 5){
            printf("请输入姓名：");
            char name[11];
            scanf("%s",name);
            struct Node * p = head->next;
            while(p != NULL){
                if(!strcmp(p->data->name,name)){
                    printf("%s\t%s\t\t%d\n",p->data->name,p->data->num,p->data->grade);
                }
                p = p->next;
            }
        }else if(choice == 6){
            break;
        }
    }
    return 0;
}

/*
1
1
aaaa
80
1
2
aaaa
70
1
3
cccc
95
1
4
cccc
60
1
5
eeee
75
3
1
6
ffff
88
1
7
gggg
100
1
8
hhhh
50
1
9
iiii
73
1
10
jjjj
78
1
11
llll
90
1
12
mmmm
71
1
13
nnnn
94
1
14
oooo
72
1
15
pppp
92
3
 */