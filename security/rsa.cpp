#include<bits/stdc++.h>
#define endl "\n"
#define MAXN 10000

const int INF=0x3f3f3f3f;

using namespace std;

class BigInt{
public:
	int sign;
	string s;

	BigInt() : s("") {}

	BigInt(string x){
		*this = x;
	}

	BigInt(int x){
		*this = to_string(x);
	}

	BigInt negative(){
		BigInt x = *this;

		x.sign *= -1;

		return x;
	}

	BigInt normalize(int newSign){
		for(int a = s.size() - 1; a > 0 && s[a] == '0'; a--)
			s.erase(s.begin() + a);

		sign = (s.size() == 1 && s[0] == '0' ? 1 : newSign);

		return *this;
	}

	void operator =(string x){
		int newSign = (x[0] == '-' ? -1 : 1);

		s = (newSign == -1 ? x.substr(1) : x);

		reverse(s.begin(), s.end());

		this->normalize(newSign);
	}

	bool operator ==(const BigInt &x) const{
		return (s == x.s && sign == x.sign);
	}

    bool operator !=(const BigInt &x) const{
        return !(*this==x);
    }

	bool operator <(const BigInt &x) const{
		if(sign != x.sign) return sign < x.sign;

		if(s.size() != x.s.size())
			return (sign == 1 ? s.size() < x.s.size() : s.size() > x.s.size());

		for(int a = s.size() - 1; a >= 0; a--) if(s[a] != x.s[a])
			return (sign == 1 ? s[a] < x.s[a] : s[a] > x.s[a]);

		return false;
	}

	bool operator <=(const BigInt &x) const{
		return (*this < x || *this == x);
	}

	bool operator >(const BigInt &x) const{
		return (!(*this < x) && !(*this == x));
	}

	bool operator >=(const BigInt &x) const{
		return (*this > x || *this == x);
	}

	BigInt operator +(BigInt x){
		BigInt curr = *this;

		if(curr.sign != x.sign) return curr - x.negative();

		BigInt res;

		for(int a = 0, carry = 0; a < s.size() || a < x.s.size() || carry; a++){
			carry += (a < curr.s.size() ? curr.s[a] - '0' : 0) + (a < x.s.size() ? x.s[a] - '0' : 0);

			res.s += (carry % 10 + '0');

			carry /= 10;
		}

		return res.normalize(sign);
	}

	BigInt operator -(BigInt x){
		BigInt curr = *this;

		if(curr.sign != x.sign) return curr + x.negative();

		int realSign = curr.sign;

		curr.sign = x.sign = 1;
		if(curr < x) return ( (x - curr).negative()).normalize(-realSign);
		BigInt res;
		for(int a = 0, borrow = 0; a < s.size(); a++){
			borrow = (curr.s[a] - borrow - (a < x.s.size() ? x.s[a] : '0'));
			res.s += (borrow >= 0 ? borrow + '0' : borrow + '0' + 10);
			borrow = (borrow >= 0 ? 0 : 1);
		}
		return res.normalize(realSign);
	}

	BigInt operator *(BigInt x){
		BigInt res("0");

		for(int a = 0, b = s[a] - '0'; a < s.size(); a++, b = s[a] -'0'){
			while(b--) res = (res + x);

			x.s.insert(x.s.begin(), '0');
		}

		return res.normalize(sign * x.sign);
	}

	BigInt operator /(BigInt x){
		if(x.s.size() == 1 && x.s[0] == '0') x.s[0] /= (x.s[0] - '0');

		BigInt temp("0"), res;

		for(int a = 0; a < s.size(); a++)
			res.s += "0";
		
		int newSign = sign * x.sign;

		x.sign = 1;

		for(int a = s.size() - 1; a >= 0; a--){
			temp.s.insert(temp.s.begin(), '0');
			temp = temp + s.substr(a, 1);

			while(!(temp < x)){
				temp = temp - x;
				res.s[a]++;
			}
		}

		return res.normalize(newSign);
	}

	BigInt operator %(BigInt x){
		if(x.s.size() == 1 && x.s[0] == '0') x.s[0] /= (x.s[0] - '0');

		BigInt res("0");

		x.sign = 1;

		for(int a = s.size() - 1; a >= 0; a--){
			res.s.insert(res.s.begin(), '0');

			res = res + s.substr(a, 1);

			while(!(res < x))
				res = res - x;
		}

		return res.normalize(sign);
	}

	string toString() const{
		string ret = s;

		reverse(ret.begin(), ret.end());

		return (sign == -1 ? "-" : "") + ret;
	}

	BigInt toBase10(int base){
		BigInt exp(1), res("0"), BASE(base);
		
		for(int a = 0; a < s.size(); a++){
			int curr = (s[a] < '0' || s[a] > '9' ? (toupper(s[a]) - 'A' + 10) : (s[a] - '0'));

			res = res + (exp * BigInt(curr));
			exp = exp * BASE;
		}

		return res.normalize(sign);
	}

	BigInt toBase10(int base, BigInt mod){
		BigInt exp(1), res("0"), BASE(base);
		
		for(int a = 0; a < s.size(); a++){
			int curr = (s[a] < '0' || s[a] > '9' ? (toupper(s[a]) - 'A' + 10) : (s[a] - '0'));

			res = (res + ((exp * BigInt(curr) % mod)) % mod);
			exp = ((exp * BASE) % mod);
		}

		return res.normalize(sign);
	}

	string convertToBase(int base){
		BigInt ZERO(0), BASE(base), x = *this;
		string modes = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

		if(x == ZERO)
			return "0";

		string res = "";

		while(x > ZERO){
			BigInt mod = x % BASE;

			x = x - mod;

			if(x > ZERO)
				x = x / BASE;

			res = modes[stoi(mod.toString())] + res;
		}

		return res;
	}

	BigInt toBase(int base){
		return BigInt(this->convertToBase(base));
	}

	friend ostream &operator <<(ostream &os, const BigInt &x){
		os << x.toString();

		return os;
	}
};

BigInt exgcd(BigInt a, BigInt b, BigInt &x, BigInt &y){
    if(b==0){
        x = BigInt(1);
        y = BigInt(0);
        return a;
    }
    BigInt res = exgcd(b,a%b,x,y);
    BigInt t=x;
    x=y;
    y=t-a/b*y;
    return res;
}

BigInt inverse( BigInt e, BigInt phi){
    BigInt x,y;
    if(exgcd(e, phi, x, y) == BigInt(1)){
        return (x%phi+phi)%phi;
    }
}

BigInt quickpowmod(BigInt a,BigInt b,BigInt c){
    BigInt ans = BigInt(1);
    a = a % c;
    string base2 = b.convertToBase(2);
    BigInt zero = BigInt(0);
    BigInt two = BigInt(2);
    while(base2.length()){
        if(base2.back() != '0'){
            ans = (ans * a) % c;
        }
        base2.pop_back();
        a = (a*a) % c;
    }
    return ans;
}
int primes[MAXN+1];

bool millerRabin(BigInt num, long long k){
    long long s = 0;
    BigInt temp = num-1;
    string tempB2 = temp.convertToBase(2);
    while(tempB2.back() == '0' &&tempB2.length()){
        s++;
        tempB2.pop_back();     
    }
    for(int i = 0; i< s;i++){
        temp = temp/2;
    }
    while(k--){
        _sleep(1);
        BigInt b = BigInt(rand())%(num-2)+2;
        BigInt y = quickpowmod(b,temp,num);
        if(y == 1 || y ==(num-1)){
            return true;
        }
        for(long long  i = 1; i < s && y != (num-1); i++){
            y = quickpowmod(y,BigInt(2),num);
            if(y == 1){
                return false;
            }
        }
        if(y != (num-1)){
            return false;
        }
    }
    return true;
}

void getPrime(){
    memset(primes,0,sizeof(primes));
    for(int i=2;i<=MAXN;i++){
    if(!primes[i])primes[++primes[0]]=i;
        for(int j=1;j<=primes[0]&&primes[j]<=MAXN/i;j++){
            primes[primes[j]*i]=1;
            if(i%primes[j]==0) break;
        }
    }
}


bool isPrime(BigInt num){
    BigInt zero(0);
    for(int i = 1; i<=1228;i++){
        if(num % primes[i] == zero){
            return false;
        }
    }
    if(!millerRabin(num,5)){
        return false;
    }
    return true;
}


string gen_rand(int len = 32){
    string res;
    int a[4] = {1,3,7,9};
    for(int i = 1;i<len;i++){
        res.push_back(rand()%10+'0');
        _sleep(1);
    }
    res.push_back(a[rand()*10%4]+'0');
    return res;
}

string gen_prime(int len = 32){
    string res;
    while(1){
        res = gen_rand(len);
        if(isPrime(BigInt(res))){
            return res;
        }
    }
}

int main(){
    srand(time(NULL));
    getPrime(); //gen primes < 10000
    cout<<"请输入p q生成的模式：\n1. 随机\n2. 手动输入\n请选择：";
    int mode;
    cin>>mode;
    BigInt p,q;
    if(mode == 1){
        // p = BigInt(61);
        p = gen_prime();
        cout<<"随机生成的p:"<<p<<endl;
        // q = BigInt(53);
        q = gen_prime();
        cout<<"随机生成的q:"<<q<<endl;
    }else{
        string s1,s2;
        cout<<"请输入p: ";
        cin>>s1;
        cout<<"请输入q: ";
        cin>>s2;
        p = BigInt(s1);
        q = BigInt(s2);
    }
    BigInt n = p*q;
    cout<<"计算得到的n:"<<n<<endl;
    BigInt phi = (p-1)*(q-1);
    cout<<"计算得到的phi:"<<phi<<endl;
    BigInt e = gen_prime(phi.s.length()-1);
    cout<<"随机生成的e:"<<e<<endl;
    BigInt d = inverse(e,phi);
    cout<<"计算得到的d:"<<d<<endl;
    string s;
    cout<<"请输入明文，纯数字(不得超过n)：";
    cin>>s;
    BigInt message = BigInt(s);
    BigInt secret = quickpowmod(message, e, n);
    cout<<"密文："<<secret<<endl;
    BigInt origin = quickpowmod(secret, d, n);
    cout<<"解密密文验证："<<origin<<endl;
    return 0;
}