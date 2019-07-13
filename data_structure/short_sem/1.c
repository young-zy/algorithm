#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Data{
    char num[11];
    char name[11];
    int grade1;
    int grade2;
};


struct Node {
    struct Data * data;
    struct Node * next;
};

/*
比较函数
参数：节点a,节点b
功能：比较a成绩与b成绩大小
返回值：若a的成绩1 > b的成绩1 则返回1
        否则返回0，
        若成绩1相同，则返回a的成绩2是否大于b的成绩2
 */
int cmp(struct Node* a,struct Node* b){
    if(a->data->grade1 == b->data->grade1){
        return a->data->grade2 < b->data->grade2;
    }
    return a->data->grade1 < b->data->grade1;
}

/*
交换节点数据
参数：节点a，节点b
功能：交换a的data与b的data
返回值：空
 */
void swap_data(struct Node *a,struct Node *b){
    struct Data * temp;
    temp = a->data;
    a->data = b->data;
    b->data = temp;
}

int main(){
    struct Node * head = (struct Node * )malloc(sizeof(struct Node));   //链表头
    head -> next = NULL;                                                //初始化链表头
    head -> data = NULL;
    int length = 0;
    printf("\n");
    while(1){                                                           //循环展示菜单直到用户退出
        printf("请选择操作项目：\n");
        printf("1. 新建一个学生\n");
        printf("2. 删除一个学生\n");
        printf("3. 排序后输出\n");
        printf("4. 计算平均分和成绩统计\n");
        printf("5. 模糊查询姓名\n");
        printf("6. 退出\n");
        printf("请选择：");
        int choice;                                                     //用户选择结果
        scanf("%d",&choice);
        if(choice == 1){
            printf("请输入学号：");
            char num[11];
            int grade1;
            int grade2;
            char name[11];
            scanf("%s",&num);
            struct Node * p = head;
            while(p->next != NULL){                                     //遍历链表查询重复   
                if(!strcmp(p->next->data->num,num)){
                    printf("学号不能重复\n\n");
                    break;
                }
                p = p->next;
            }
            printf("请输入姓名：");
            scanf("%s",name);
            printf("请输入成绩1：");
            scanf("%d",&grade1);
            if(grade1 < 0 || grade1 > 100){           //判断输入是否正确
                printf("输入有误\n\n");
                continue;
            }
            printf("请输入成绩2：");
            scanf("%d",&grade2);
            if(grade2 < 0 || grade2 > 100){
                printf("输入有误\n\n");
                continue;
            }
            p->next = (struct Node *)malloc(sizeof(struct Node));       //创建新节点
            p = p->next;
            p->next = NULL;
            p->data = (struct Data *)malloc(sizeof(struct Data));       
            strcpy(p->data->name,name);                                 //新节点写入数据
            strcpy(p->data->num,num);
            p->data->grade1 = grade1;
            p->data->grade2 = grade2;
            length++;
            printf("创建成功！\n\n");
        }else if(choice == 2){
            char * num;                                                 //用户输入的学号
            printf("请输入要删除的学号：");                                       
            scanf("%s",num);
            struct Node * p = head;
            while(p->next != NULL){
                if( !strcmp(p->next->data->num,num)){
                    struct Node *q = p->next;
                    p->next = q->next;
                    free(q);
                    printf("删除成功！");
                    break;
                }
                p = p->next;
            }
            if(p->next == NULL){
                printf("没有找到学号");
            }
        }else if(choice == 3){
            if(length >1){
                for(int i = 0; i< length;i++){                    //冒泡排序
                    struct Node *p = head -> next;
                    for(int j = 0; j < length;j++){
                        if(cmp(p , p->next)){
                            swap_data(p,p->next);                   //符合交换条件交换节点
                        }
                    }
                }
            }
            struct Node *p = head -> next;
            printf("学号\t\t姓名\t成绩1\t成绩2\n");
            while(p != NULL){                                       //输出排序后的节点
                printf("%s\t%s\t%d\t%d\n",p->data->num,p->data->name,p->data->grade1,p->data->grade2);
                p = p->next;
            }
            printf("\n");
        }else if(choice == 4){
            double avg1 = 0;                                        //成绩1平均值
            double avg2 = 0;                                        //成绩2平均值
            int count[2][11] = {0};                                 //成绩范围记录
            struct Node * p = head -> next;
            while(p != NULL){                                       //遍历所有节点
                avg1 += p->data->grade1;
                avg2 += p->data->grade2;
                count[0][(int)p->data->grade1/10]++;
                count[1][(int)p->data->grade2/10]++;
                p = p->next;
            }
            if(length != 0){                                        //判断长度是否为0，防止错误
                avg1 /= length;
                avg2 /= length;
            }
            for(int i = 0;i<10;i++){
                if(i < 5){
                    count[0][i+1] += count[0][i];
                }else if(i == 5){
                    printf("成绩一不及格的有\t\t%d人\n",count[0][5]);
                }else if(i < 9){
                    printf("成绩一在%d分到%d分之间有\t%d人\n",i*10,i*10+9,count[0][i]);
                }else{
                    printf("成绩一在90分到100分之间有\t%d人\n",count[0][9]+ count[0][10]);
                }
            }
            for(int i = 0;i<10;i++){
                if(i < 5){
                    count[1][i+1] += count[1][i];
                }else if(i == 5){
                    printf("成绩二不及格的有\t\t%d人\n",count[0][5]);
                }else if(i < 9){
                    printf("成绩二在%d分到%d分之间有\t%d人\n",i*10,i*10+9,count[1][i]);
                }else{
                    printf("成绩二在90分到100分之间有\t%d人\n",count[1][9]+ count[1][10]);
                }
            }
            printf("成绩1的平均分为：%lf",avg1);
            printf("成绩2的平均分为：%lf",avg2);
        }else if(choice == 5){
            printf("请输入姓名：");
            char name[11];
            scanf("%s",name);
            struct Node * p = head->next;
            printf("学号\t\t姓名\t成绩1\t成绩2\n");
            while(p != NULL){                                               //遍历链表查找姓名匹配的学生
                if(!strcmp(p->data->name,name)){
                    printf("%s\t%s\t\t%d\t\t%d\n",p->data->name,p->data->num,p->data->grade1,p->data->grade2);
                }
                p = p->next;
            }
        }else if(choice == 6){
            break;
        }
    }
}

