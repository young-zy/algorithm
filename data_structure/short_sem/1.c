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
�ȽϺ���
�������ڵ�a,�ڵ�b
���ܣ��Ƚ�a�ɼ���b�ɼ���С
����ֵ����a�ĳɼ�1 > b�ĳɼ�1 �򷵻�1
        ���򷵻�0��
        ���ɼ�1��ͬ���򷵻�a�ĳɼ�2�Ƿ����b�ĳɼ�2
 */
int cmp(struct Node* a,struct Node* b){
    if(a->data->grade1 == b->data->grade1){
        return a->data->grade2 < b->data->grade2;
    }
    return a->data->grade1 < b->data->grade1;
}

/*
�����ڵ�����
�������ڵ�a���ڵ�b
���ܣ�����a��data��b��data
����ֵ����
 */
void swap_data(struct Node *a,struct Node *b){
    struct Data * temp;
    temp = a->data;
    a->data = b->data;
    b->data = temp;
}

int main(){
    struct Node * head = (struct Node * )malloc(sizeof(struct Node));   //����ͷ
    head -> next = NULL;                                                //��ʼ������ͷ
    head -> data = NULL;
    int length = 0;
    printf("\n");
    while(1){                                                           //ѭ��չʾ�˵�ֱ���û��˳�
        printf("��ѡ�������Ŀ��\n");
        printf("1. �½�һ��ѧ��\n");
        printf("2. ɾ��һ��ѧ��\n");
        printf("3. ��������\n");
        printf("4. ����ƽ���ֺͳɼ�ͳ��\n");
        printf("5. ģ����ѯ����\n");
        printf("6. �˳�\n");
        printf("��ѡ��");
        int choice;                                                     //�û�ѡ����
        scanf("%d",&choice);
        if(choice == 1){
            printf("������ѧ�ţ�");
            char num[11];
            int grade1;
            int grade2;
            char name[11];
            scanf("%s",&num);
            struct Node * p = head;
            while(p->next != NULL){                                     //���������ѯ�ظ�   
                if(!strcmp(p->next->data->num,num)){
                    printf("ѧ�Ų����ظ�\n\n");
                    break;
                }
                p = p->next;
            }
            printf("������������");
            scanf("%s",name);
            printf("������ɼ�1��");
            scanf("%d",&grade1);
            if(grade1 < 0 || grade1 > 100){           //�ж������Ƿ���ȷ
                printf("��������\n\n");
                continue;
            }
            printf("������ɼ�2��");
            scanf("%d",&grade2);
            if(grade2 < 0 || grade2 > 100){
                printf("��������\n\n");
                continue;
            }
            p->next = (struct Node *)malloc(sizeof(struct Node));       //�����½ڵ�
            p = p->next;
            p->next = NULL;
            p->data = (struct Data *)malloc(sizeof(struct Data));       
            strcpy(p->data->name,name);                                 //�½ڵ�д������
            strcpy(p->data->num,num);
            p->data->grade1 = grade1;
            p->data->grade2 = grade2;
            length++;
            printf("�����ɹ���\n\n");
        }else if(choice == 2){
            char * num;                                                 //�û������ѧ��
            printf("������Ҫɾ����ѧ�ţ�");                                       
            scanf("%s",num);
            struct Node * p = head;
            while(p->next != NULL){
                if( !strcmp(p->next->data->num,num)){
                    struct Node *q = p->next;
                    p->next = q->next;
                    free(q);
                    printf("ɾ���ɹ���");
                    break;
                }
                p = p->next;
            }
            if(p->next == NULL){
                printf("û���ҵ�ѧ��");
            }
        }else if(choice == 3){
            if(length >1){
                for(int i = 0; i< length;i++){                    //ð������
                    struct Node *p = head -> next;
                    for(int j = 0; j < length;j++){
                        if(cmp(p , p->next)){
                            swap_data(p,p->next);                   //���Ͻ������������ڵ�
                        }
                    }
                }
            }
            struct Node *p = head -> next;
            printf("ѧ��\t\t����\t�ɼ�1\t�ɼ�2\n");
            while(p != NULL){                                       //��������Ľڵ�
                printf("%s\t%s\t%d\t%d\n",p->data->num,p->data->name,p->data->grade1,p->data->grade2);
                p = p->next;
            }
            printf("\n");
        }else if(choice == 4){
            double avg1 = 0;                                        //�ɼ�1ƽ��ֵ
            double avg2 = 0;                                        //�ɼ�2ƽ��ֵ
            int count[2][11] = {0};                                 //�ɼ���Χ��¼
            struct Node * p = head -> next;
            while(p != NULL){                                       //�������нڵ�
                avg1 += p->data->grade1;
                avg2 += p->data->grade2;
                count[0][(int)p->data->grade1/10]++;
                count[1][(int)p->data->grade2/10]++;
                p = p->next;
            }
            if(length != 0){                                        //�жϳ����Ƿ�Ϊ0����ֹ����
                avg1 /= length;
                avg2 /= length;
            }
            for(int i = 0;i<10;i++){
                if(i < 5){
                    count[0][i+1] += count[0][i];
                }else if(i == 5){
                    printf("�ɼ�һ���������\t\t%d��\n",count[0][5]);
                }else if(i < 9){
                    printf("�ɼ�һ��%d�ֵ�%d��֮����\t%d��\n",i*10,i*10+9,count[0][i]);
                }else{
                    printf("�ɼ�һ��90�ֵ�100��֮����\t%d��\n",count[0][9]+ count[0][10]);
                }
            }
            for(int i = 0;i<10;i++){
                if(i < 5){
                    count[1][i+1] += count[1][i];
                }else if(i == 5){
                    printf("�ɼ������������\t\t%d��\n",count[0][5]);
                }else if(i < 9){
                    printf("�ɼ�����%d�ֵ�%d��֮����\t%d��\n",i*10,i*10+9,count[1][i]);
                }else{
                    printf("�ɼ�����90�ֵ�100��֮����\t%d��\n",count[1][9]+ count[1][10]);
                }
            }
            printf("�ɼ�1��ƽ����Ϊ��%lf",avg1);
            printf("�ɼ�2��ƽ����Ϊ��%lf",avg2);
        }else if(choice == 5){
            printf("������������");
            char name[11];
            scanf("%s",name);
            struct Node * p = head->next;
            printf("ѧ��\t\t����\t�ɼ�1\t�ɼ�2\n");
            while(p != NULL){                                               //���������������ƥ���ѧ��
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

