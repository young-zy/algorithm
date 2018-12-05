#include<bits/stdc++.h>

using namespace std;

void initnode(struct node * p);

struct node * iterate(int a[],int b[],int al,int ar,int bl,int br);                     //a:中序遍历数组  b：后序遍历数组 al：中序遍历左范围  ar：中序遍历右范围
                                                                                        //bl：后序遍历左范围  br：后序遍历右范围

struct node {
    int data;                                                                           //节点数据
    struct node * left;                                                                 //左子树头地址
    struct node * right;                                                                //右子树头地址
};

struct index{
    int _index;
    int data;
    friend bool operator < (struct index a,struct index b){                             //重载小于操作符
        return a._index < b._index;                                                     
    }
};

void initnode(struct node * p){                                                         //初始化节点为空
    p -> left = nullptr;
    p -> right = nullptr;
}

struct node * iterate(int a[],int b[],int al,int ar,int bl,int br){                     //迭代函数，参数说明见声明
    struct node *p = (struct node *)malloc(sizeof(node));                               //创建节点
    p -> data = b[br];                                                                  //将值写入节点
    initnode(p);                                                                        //初始化节点指针
    int temp;                                                                           //
    for(int i = al; i <= ar;i++){                                                       //遍历查找与 后序遍历 数组中最后一个数 在 中序遍历 中的位置
        if(a[i] == b[br]){
            temp = i;                                                                   //记录位置
            break;
        }
    }
    int lal,lar,lbl,lbr,ral,rar,rbl,rbr;                                                //lal,lar 为中序遍历分割后子问题左界限和右界限，其余同理
    if(temp != ar){                                 //当位置不为右界限时，说明右侧仍有子树
        ral = temp + 1;                             //中序右侧子问题 左界限 为分割符+1
        rar = ar;                                   //中序右侧子问题 右界限 为原右界限
        rbr = br - 1;                               //后序右侧子问题 右界限 左移一位（去除已经保存的数字）
        rbl = rbr - (rar - ral);                    //后序右侧子问题 左界限 为 后序右侧子问题 右界限 - 中序右侧子问题 中包含的元素数量（左界限 - 右界限） 
        p -> right = iterate(a,b,ral,rar,rbl,rbr);  //执行下一次迭代 
    }                                               //（下面还有一遍绕口令）
    if(temp != al){                                 //当位置不为左侧界限时，说明左侧仍有子树
        lal = al;                                   //中序左侧子问题 左界限 为原左界限
        lar = temp - 1;                             //中序左侧子问题 右界限 为分隔符-1
        lbl = bl;                                   //后续左侧子问题 左界限 为原左界限
        lbr = bl + (lar - lal);                     //后续左侧子问题 右界限 为原左界限 + 中序左侧子问题 中包含的元素数量 （左界限 - 右界限）
        p->left = iterate(a,b,lal,lar,lbl,lbr);     //执行下一次迭代
    }                                               //（总算解释完了）
    return p;                                       //返回节点地址（若位置为界限则返回没有子树的节点）
}

void save(set<struct index> &s,int k,struct node * p){                                  //将 树 转换为数组存储，将下标和数据递归存入集合中
    struct index q;                                                                     //新建一个集合内存储的结构体
    q._index = k;                                                                       //存入下标值
    q.data = p -> data;                                                                 //存入节点数据
    s.insert(q);                                                                        //将结构体存入集合
    if(p -> left != NULL){                                                              //如果左子树不为空
        save(s,2*k,p->left);                                                            //递归执行  下标为现下标 * 2
    }                                                                                   
    if(p -> right != NULL){                                                             //如果右子树不为空
        save(s,2*k+1,p->right);                                                         //递归执行  下标为现下标 * 2 + 1
    }
}


int main(){
    int num;                                                                            //定义节点数量变量
    scanf("%d",&num);                                                                   //输入节点数量存入变量
    if(num == 0){                                                                       //如果节点数量为0
        return 0;                                                                       //结束程序
    }
    set<struct index> s;                                                                //新建集合
    int a[num],b[num];                                                                  //新建中序遍历数组与后序遍历数组
    for(int i = 0; i<num;i++){                                                          //读入中序遍历数组数据
        scanf("%d",&a[i]);  
    }
    for(int i = 0; i<num;i++){                                                          //读入后序遍历数组数据
        scanf("%d",&b[i]);
    }
    struct node * head = iterate(a,b,0,num-1,0,num-1);                                  //执行 迭代，将树保存至节点
    save(s,1,head);                                                                     //将树中数据和对应下标存入集合
    int count = 0;                                                                      //定义 输出数量 计数器
    int start = 1;                                                                      //定义行标开始位置
    int end = 1;                                                                        //定义行标结束位置
    set<struct index>::iterator it;                                                     //定义集合正向迭代器
    set<struct index>::reverse_iterator rit;                                            //定义集合反向迭代器
    for(int i = 0; count < num;i++){                                                    //循环查找直到输出全部节点
        if(i% 2 == 0){                                                                  //当行标为2的整数倍时（逆向输出）
            for(rit = s.rbegin();rit != s.rend();++rit){                                //反向遍历集合
                if(rit -> _index < start){                                              //如果 下标 小于行标初始值 则说明没有更多元素属于这一行
                    break;                                                              //停止遍历
                }else if(rit -> _index > end){                                          //如果 下标 小于行标末尾值 执行下一次循环
                    continue;
                }else{                                                                  //如果 下标 位于行标范围内
                    if(count != 0){                                                     //如果不是第一个输出
                        printf(" ");                                                    //打印空格
                    }
                    printf("%d",rit -> data);                                           //打印 下标 对应的数据
                    count++;                                                            //计数器自增
                }
            }
        }else{                                                                          //当行标不为2的整数倍（正向输出）
            for(it = s.begin();it != s.end();++it){                                     //正向遍历集合
                if(it -> _index < start){                                               //如果 下标 小于行标初始值 执行下一次循环
                    continue;                                                           
                }else if(it -> _index > end){                                           //如果 下标 大于行标末尾值 说明没有更多元素属于这一行
                    break;                                                              //停止遍历
                }else{
                    if(count != 0){                                                     //如果不是第一个输出
                        printf(" ");                                                    //打印空格
                    }   
                    printf("%d",it -> data);                                            //打印 下标 对应的数据
                    count++;                                                            //计数器自增
                }
            }
        }
        start *= 2;                                                                     //一行数据输出完成后 行标 初始值 为行标初始值 * 2
        end = end*2 +1;                                                                 //行标 末尾值为 行标末尾值 *2 +1
    }
    system("pause");
    return 0;                                                                           //循环结束后停止程序
}