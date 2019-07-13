#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define maxn 100000

struct treenode * treehead = NULL;          //���ĸ��ڵ�

int count[11] = {0};                        //�ɼ��ֶμ�������
int sum = 0;                                //�ɼ��ܺͼ���
int count_stu = 0;                          //ѧ����������

struct Data{                                //���ݽṹ��
    char name[11];                          //����
    char num[11];                           //ѧ��
    int grade;                              //�ɼ�
};

struct Node {                               //����ڵ�
    struct Data* data;                      //���ݲ���
    struct Node * next;                     //��һ���ڵ�
};

struct treenode{                            //���Ͻڵ�
    struct treenode * left;                 //����
    struct treenode * right;                //�Һ���
    int grade;                              //�ɼ�
    struct Node * head;                     //�����ͷ
};

/*
��������ǰ���ڽڵ�t ��Ҫɾ���Ľڵ�target
���ܣ�ɾ��target�ڵ㲢������
 */
int del_node(struct treenode * t,struct treenode *target){      //ɾ��һ�����ڵ�
    if(target == treehead){                                     //��Ŀ��ڵ�Ϊ���ڵ�
        if(t->left == NULL && t->right == NULL){                //�����Һ��Ӿ�Ϊ��
            free(treehead);                                     //�ͷ��ڴ�
            treehead = NULL;                                    //���������
            return 0;
        }else if(t->left != NULL){                              //�����Ӳ�Ϊ��
            struct treenode *p = t->left;                       //���������������ڵ�
            while(p->right != NULL){
                p = p -> right;
            }
            int grade = p->grade;                               //�ݴ�
            struct Node * head = p->head;                
            del_node(treehead,p);                               //ɾ�����Ľڵ�
            target->grade = grade;                              //���ݴ����������Ŀ��ڵ㣬�ﵽ������Ŀ��
            target->head = head;
        }else{                                                  //Ŀ��Ϊ�Ǹ��ڵ�
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
��������ǰ���ڽڵ�t ��ѧ��num���ɼ�grade
���ܣ�ɾ������ĳ��ѧ����Ϣ����ѧ�źͳɼ�Ϊ��ѯ����
����ֵ���ɹ�����0��ʧ�ܷ���-1
 */
int del_stu(struct treenode * t,char * num,int grade){                  //ɾ������ѧ����Ϣ
    if(t == NULL){                                                      //�����Ϊ�շ���-1
        return -1;
    }
    int flag = 0;                                                       //�Ƿ�ɹ�ɾ����flag
    if(grade == t->grade){                                              //�����ɼ�ƥ�����ڽڵ�������˳�����
        struct Node * p = t->head;
        while(p->next != NULL){
            if(!strcmp(num,p->next->data->num)){                        //����ҵ���ɾ���ڵ�
                free(p->next->data);                                    //�ͷ�data�ڴ�
                struct Node *q = p->next;                               //�ݴ�������һ�ڵ��ַ
                p->next = q->next;                                      //����һ�ڵ��ַ��ֵ����һ�ڵ�next
                free(q);                                                //�ͷ�Ŀ��ڵ�
                flag = 1;                                               //flag��1��ʾ�ɹ�ɾ��
                break;                                                  //ֹͣ��ѯ
            }
            p = p->next;
        }
        if(t->head->next == NULL){                                      //����ڵ�����Ϊ��
            del_node(treehead,t);                                       //ɾ�������ڵ�
        }
        if(flag == 0){                                                  //���û���ҵ�����-1
            return -1;
        }else{                                                          //���򷵻�0
            return 0;
        }
    }else if(grade < t->grade){                                         //���Ŀ��ɼ��ȸýڵ�ɼ�С������ݹ��ѯ
        int res = del_stu(t->left,num,grade);
    }else{                                                              //�������ҵݹ��ѯ
        int res = del_stu(t->right,num,grade);
    }
}

/*
��������ǰ���ڽڵ�t ��ѧ��num���ɼ�grade������name
���ܣ�������ѡ����ȷλ�ò���ѧ����Ϣ
����ֵ����
 */
void insert_stu(struct treenode * t,char *num,int grade,char * name){        //�����ϲ���ѧ��
    if(t == NULL){                                                          //�����Ϊ�������½��ڵ�
        t = (struct treenode *)malloc(sizeof(struct treenode));
        t->head = (struct Node *)malloc(sizeof(struct Node));
        t->head->next = NULL;
        t->grade = grade;
    }else if(grade == t->grade){                                            //����ɼ�ƥ������뵽�ڵ�����β��
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
    }else if(grade < t->grade){                                             //����ɼ�С�ڵ�ǰ�ڵ�ɼ��������ӵݹ�
        if(t->left == NULL){                                                //������Ϊ�����½��ڵ�
            t->left = (struct treenode *)malloc(sizeof(struct treenode));   
            t->left->head = (struct Node *)malloc(sizeof(struct Node));
            t->left->head->next = NULL;
            t->left->grade = grade;
            t->left->left = NULL;
            t->left->right = NULL;
        }
        t = t->left;
        insert_stu(t,num,grade,name);
    }else{                                                                  //�ɼ����ڵ�ǰ�ڵ�ֵ�����Һ��ӵݹ�
        if(t->right == NULL){                                               //����к���Ϊ�����½��ڵ�
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
��������ǰ���ڽڵ�t
���ܣ��ݹ��ӡѧ���ɼ�
����ֵ����
 */
void print_treenode(struct treenode * t){                                   //���ɼ��Ӵ�С���ѧ����Ϣ
    if(t == NULL){                                                          //����ǰ�ڵ�Ϊ��ֱ�ӷ���
        return;
    }
    if(t -> right != NULL){                                                 //����������Ϊ���ȵݹ��������������
        print_treenode(t->right);
    }
    int grade = t->grade;                                                   //����ýڵ�����������ѧ����Ϣ
    struct Node * p = t->head;
    int i = grade / 10;
    while(p->next != NULL){
        printf("%s\t%s\t\t%d\n",p->next->data->name,p->next->data->num,grade);
        count[i]++;
        count_stu++;
        sum += grade;
        p = p->next;
    }
    if(t -> left != NULL){                                                  //�ٵݹ��������������
        print_treenode(t->left);
    }
}

/*
��������ǰ���ڽڵ�t
���ܣ��ݹ�����������Ͻڵ�
����ֵ����
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
        printf("\n��ѡ�������Ŀ��\n");
        printf("1. �½�һ��ѧ��\n");
        printf("2. ɾ��һ��ѧ��\n");
        printf("3. ����ͳ��\n");
        printf("4. �������\n");
        printf("5. ����ģ����ѯ\n");
        printf("6. �˳�\n");
        printf("��ѡ��");
        int choice;
        scanf("%d",&choice);
        if(choice == 1){
            char name[11];
            char num[11];
            int grade;
            printf("������ѧ�ţ�");
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
                printf("ѧ���Ѵ���\n\n");
                continue;
            }
            printf("������������");
            scanf("%s",name);
            printf("������ɼ���");
            scanf("%d",&grade);
            if(grade <0 || grade >100){
                printf("��������\n");
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
            printf("������ѧ�ţ�");
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
                    printf("���������\t\t%d��\n",count[5]);
                }else if(i < 9){
                    printf("%d�ֵ�%d��֮����\t%d��\n",i*10,i*10+9,count[i]);
                }else{
                    printf("90�ֵ�100��֮����\t%d��\n",count[9]+ count[10]);
                }
            }
            printf("ƽ����Ϊ��%.2lf\n",(double)sum/count_stu);
        }else if(choice == 4){
            pri_print_treenode(treehead);
        }else if(choice == 5){
            printf("������������");
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