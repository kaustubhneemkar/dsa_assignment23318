/*ROLL NO 23318 ASSIGNMENT-2 [UNDO REDO]
Implementing Queues and Stacks Using Linked Lists for Real-World Task Management
Systems
Undo/Redo Functionality (Stack): Implementing an undo/redo feature in text editors or
design software using a last-in, first-out (LIFO) approach
 */

#include<iostream>
using namespace std;

typedef struct node{
    //Node structure
    string data;
    node* next=NULL;
} node;

class my_stack{
    node* head=NULL;
    public:
        node* get_node(string c){
            // Create a new node with data
            node* new_node=new node();
            new_node->data=c;
            return new_node;
        }
        void push(string c){
            // Push character on top of stack
            node * new_node=get_node(c);
            if(head==NULL){
                head=new_node;
            }
            else{
                new_node->next=head;
                head=new_node;
            }
        }
        void pop(){
            // Remove top element of stack
            if(head==NULL){
                cout<<"Stack is empty.\n";
            }
            else{
                node* temp=head;
                head=head->next;
                delete temp;
            }
        }
        bool isEmpty(){
            // Check if stack is empty
            return head==NULL;
        }
        string peek(){
            // Check data stored in top element of stack
            if(head==NULL){
                cout<<"Stack is empty\n";
                return "";
            }
            else{
                return head->data;
            }
        }
        void display(){ 
            // Display Stack from top to bottom
            if(isEmpty()){
                cout<<"Stack is empty. Nothing to display";
            }
            else{
                node* temp=head;
                cout<<"Text:\n";
                while(temp!=NULL){
                    cout<<temp->data<<' ';
                    temp=temp->next;
                }
            }
            cout<<'\n';
        }
        ~my_stack(){
            // Destructor to delete the stack
            while(head!=NULL){
                node* temp=head;
                head=head->next;
                delete temp;
            }
        }
};
int main(){
    my_stack st;
    my_stack removed;
    while(true){
        cout<<"Enter 0(Undo),1(Redo),2(Push word),3(Show Text),4(Exit):";
        int choice;
        cin>>choice;
        string word;
        switch(choice){
            case 0:
                if(st.isEmpty()){
                    cout<<"Nothing to Undo\n";
                }
                else{
                    removed.push(st.peek());
                    st.pop();
                    cout<<"Undo Operation Complete!\n";
                }
                break;
            case 1:
                if(removed.isEmpty()){
                    cout<<"Nothing to Redo\n";
                }
                else{
                    st.push(removed.peek());
                    removed.pop();
                    cout<<"Redo Operation Complete!\n";
                }
                break;
            case 2:
                cout<<"Enter word to add to text:";
                cin>>word;
                st.push(word);
                cout<<"Word Added!!\n";
                break;
            case 3:
                st.display();
                break;
            case 4:
                cout<<"Exiting, Bye!\n";
                exit(0);
            default:
                cout<<"Invalid choice entered!\n";

        }
    }
    return 0;
}

