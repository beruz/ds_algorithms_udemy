#include <iostream>

using namespace std;

class Stack{
    public:
        int size;
        int top;
        int *s;
        
        Stack(int csize){
            size = csize;
            top = -1;
            s = new int[size];        
        }

        void push(int value){
            if (top == size-1)
                cout << "stack overflow\n";
            else
                top++;
                s[top] = value;
        }
        int checkTop(){
            return s[top];
        }

        int pop(){
            int x= -1;
            if (top == -1)
                cout << "stack underflow\n";
            else{
                x = s[top];
                top--;            
            }
            return x;
        }

        bool isEmpty(){
            if(top == -1)
                return true;
            else
                return false;
        }
        
        bool isFull(){
            if (top == size -1)
                return true;
            else 
                return false;
        }

        int peek(int pos){
            int x=-1;
            if(top-pos+1 <0 || top-pos+1 >size-1)
                cout << "invalid position\n";
            else
                x = s[top-pos+1];
            return x;
        }

        void display(){
            for(int i=top;i>=0;i--){
                cout << s[i] << " " << endl;
            }
            cout << endl;
        }
};

int main()
{
    int size;
    cout << "Enter the size of stack: " ;
    cin >> size;

    Stack st(size);    
    st.push(5);
    st.push(12);
    st.push(13);
    st.push(14);
    cout << "isFull: " << st.isFull() << endl;
    cout << "peeked:  " << st.peek(2) << endl;
    cout << "top: " << st.checkTop() << endl;
    st.pop();
    st.display();

    return 0;
}
