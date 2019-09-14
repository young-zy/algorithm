#include<bits/stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f
#define MAXN 9999
#define MAXSIZE 1010
#define DLEN 4
using namespace std;

class BigNum{
private:
    int a[500]; //可以控制大数的位数
    int len;
    public:
    BigNum(){len=1;memset(a,0,sizeof(a));} //构造函数
    BigNum(const int); //将一个 int 类型的变量转化成大数
    BigNum(const char*); //将一个字符串类型的变量转化为大数
    BigNum(const BigNum &); //拷贝构造函数
    BigNum &operator=(const BigNum &); //重载赋值运算符，大数之间进行赋
    friend istream& operator>>(istream&,BigNum&); //重载输入运算符
    friend ostream& operator<<(ostream&,BigNum&); //重载输出运算符
    BigNum operator+(const BigNum &)const; //重载加法运算符，两个大数之间的相加运算
    BigNum operator-(const BigNum &)const; //重载减法运算符，两个大数之间的相减运算
    BigNum operator*(const BigNum &)const; //重载乘法运算符，两个大数之间的相乘运算
    BigNum operator/(const int &)const; //重载除法运算符，大数对一个整数进行相除运算
    BigNum operator^(const int &)const; //大数的 n 次方运算
    int operator%(const int &)const; //大数对一个类型的变量进行取模运算int
    bool operator>(const BigNum &T)const; //大数和另一个大数的大小比较
    bool operator>(const int &t)const; //大数和一个 int 类型的变量的大小比较
    void print(); //输出大数
};

BigNum::BigNum(const int b){
    int c,d=b;
    len=0;
    memset(a,0,sizeof(a));
    while(d>MAXN){
        c=d-(d/(MAXN+1))*(MAXN+1);
        d=d/(MAXN+1);
        a[len++]=c;
    }
    a[len++]=d;
}

BigNum & BigNum::operator=(const BigNum &n){
    int i;
    len=n.len;
    memset(a,0,sizeof(a));
    for(i=0;i<len;i++)
        a[i]=n.a[i];
    return *this;
}


istream& operator>>(istream &in,BigNum &b){
    char ch[MAXSIZE*4];
    int i=-1;
    in>>ch;
    int L=strlen(ch);
    int count=0,sum=0;
    for(i=L-1;i>=0;){
        sum=0;
        int t=1;
        for(int j=0;j<4&&i>=0;j++,i--,t*=10){
            sum+=(ch[i]-'0')*t;
        }
        b.a[count]=sum;
        count++;
    }
    b.len=count++;
    return in;
}
//重载输出运算符 
ostream& operator<<(ostream& out,BigNum& b){
    int i;
    cout<<b.a[b.len-1];
    for(i=b.len-2;i>=0;i--){
        printf("%04d",b.a[i]);
    }
    return out;
}

bool BigNum::operator>(const BigNum &T)const{
    int ln;
    if(len>T.len)return true;
    else if(len==T.len){
        ln=len-1;
        while(a[ln]==T.a[ln]&&ln>=0)
            ln--;
        if(ln>=0 && a[ln]>T.a[ln])
            return true;
        else
            return false;
    }
    else
    return false;
}

BigNum BigNum::operator*(const BigNum &T)const{
    BigNum ret;
    int i,j,up;
    int temp,temp1;
    for(i=0;i<len;i++){
        up=0;
        for(j=0;j<T.len;j++){
            temp=a[i]*T.a[j]+ret.a[i+j]+up;
            if(temp>MAXN){
                temp1=temp-temp/(MAXN+1)*(MAXN+1);
                up=temp/(MAXN+1);
                ret.a[i+j]=temp1;
            }else{
                up=0;
                ret.a[i+j]=temp;
            }
        }
        if(up!=0)
            ret.a[i+j]=up;
    }
    ret.len=i+j;
    while(ret.a[ret.len-1]==0 && ret.len>1)ret.len--;
    return ret;
}


int main(){
    int t;
    cin>>t;
    for(int te = 0; te< t ; te++){
        BigNum n;
        cin>>n;
        BigNum ans(1);
        while(n > ans){
            BigNum temp = ans * 2;
            if(temp > n){
                break;
            }else{
                ans = temp;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}