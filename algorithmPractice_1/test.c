#include <stdio.h>
struct redpocket
{
    int num;
    int k;
    int qiang;
    float money;
}man[1001];
int main()
{
    int n,i,j,bianhao,mid1,max;
    float mid2,shouru;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        man[i].money=0.0;//��ʼ��
        man[i].qiang=0;
        man[i].num=i+1;//���Ū��
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&man[i].k);
        for(j=0;j<man[i].k;j++)
        {
            scanf("%d %f",&bianhao,&shouru);
            man[bianhao-1].money+=shouru;
            man[i].money-=shouru;
            man[bianhao-1].qiang++;
        }
    }
    for(i=0;i<n;i++)
    {
        max=i;
        for(j=i+1;j<n;j++)
        {
            if(man[j].money>man[max].money)
                max=j;
            else if(man[j].money==man[max].money)
            {
                if(man[j].qiang>man[max].qiang)
                    max=j;
                else if(man[j].qiang==man[max].qiang)
                {
                    if(man[j].num<man[max].num)
                        max=j;
                    else;
                }
                else;
            }
            else;//�����κβ���
        }
        if(max!=i)
        {
            mid2=man[max].money;
            man[max].money=man[i].money;
            man[i].money=mid2;
            mid1=man[max].num;
            man[max].num=man[i].num;
            man[i].num=mid1;//���������ṹ���е�����
        }
    }
    for(i=0;i<n;i++)
        printf("%d %.2f\n",man[i].num,man[i].money/100.0);
    return 0;
}