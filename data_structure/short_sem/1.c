#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Data{
    char num[11];
    char name[11];
    double grade1;
    double grade2;
};


struct Node {
    struct Data * data;
    struct Node * next;
};


int cmp(struct Node* a,struct Node* b){
    if(a->data->grade1 == b->data->grade1){
        return a->data->grade2 < b->data->grade2;
    }
    return a->data->grade1 < b->data->grade1;
}

void swap_data(struct Node *a,struct Node *b){
    struct Data * temp;
    temp = a->data;
    a->data = b->data;
    b->data = temp;
}

int main(){
    struct Node * head = (struct Node * )malloc(sizeof(struct Node));
    head -> next = NULL;
    head -> data = NULL;
    int length = 0;
    printf("\n");
    while(1){
        printf("��ѡ�������Ŀ��\n");
        printf("1. �½�һ��ѧ��\n");
        printf("2. ɾ��һ��ѧ��\n");
        printf("3. ��������\n");
        printf("4. ����ƽ���ֺͳɼ�ͳ��\n");
        printf("��ѡ��");
        int choice;
        scanf("%d",&choice);
        if(choice == 1){
            printf("������ѧ�ţ�");
            char num[10];
            scanf("%s",&num);
            struct Node * p = head;
            while(p->next != NULL){
                if(!strcmp(p->next->data->num,num)){
                    printf("ѧ�Ų����ظ�\n\n");
                    break;
                }
                p = p->next;
            }
            p->next = (struct Node *)malloc(sizeof(struct Node));
            p = p->next;
            p->next = NULL;
            p->data = (struct Data *)malloc(sizeof(struct Data));
            length++;
            strcpy(p->data->num,num);
            printf("������������");
            scanf("%s",p->data->name);
            printf("������ɼ�1��");
            scanf("%lf",&p->data->grade1);
            printf("������ɼ�2��");
            scanf("%lf",&p->data->grade2);
            printf("�����ɹ���\n\n");
        }else if(choice == 2){
            char * num;
            printf("������Ҫɾ����ѧ�ţ�");
            scanf("%s",num);
            struct Node * p = head;
            while(p->next != NULL){
                if( !strcmp(p->next->data->num,num)){
                    struct Node *q = p->next;
                    p->next = q->next;
                    free(q);
                    printf("ɾ���ɹ���");
                }
            }
            if(p->next == NULL){
                printf("û���ҵ�ѧ��");
            }
        }else if(choice == 3){
            if(length >1){
                for(int i = 0; i< length-1;i++){
                    struct Node *p = head -> next;
                    for(int j = 0; j < length-1;j++){
                        if(cmp(p , p->next)){
                            swap_data(p,p->next);
                        }
                    }
                }
            }
            struct Node *p = head -> next;
            printf("ѧ��\t\t����\t�ɼ�1\t�ɼ�2\n");
            while(p != NULL){
                printf("%s\t%s\t%.2lf\t%.2lf\n",p->data->num,p->data->name,p->data->grade1,p->data->grade2);
                p = p->next;
            }
            printf("\n");
        }else if(choice == 4){
            double avg1 = 0;
            double avg2 = 0;
            struct Node * p = head -> next;
            while(p != NULL){
                avg1 += p->data->grade1;
                avg2 += p->data->grade2;
            }
            if(length != 0){
                avg1 /= length;
                avg2 /= length;
            }
            printf("�ɼ�1��ƽ����Ϊ��%lf",avg1);
            printf("�ɼ�2��ƽ����Ϊ��%lf",avg2);
        }

    }
}

