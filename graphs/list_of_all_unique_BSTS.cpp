#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
vector <TreeNode*> generateTrees1(int start, int end){
	vector <TreeNode*> result;
	if(start>end){
		result.push_back(NULL);
		return result;
	}
	for(int i=start;i<=end;i++){
		vector <TreeNode*> leftsubtree=generateTrees1(start,i-1);
		vector <TreeNode*> rightsubtree=generateTrees1(i+1,end);
		for(int j=0;j<leftsubtree.size();j++){
			for(int k=0;k<rightsubtree.size();k++){
				TreeNode *root=new TreeNode(i);
				root->left=leftsubtree[j];
				root->right=rightsubtree[k];
				result.push_back(root);
			}
		}
	}
	return result;
}

vector <TreeNode*> generateTrees(int A) {
	vector <TreeNode *> ans=generateTrees1(1,A);
	return ans;
}

int main(){

}