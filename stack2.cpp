//TEXT EDITOR USING STACK
 
#include<bits/stdc++.h>
using namespace std;
class NODE{
    public:
    string s;
    NODE* next;
    NODE(string intake){
        s=intake;
        next=NULL;
    }
};

class texteditor{
    public:
    NODE* holder,*HEAD;
    string temp;
    texteditor(){
       holder=NULL;
       HEAD=NULL;
    }

    void insertdata(){
        string s1;
        cout<<"enter the string to be inserted in the stack: ";
        cin>>s1;
        NODE* newnode=new NODE(s1);
        if(HEAD==NULL){//IF THE STACK IS EMPTY
            HEAD=newnode;
        }//IF THE STACK IS NOT EMPTY
        else{
            HEAD->next=newnode;
            HEAD=HEAD->next;
        }
    }
//deleted data should be stored in the temp node untill new node is added
    void undo(){//do this if u want to delete the topmost or recently added element
       if(HEAD=NULL){cout<<"the stack is already empty: ";}
       else{}
    }

    void redo(){}
};

int main(){}