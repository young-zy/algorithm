#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

struct aStarNode;
struct node;

using namespace std;

int M, K, C, B;

int op[5][2] = {{1,1},{2,0},{1,0},{0,1},{0,2}}; //可行操作，第一位代表运送的修道士数量第二位代表运送的野人数量

int heuristicFunction(struct node no);

struct node{
    int m;  //左侧修道士
    int c;  //左侧野人
    bool b;  //船只是否在左侧

    node(){

    }

    node(int m, int c, int b){
        this->m = m;
        this->c = c;
        this->b = b;
    }

    bool operator == (const node& b) const {
        return this -> m == b.m && this->c == b.c && this->b == b.b;
    }
};

namespace std{
    template<> struct hash<node>
    {
        std::size_t operator()(node const& no) const noexcept
        {
            return no.m*100+no.c*10+no.b;
        }
    };
}

priority_queue<aStarNode> pq;

unordered_map<node, int> nodeFlag;    //状态标签

vector<aStarNode> ve;                       //状态列表

struct aStarNode{

    struct node no;     //状态

    int val;            //权重

    int step;           //步数

    int id;             //自己的id

    int parentId;       //父操作的id

    aStarNode(node no, int step, int parentId){
        this -> no = no;
        this -> val = heuristicFunction(no);
        this -> step = step;
        this -> parentId = parentId;
        this -> id = ve.size();
    }

    bool operator < (aStarNode b) const{
        return this->val < b.val;
    }
};


int heuristicFunction(struct node no) { //启发函数，从当前状态到达最终状态需要的最少次数
    return no.m + no.c - K * no.b;
}



bool isValid(node no) {
    int m = no.m;
    int c = no.c;
    int b = no.b;
    if(m > M || m < 0 || c > C || c < 0 || (m != 0 && m < c) || (M-m != 0 && (M-m) < (C-c))) return false;
    if(nodeFlag[node(m, c, b)] != 0 ) return false;     //已遍历
    return true;
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    cout<<"输入修道士数量：";
    cin>>M;
    cout<<"输入野人数量：\t";
    cin>>C;
    B = 1;
    K = 2;

    bool canSolve = false;
    aStarNode start = aStarNode( node(M, C, B), 0, 0 );
    ve.push_back(start);
    pq.push( start );
    while( !pq.empty() ){
        struct aStarNode astno = pq.top();
        pq.pop();
        bool state = astno.no.b;        //true代表船在左侧
        // cout<<astno.no.m << " "<< astno.no.c<<" "<< astno.no.b<<endl;    //调试输出
        if(astno.no.m == 0 && astno.no.c == 0) {
            canSolve = true;
            cout<<"需 "<< astno.step <<" 次便可!\n"<<endl;
            stack<aStarNode> st;
            while(astno.id != 0){
                st.push(astno);
                astno = ve[astno.parentId];
            }
            while (!st.empty()) {
                aStarNode temp = st.top();
                cout<<"第"<<temp.step<<"步"<<endl;
                cout<<"左侧修道士："<< temp.no.m;
                cout<<"左侧野人："<< temp.no.c;
                cout<<"左侧船只："<< temp.no.b;
                cout<<endl;
                st.pop();
            }
            break;
        }

        for( int i = 0; i < 5 ; i++ ){
            if(state){      //船在左侧
                node ntemp = node(astno.no.m-op[i][0], astno.no.c-op[i][1], !state);
                if(!isValid(ntemp)){
                    continue;
                }
                nodeFlag[ntemp]++;
                aStarNode temp = aStarNode( ntemp, astno.step+1, astno.id );
                ve.push_back(temp);
                pq.push(temp);
            }else{
                node ntemp = node(astno.no.m+op[i][0], astno.no.c+op[i][1], !state);
                aStarNode temp = aStarNode( ntemp, astno.step+1, astno.id );
                if(!isValid(ntemp)){
                    continue;
                }
                nodeFlag[ntemp]++;
                ve.push_back(temp);
                pq.push(temp);
            }
        }
    }
    if( !canSolve ){
        cout<<"无解";
    }
    return 0;
}