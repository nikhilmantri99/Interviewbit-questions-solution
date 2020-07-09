#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vec(vector <string> &x){
	for(int i=0;i<x.size();i++){
		cout<<x[i]<<endl;
	}
	return ;
}

string spacing(int x){
	int i;
	string t;
	for(i=0;i<x;i++){
		t.append(" ");
	}
	return t;
}


string construct(vector <string> &words,int start,int end,int L){
	string build;
	int i,j,k;
	if(start==end){
		build+=words[start];
		for(i=0;i<L-build.size();i++){
			build.append(" ");
		}
		return build;
	}
	else{
		int spaces=0;
		int n_words=end-start+1;
		int word_len=0;
		for(i=start;i<=end;i++){
			word_len+=words[i].size();
		}
		spaces=L-word_len;
		int equal_spaces=spaces/(n_words-1);
		int left_spaces=equal_spaces+1;
		int num_left_spaces=spaces%(n_words-1);
		for(i=start;i<=end;i++){
			build+=words[i];
			if(num_left_spaces>0){
				build+=spacing(left_spaces);
				num_left_spaces--;
			}
			else{
				if(i<end){
					build+=spacing(equal_spaces);
				}
			}
		}
		return build;
	}
}

string last_string(vector <string> &words,int start,int end){
	string build;
	for(int i=start;i<end;i++){
		build+=words[i]+" ";
	}
	build+=words[end];
	return build;
}

vector <string> fullJustify(vector <string> &A, int B) {//A is a vector of words, B is justify length
	int i,j,k,n=A.size();
	vector <string> ans;
	i=0;
	int len=0;
	while(i<n){
		j=i;
		len=0;
		while(j<A.size()){
			len+=A[j].size();
			if(len<B){
				if(j==n-1){
					ans.push_back(last_string(A,i,j));
					return ans;
				}
				len++;//add space
				j++;
			}
			else if(len==B){
				if(j==n-1){
					ans.push_back(last_string(A,i,j));
					return ans;
				}
				else{
					ans.push_back(construct(A,i,j,B));
					i=j+1;
					break;
				}
			}
			else if(len>B){
				ans.push_back(construct(A,i,j-1,B));
				i=j;
				break;
			}
		}
	}
	return ans;
}

int main(){
	vector <string> t={"This", "is", "an", "example", "of", "text", "justification."};
	int L=16;
	vector <string> ans=fullJustify(t,16);
	print_vec(ans);
	return 0;

}