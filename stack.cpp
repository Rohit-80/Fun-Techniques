// There is nothin in a catterpillar that tells you its going to be a butterfly ------------------- !
#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
   int size;
   int top;
   int *S;

   void createStack(int size){
       this->size = size;
       this->top = -1;
       this->S = new int[size];
   }

   void push(int x){
       if(top == size-1){
         cout<<"OverFlow\n";
       }else{
          top++;
          S[top] = x;
       }
   }


   int pop(){
       int x = -1;
       if(top == -1){
         cout<<"UnderFlow\n";
       }else{
         x = S[top];
          top--;
       }

       return x;
   }


   int peek(int pos){
      int x = -1;
      if(top - pos + 1 < 0){
         cout<<"Invalid Position\n";
      }else{
         x = S[top-pos+1];
      }
      return x;
   }
    
    int stacktop(){
       if(top == -1) return -1;
       else return S[top];
    }
   
    bool isEmpty(){
       if(top == -1) return 1;
       else return 0;
    }

    bool isFull(){
      if(top == size - 1){
         return 1;
      }else return 0;
    }

   void display(){
      for(int i = top ; i >= 0; i--){
         cout<<S[i]<<" ";
      }
   }
};

int main(){
   
    Stack st;
    st.createStack(0);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

 // cout<<st.stacktop()<<endl;
 // st.pop();
// cout<<st.isFull()<<endl;

 // st.display();

    // cout<<st.pop();



    
     // cout<<st.top<<endl;

}