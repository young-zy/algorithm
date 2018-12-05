#include<bits/stdc++.h>

using namespace std;

void initnode(struct node * p);

struct node * iterate(int a[],int b[],int al,int ar,int bl,int br);                     //a:�����������  b������������� al�����������Χ  ar����������ҷ�Χ
                                                                                        //bl�����������Χ  br����������ҷ�Χ

struct node {
    int data;                                                                           //�ڵ�����
    struct node * left;                                                                 //������ͷ��ַ
    struct node * right;                                                                //������ͷ��ַ
};

struct index{
    int _index;
    int data;
    friend bool operator < (struct index a,struct index b){                             //����С�ڲ�����
        return a._index < b._index;                                                     
    }
};

void initnode(struct node * p){                                                         //��ʼ���ڵ�Ϊ��
    p -> left = nullptr;
    p -> right = nullptr;
}

struct node * iterate(int a[],int b[],int al,int ar,int bl,int br){                     //��������������˵��������
    struct node *p = (struct node *)malloc(sizeof(node));                               //�����ڵ�
    p -> data = b[br];                                                                  //��ֵд��ڵ�
    initnode(p);                                                                        //��ʼ���ڵ�ָ��
    int temp;                                                                           //
    for(int i = al; i <= ar;i++){                                                       //���������� ������� ���������һ���� �� ������� �е�λ��
        if(a[i] == b[br]){
            temp = i;                                                                   //��¼λ��
            break;
        }
    }
    int lal,lar,lbl,lbr,ral,rar,rbl,rbr;                                                //lal,lar Ϊ��������ָ������������޺��ҽ��ޣ�����ͬ��
    if(temp != ar){                                 //��λ�ò�Ϊ�ҽ���ʱ��˵���Ҳ���������
        ral = temp + 1;                             //�����Ҳ������� ����� Ϊ�ָ��+1
        rar = ar;                                   //�����Ҳ������� �ҽ��� Ϊԭ�ҽ���
        rbr = br - 1;                               //�����Ҳ������� �ҽ��� ����һλ��ȥ���Ѿ���������֣�
        rbl = rbr - (rar - ral);                    //�����Ҳ������� ����� Ϊ �����Ҳ������� �ҽ��� - �����Ҳ������� �а�����Ԫ������������� - �ҽ��ޣ� 
        p -> right = iterate(a,b,ral,rar,rbl,rbr);  //ִ����һ�ε��� 
    }                                               //�����滹��һ���ƿ��
    if(temp != al){                                 //��λ�ò�Ϊ������ʱ��˵�������������
        lal = al;                                   //������������� ����� Ϊԭ�����
        lar = temp - 1;                             //������������� �ҽ��� Ϊ�ָ���-1
        lbl = bl;                                   //������������� ����� Ϊԭ�����
        lbr = bl + (lar - lal);                     //������������� �ҽ��� Ϊԭ����� + ������������� �а�����Ԫ������ ������� - �ҽ��ޣ�
        p->left = iterate(a,b,lal,lar,lbl,lbr);     //ִ����һ�ε���
    }                                               //������������ˣ�
    return p;                                       //���ؽڵ��ַ����λ��Ϊ�����򷵻�û�������Ľڵ㣩
}

void save(set<struct index> &s,int k,struct node * p){                                  //�� �� ת��Ϊ����洢�����±�����ݵݹ���뼯����
    struct index q;                                                                     //�½�һ�������ڴ洢�Ľṹ��
    q._index = k;                                                                       //�����±�ֵ
    q.data = p -> data;                                                                 //����ڵ�����
    s.insert(q);                                                                        //���ṹ����뼯��
    if(p -> left != NULL){                                                              //�����������Ϊ��
        save(s,2*k,p->left);                                                            //�ݹ�ִ��  �±�Ϊ���±� * 2
    }                                                                                   
    if(p -> right != NULL){                                                             //�����������Ϊ��
        save(s,2*k+1,p->right);                                                         //�ݹ�ִ��  �±�Ϊ���±� * 2 + 1
    }
}


int main(){
    int num;                                                                            //����ڵ���������
    scanf("%d",&num);                                                                   //����ڵ������������
    if(num == 0){                                                                       //����ڵ�����Ϊ0
        return 0;                                                                       //��������
    }
    set<struct index> s;                                                                //�½�����
    int a[num],b[num];                                                                  //�½������������������������
    for(int i = 0; i<num;i++){                                                          //�������������������
        scanf("%d",&a[i]);  
    }
    for(int i = 0; i<num;i++){                                                          //������������������
        scanf("%d",&b[i]);
    }
    struct node * head = iterate(a,b,0,num-1,0,num-1);                                  //ִ�� �����������������ڵ�
    save(s,1,head);                                                                     //���������ݺͶ�Ӧ�±���뼯��
    int count = 0;                                                                      //���� ������� ������
    int start = 1;                                                                      //�����б꿪ʼλ��
    int end = 1;                                                                        //�����б����λ��
    set<struct index>::iterator it;                                                     //���弯�����������
    set<struct index>::reverse_iterator rit;                                            //���弯�Ϸ��������
    for(int i = 0; count < num;i++){                                                    //ѭ������ֱ�����ȫ���ڵ�
        if(i% 2 == 0){                                                                  //���б�Ϊ2��������ʱ�����������
            for(rit = s.rbegin();rit != s.rend();++rit){                                //�����������
                if(rit -> _index < start){                                              //��� �±� С���б��ʼֵ ��˵��û�и���Ԫ��������һ��
                    break;                                                              //ֹͣ����
                }else if(rit -> _index > end){                                          //��� �±� С���б�ĩβֵ ִ����һ��ѭ��
                    continue;
                }else{                                                                  //��� �±� λ���б귶Χ��
                    if(count != 0){                                                     //������ǵ�һ�����
                        printf(" ");                                                    //��ӡ�ո�
                    }
                    printf("%d",rit -> data);                                           //��ӡ �±� ��Ӧ������
                    count++;                                                            //����������
                }
            }
        }else{                                                                          //���б겻Ϊ2�������������������
            for(it = s.begin();it != s.end();++it){                                     //�����������
                if(it -> _index < start){                                               //��� �±� С���б��ʼֵ ִ����һ��ѭ��
                    continue;                                                           
                }else if(it -> _index > end){                                           //��� �±� �����б�ĩβֵ ˵��û�и���Ԫ��������һ��
                    break;                                                              //ֹͣ����
                }else{
                    if(count != 0){                                                     //������ǵ�һ�����
                        printf(" ");                                                    //��ӡ�ո�
                    }   
                    printf("%d",it -> data);                                            //��ӡ �±� ��Ӧ������
                    count++;                                                            //����������
                }
            }
        }
        start *= 2;                                                                     //һ�����������ɺ� �б� ��ʼֵ Ϊ�б��ʼֵ * 2
        end = end*2 +1;                                                                 //�б� ĩβֵΪ �б�ĩβֵ *2 +1
    }
    system("pause");
    return 0;                                                                           //ѭ��������ֹͣ����
}