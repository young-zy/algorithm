#include<bits/stdc++.h>
#define endl "\n"

const int INF=0x3f3f3f3f;

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL;
        ListNode *cur = NULL;
        int flag = 0;
        while(l1 != NULL && l2 != NULL){
            int temp = l1->val+l2->val+flag;
            flag = 0;
            if(temp >= 10){
                temp -= 10;
                flag = 1;
            }
            if(res == NULL){
                res = new ListNode(temp);
                cur = res;
            }else{
                cur->next = new ListNode(temp);
                cur = cur->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!= NULL){
            int temp = l1->val+flag;
            flag = 0; 
            if(temp >= 10){
                temp -= 10;
                flag = 1;
            }
            cur->next = new ListNode(temp);
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2!= NULL){
            int temp = l2->val+flag;
            flag = 0;
            if(temp >= 10){
                temp -= 10;
                flag  = 1;
            }
            cur->next = new ListNode(temp);
            cur = cur->next;
            l2 = l2->next;
        }
        if(flag == 1){
            cur->next = new ListNode(1);
        }
        return res;
    }
};



void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}



