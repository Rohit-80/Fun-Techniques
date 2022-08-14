#include <bits/stdc++.h>
using namespace std;
/*---------------- using Array ---------------------*/
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


/*----------------  using  LinkedList --------------- */

struct node
{
   int data;
   node* next;
};

class Stack {
public:
   node *top = NULL;

   void push(int x) {
      node * t = new node;
      if (t == NULL) {
         cout << "Overflow\n";
      } else {
         t->data = x;
         t->next = top;
         top = t;



      }
   }

   int pop() {
      node *p;
      int x = -1;
      if (top == NULL) {
         return x;
      } else {
         p = top;
         top = p->next;
         x = p->data;
         free(p);
         return x;

      }
   }

   int peek(int pos) {
      node * t = top;

      for (int i = 0 ; t && i < pos - 1; i++) {
         t = t->next;
         // cout<<"work"<<endl;
      }
      if (t) {
         return t->data;
      } else
      {
         cout << "Invalid Pos\n";
         return -1;
      }
   }


   int stacktop() {
      if (top == NULL) return -1;
      else return top->data;
   }

   int isEmpty() {
      return top ? 0 : 1;
   }
   int isFull() {
      node * t = new node;
      int x =  t  ? 0 : 1;
      free(t);
      return x;
   }
};


int main(){
   
    Stack st;
    st.push(5);
    st.push(2);
    st.push(4);

    st.pop();
    st.pop();
    st.pop();

    cout<<st.isEmpty()<<endl;
}



class Solution
{
public:
    int ope (char c){
        if(c == '-' || c == '+') return 1;
        if(c == '*' || c == '/') return 2;
    }
    
    bool operand(char c ){
        return (c == '-' || c == '+' || c == '*' || c == '/');
    }
    
    string infixToPostfix(string infix)
    {

      
         stack<char> s;
         string postfix;
         for(auto a : infix){
             if(a != '(' && a != ')'){
                 if(!operand(a)){
                   postfix += a;
                 }else{
                  
                  
                  while(!s.empty() && s.top() != '(' && ope(s.top()) >= ope(a)){
                     postfix += s.top();
                     s.pop();
                  }
                  s.push(a);
                  
                  
                  
                  
               }
            }else if(a == '('){
              s.push('(');  
            }else{
                while(s.top() != '('){
                    postfix += s.top();
                    s.pop();
                }
                trace(postfix);
                s.pop();
            }
         }
         
         while(!s.empty()){
            postfix += s.top();
            s.pop();
         }
         return postfix;
         
    }
};

int main() {
 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    auto start = std::chrono::high_resolution_clock::now();
    
    ll t = 1;
    // cin>>t;
    
        // while(t--){
        //      test();
        // }
  

    Solution s;
     cout<<s.infixToPostfix("(A+B)*(C/D)")<<endl;
 
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "T_taken : " << ((long double)duration.count()) / ((long double) 1e9) << "s " << endl;
    return 0;
}