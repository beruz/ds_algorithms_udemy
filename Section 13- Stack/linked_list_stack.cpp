#include <iostream>

using namespace std;
struct Node{
    int data;
    struct Node *next;
};
class Stack{
    public:
        Node *top;

        void push(int x){
            Node *t = new Node;
            if(t == NULL)
                cout << "stack overflow" << endl;
            else
                t->data = x;
                t->next = top;
                top = t;
        }
        int checkTop(){
            return top->data;
        }

        int pop(){
            Node *t;
            int x = -1;
            if (top == NULL)
                cout << "stack underflow\n";
            else{
                t = top;
                x = t->data;
                top = top->next;                
                free(t);          
            }
            return x;
        }

        bool isEmpty(){
            return top==NULL;
        }
        
        bool isFull(){
            Node *t;
            return t==NULL;
        }

       int peek(int pos){
            int x=-1;
            Node *p = top;
            for(int i=0;p!=NULL && i<pos-1;i++){
                p=p->next;
            }
            if(p!=NULL)
                return p->data;
            else
                return -1;
        }

        void display(){
            struct Node *p=top;
            while(p != NULL)
            {
                cout << p->data << " ";
                p=p->next;
            }
            cout << "\n";
        }
};

int main()
{
    Stack st;    
    st.push(10);
    st.push(20);
    st.push(30);
    st.display();

    return 0;
}
