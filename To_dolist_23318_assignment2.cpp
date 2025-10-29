/*ROLL NO 23318 ASSIGNMENT-2 [TO-DO LIST]
Task Scheduling System (Queue): Managing tasks in a first-in, first-out (FIFO) order, such
as print job scheduling or process management in an operating system.
*/

#include<iostream>
using namespace std;

enum level{
    // enum to define the levels for difficulty and priority
    low=0,medium=1,high=2
};
typedef struct Task{
    // Task structure for a node
    string title;
    enum level priority;
    enum level difficulty;
    Task* next;
} Task;

class my_queue{
    Task* front=NULL;
    Task* rear=NULL;
    public:
        Task* get_node(){
            // Function to create a new node by taking necessary input and validation
            int flag1=0,flag2=0,flag0=0;
            int difficulty;
            string title;
            int priority;
            do{
                if(!flag0){   
                    cout<<"Enter Title of Task:";
                    cin>>title;
                    flag0=1;
                }
                if(!flag1){
                    cout<<"Enter Difficulty of Task(0->Low,1->Medium,2->High):";    
                    cin>>difficulty;
                    flag1=difficulty>=0 && difficulty<=2;
                }
                if(!flag2){
                    cout<<"Enter Priority of Task(0->Low,1->Medium,2->High):";
                    cin>>priority;
                    flag2=priority>=0 && priority<=2;
                }
            }while(!(flag1 && flag2));
            enum level arr[]={low,medium,high};
            Task* new_node=new Task();
            new_node->title=title;
            new_node->difficulty=arr[difficulty];
            new_node->priority=arr[priority];
            return new_node;
        }
        void enqueue(){
            // Insert node at rear
            Task* new_node=get_node();
            if(front==NULL){
                front=new_node;
                rear=new_node;
            }
            else{
                rear->next=new_node;
                rear=new_node;
            }
        }
        void dequeue(){
            // Delete node from front
            if(front==NULL){
                cout<<"Queue is empty!\n";
            }
            else{
                Task* temp=front;
                front=front->next;
                delete temp;
            }
        }
        Task* peek(){
            // Return front element
            if(isEmpty()){
                cout<<"Queue is empty!";
                return NULL;
            }
            else{
                return front;
            }
        }
        bool isEmpty(){
            //Check if queue is empty
            return front==NULL;
        }

};
int main(){
    my_queue Tasks;
    while(true){
        cout<<"Enter 0(Exit),1(Add Task),2(Complete Task),3(Peek):";
        int choice;
        cin>>choice;
        switch(choice){
            case 0:
                cout<<"Exiting, Bye!\n";
                exit(0);
                break;
            case 1:
                Tasks.enqueue();
                cout<<"Task Added to front!\n";
                break;
            case 2:
                if(Tasks.isEmpty()){
                    cout<<"No Tasks to Complete\n";
                }
                else {
                    Tasks.dequeue();
                    cout<<"Task Completed\n";
                }
                break;
            case 3:
                if(Tasks.isEmpty()){
                    cout<<"No Tasks to Show\n";
                }
                else{
                    Task* first_task=Tasks.peek();
                    cout<<"Title:"<<first_task->title<<'\n';
                    cout<<"Difficulty:"<<first_task->difficulty<<'\n';
                    cout<<"Priority:"<<first_task->priority<<"\n";
                }
                break;
            default:
                cout<<"Invalid choice entered!\n";

        }
    }
    return 0;
}

