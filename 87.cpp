#include<bits/stdc++.h>

using namespace std;


class Student{
    private:
        string name;
        string sex;
        int age;
    public:
        Student(string _name,string _sex,int _age){
            name = _name;
            sex = _sex;
            age= _age;
        }
        string tostring(){
            string a = "Student [name='" + name + "', sex='"+ sex+"', age=" + to_string(age)+"]";
            return a;
        }
};

int main(){
    string name;
    string sex;
    int age;
    cin>>name>>age>>sex;
    Student stu(name,sex,age);
    cout<<stu.tostring();
    return 0;
}
