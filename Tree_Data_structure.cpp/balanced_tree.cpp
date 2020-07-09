/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    void inorder(){
        stack <TreeNode *> s;
        TreeNode *p,*q,*r;
        p=this;
        while(p!=NULL){
            s.push(p);
            p=p->left;
        }
        while(!s.empty()){
            cout<<"inorder: "<<s.top()->val<<endl;
            p=s.top()->right;
            s.pop();
            while(p!=NULL){
                s.push(p);
                p=p->left;
            }
        }
    }

    int maxdepth(){
        if(this->left==NULL && this->right==NULL){
            return 1;
        }
        else if(this->left!=NULL && this->right==NULL){
            return 1+this->left->maxdepth();
        }
        else if(this->left==NULL && this->right!=NULL){
            return 1+this->right->maxdepth();
        }
        else{
            return 1+max(this->left->maxdepth(),this->right->maxdepth());
        }
    }
};

// Think recursively.
// How can you maintain the depth of subtree of every node?
int height(TreeNode *A){
    if(A==NULL){
        return 0;
    }
    else if(A->left==NULL && A->right==NULL){
        return 1;
    }
    else if(A->left==NULL && A->right!=NULL){
        return 1+height(A->right);
    }
    else if(A->left!=NULL && A->right==NULL){
        return 1+height(A->left);
    }
    else{
        return 1+max(height(A->left),height(A->right));
    }
}

bool isbalanced(TreeNode *A){
    if(A==NULL){
        return true;
    }
    else if(A->left==NULL && A->right==NULL){
        return true;
    }
    if(abs(height(A->right)-height(A->left))<=1){
        bool truth1=isbalanced(A->left);
        bool truth2=isbalanced(A->right);
        return (truth1 && truth2);
    }
    else{
        return false;
    }
}

int Solution::isBalanced(TreeNode* A) {
    if(isbalanced(A)==true){
        return 1;
    }
    else{
        return 0;
    }
}
