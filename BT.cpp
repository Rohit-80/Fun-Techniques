#include <bits/stdc++.h>
using namespace std;

  struct node
  {
      node * lchild;
      node * rchild;
      int data;
      
  };

node* createBinaryTree(){
     node *p;
     queue<node*> q;
   
     int x; cout<<"Enter the Root Value\n";
     cin>>x;

     node *root = new node;
     root->data = x;
     root->lchild = root->rchild = NULL;
     q.push(root);

     while(!q.empty()){
        p = q.front();
        q.pop();
        x = -1;
        cout<<"Enter the left child\n";
        cin>>x;
        if(x != -1){
            node* temp = new node;

            temp->data=x;
            temp->lchild = temp->rchild = NULL;
            p->lchild = temp;
            q.push(temp);
        }

        x = -1;
        cout<<"Enter the Right child\n";
        cin>>x;
        if(x != -1){
            node* temp = new node;

            temp->data=x;
            temp->lchild = temp->rchild = NULL;
            p->rchild = temp;
            q.push(temp);
        }
     }
     
     return root;

}

void preorderT(node* root){
    cout<<root->data<<" ";

    if(root->lchild){
        preorderT(root->lchild);
    }
    if(root->rchild){
        preorderT(root->rchild);
    }

}

void InorderT(node* root){
    

    if(root->lchild){
        InorderT(root->lchild);
    }
    cout<<root->data<<" ";
    if(root->rchild){
        InorderT(root->rchild);
    }

}

void PostOrderT(node* root){
    

    if(root->lchild){
        PostOrderT(root->lchild);
    }
    if(root->rchild){
        PostOrderT(root->rchild);
    }
     cout<<root->data<<" ";
}


int main(){
   
   node* root = createBinaryTree();
   preorderT(root);
   
}