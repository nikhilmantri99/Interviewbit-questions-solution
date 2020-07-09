#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// Definition for undirected graph.
struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

//we use unordered maps to store already seen labels and their node addresses so that the paths 
// from new nodes to already seen nodes can be directly assigned. Be proud of yourself that you cam eup with this
// yourself.
 
UndirectedGraphNode *create_graph(UndirectedGraphNode *node,unordered_map <int,UndirectedGraphNode *> &umap){
    if(node==NULL){
        return NULL;
    }
    if(umap.find(node->label)!=umap.end()){
        return umap[node->label];
    }
    UndirectedGraphNode *root=new UndirectedGraphNode(node->label);
    umap[node->label]=root;
    int i;
    for(i=0;i<node->neighbors.size();i++){
        root->neighbors.push_back(create_graph(node->neighbors[i],umap));
    }
    return root;
} 

 
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map <int,UndirectedGraphNode *> umap;
    if(node==NULL){
        return NULL;
    }
    UndirectedGraphNode *root=create_graph(node,umap);
    return root;
}
