#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//important question
//we use a doubly linked list containing key,value, next and prev pointer. 
// We also use a hashmap, to store pointer for a key. wehn linked list's lenght is reached , we remove one tail node
//and erase its key from hashmap. on a successful call we bring that node to the front as head. Make sure you do not forget
//to reassign tail pointer once we remove something from the tail;

struct node{
    int k;
    int val;
    node *next;
    node *prev;
    node (int x,int y){
        this->k=x;
        this->val=y;
        next=NULL;
        prev=NULL;
    }
};

void print_list(node *head){
    while(head!=NULL){
        cout<<"k:"<<head->k<<" "<<"v:"<<head->val<<"->";
        head=head->next;
    }
    cout<<endl;
}

node *head,*tail;
unordered_map <int,node*> umap;
int n;
int len;

LRUCache::LRUCache(int capacity) {
    umap.clear();
    head=NULL;
    tail=NULL;
    n=capacity;
    len=0;
}

int LRUCache::get(int key) {
    cout<<"get key:"<<key<<endl;
    node *p,*q,*r,*temp;
    if(umap.find(key)==umap.end()){
        print_list(head);
        cout<<"ans: -1"<<endl;
        return -1;
    }
    else{
        int ans=umap[key]->val;
        temp=umap[key];
        if(temp->next==NULL && temp->prev!=NULL){
            p=temp;
            p=p->prev;
            p->next=NULL;
            tail=p;
            temp->prev=NULL;
            temp->next=NULL;
            temp->next=head;
            head->prev=temp;
            head=temp;
            umap[key]=head;
        }
        else if(temp->next!=NULL && temp->prev!=NULL){
            p=temp->prev;
            q=temp->next;
            temp->prev=NULL;
            temp->next=NULL;
            p->next=q;
            q->prev=p;
            temp->next=head;
            head->prev=temp;
            head=temp;
            umap[key]=head;
        }
        print_list(head);
        cout<<"ans:"<<ans<<endl;
        return ans;
    }
}

void LRUCache::set(int key, int value) {
    cout<<"set key:"<<key<<" as val:"<<value<<endl;
    node *p,*q,*r,*temp;
    if(umap.find(key)==umap.end()){//no such key already exists, add to front;
        if(len==n){//removal
            cout<<"up here "<<endl;
            cout<<"erasing: "<<tail->k<<endl;
            umap.erase(tail->k);
            tail=tail->prev;
            if(tail!=NULL){
                cout<<"tail not null"<<endl;
                tail->next=NULL;
            }
            if(tail==NULL){
                cout<<"tail Null"<<endl;
                head=NULL;
            }
            len--;
        }
        if(head==NULL){//assign
            cout<<"up here1"<<endl;
            head=new node(key,value);
            tail=head;
            umap[key]=head;
            len++;
        }
        else{//assign
            cout<<"up here2"<<endl;
            temp=new node(key,value);
            temp->prev=NULL;
            temp->next=head;
            head->prev=temp;
            head=temp;
            umap[key]=head;
            len++;
        }
    }
    else{
        temp=umap[key];
        p=umap[key];
        if(temp->prev==NULL ){//head;
            cout<<"here"<<endl;
            temp->val=value;
            umap[key]=temp;
        }
        else if(temp->next==NULL){//tail;
            cout<<"here1"<<endl;
            p=p->prev;
            p->next=NULL;
            tail=p;
            temp->prev=NULL;
            temp->val=value;
            temp->next=head;
            head->prev=temp;
            head=temp;
            umap[key]=head;
        }
        else{//beechmein
            cout<<"here2"<<endl;
            temp->val=value;
            p=temp->prev;
            q=temp->next;
            temp->prev=NULL;
            temp->next=NULL;
            p->next=q;
            q->prev=p;
            temp->next=head;
            temp->prev=NULL;
            head->prev=temp;
            head=temp;
            umap[key]=head;
        }
    }
    print_list(head);
}


