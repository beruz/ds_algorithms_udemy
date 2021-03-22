#include <iostream>
#include <cstring> 

using namespace std;

class Stack{
    public:
        int size;
        int top;
        char *s;

        Stack(){
            size = 0;
            top = -1;
            s = new char[size];        
        }

        Stack(int csize){
            size = csize;
            top = -1;
            s = new char[size];        
        }

        void push(char value){
            if (isFull())
                cout << "stack overflow\n";
            else
                top++;
                s[top] = value;
        }
        int checkTop(){
            return s[top];
        }

        int pop(){
            char x= 1;
            if (isEmpty())
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

bool isBalanced(char *exp)
{
    Stack st((int)strlen(exp));
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            st.push(exp[i]);         
        else if (exp[i] == ')'){
            if(st.isEmpty())
                return false;
            else 
                st.pop();
        }
    }
    return st.isEmpty() ? true : false;
}

int main()
{
    char E[] = "((a+b)*(c-d))";
    cout << isBalanced(E) << endl;
 
    char F[] = "((a+b)*(c-d)))";
    cout << isBalanced(F) << endl;
 
    char G[] = "(((a+b)*(c-d))";
    cout << isBalanced(G) << endl;

    return 0;
}