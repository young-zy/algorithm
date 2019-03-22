#include<bits/stdc++.h>

using namespace std;

double zcq(double p, double e1, double e2){
    return p*(e1 + e2)+(1-p)*(e1-e2);
}

int main(){
    stack<double> st;
    string s;
    getline(cin,s);
    stringstream ss(s);
    while(s!=""){
        if(s[0] == '('){
            char temp;
            ss>>temp;
            double dtemp;
            ss>>dtemp;
            ss>>temp;
            st.push(dtemp);
            getline(ss,s);
            //ss<<s;
            continue;
        }else if(s[0] == ')'){
            char temp;
            ss>>temp;
            double e2,e1,p;
            e2 = st.top();
            st.pop();
            e1 = st.top();
            st.pop();
            p = st.top();
            st.pop();
            st.push(zcq(p,e1,e2));
        }else{
            char temp;
            double dtemp;
            ss>>dtemp;
            ss>>temp;
            st.push(dtemp);
            getline(ss,s);
            //ss<<s;
        }
    }
    cout<<st.top();
    
    return 0;
}