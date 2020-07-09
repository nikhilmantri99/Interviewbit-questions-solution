#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void print_vec(vector <int> &A){
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
	//A->gas station
	//B->gas cost
	int i,j;
	int n=A.size();
	i=0;
	while(i<A.size()){
		if(A[i]<B[i]) i++;
		else break;
	}
	if(i==A.size()){
		return -1;
	}
	int temp=i;
	while(i<A.size()){
		j=i+1;
		int cap=A[i]-B[i];
		int flag=0;
		while((j%n)!=i){
			cap=cap+A[j%n]-B[j%n];
			if(cap<0){
				// i=j;
				flag++;
				break;
			}
			j++;
		}
		if((j%n)==i){
			return i;
		}
		if(flag>0){
			i=j;
			while( i<A.size()){
				if(A[i]<B[i]) i++;
				else break;
			}
		}
	}
	return -1;
}

int main(){
	vector <int> A={809, 410, 921, 639, 123, 528, 944, 295, 14, 955, 441, 186, 979, 724, 375, 709, 85, 697, 371, 397, 928, 204, 417, 669, 739, 374, 765, 833, 230, 984, 909, 857, 828, 324, 205, 125, 242, 998, 548, 269, 68, 647, 153, 986, 328, 603, 600, 866, 401, 694, 561, 814, 933, 670, 842, 137, 173, 218, 337, 888, 801, 621, 332, 189, 75, 507, 293, 251, 731, 712, 56, 331, 324, 189, 969, 159, 422, 248, 936, 590, 23, 786, 919, 563, 327, 327, 108, 452, 753};
	cout<<A.size()<<endl;
	vector <int> B={307, 134, 341, 322, 705, 727, 153, 877, 926, 36, 33, 467, 651, 393, 412, 290, 85, 468, 978, 332, 683, 857, 477, 198, 701, 856, 316, 358, 263, 579, 88, 69, 21, 390, 253, 629, 358, 302, 297, 800, 460, 830, 908, 287, 710, 434, 742, 832, 993, 314, 699, 655, 366, 153, 833, 230, 881, 931, 376, 547, 60, 970, 897, 403, 747, 725, 611, 491, 385, 628, 786, 574, 660, 637, 906, 148, 301, 991, 610, 497, 164, 920, 468, 722, 683, 390, 754, 220, 492};
	cout<<canCompleteCircuit(A,B)<<endl;
	return 0;
}
