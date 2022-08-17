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


int heightOfBT(node * root){

    int x,y;
      if(root){
        x = heightOfBT(root->lchild);
        y = heightOfBT(root->rchild);

        if(x > y) return x+1;
        else return y+1;
      }

      return 0;

}

int countNodeBT(node * root){

    int x,y;
      if(root){
        x = countNodeBT(root->lchild);
        y = countNodeBT(root->rchild);

       return x+y+1;
      }

      return 0;

}

int countLeafNodes(node * root){

      if(!root){
        return 0;
      }
    int x = 0,y = 0;
      if(!root->lchild && !root->rchild){
        x = countLeafNodes(root->lchild);
        y = countLeafNodes(root->rchild);
    
        return x+y+1;
      }

      return countLeafNodes(root->lchild) + countLeafNodes(root->rchild); 

}

void given_level_traversal(node* root,int lvl){
      if(root == NULL) return;

     if(lvl == 0){
        cout<<root->data<<" ";
     }else{
        given_level_traversal(root->lchild,lvl - 1);
        given_level_traversal(root->rchild,lvl - 1);
     }
}



int main(){
   
   node* root = createBinaryTree();
   preorderT(root);


   cout<<" \n \n\n \n\n";

   cout<<countLeafNodes(root)<<endl;
   
   
}