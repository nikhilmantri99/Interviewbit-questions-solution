#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
	int A,B;
	A=21;
	B=6;
	cout<<(A&B)<<endl;//takes bitwise and operation

	cout<<(A|B)<<endl;//takes bitwise or operation

	//bitwise XOR outputs
	// 1 0 - 1
	// 0 1 - 1
	// 0 0 - 0
	// 1 1 - 0
	//a ^ b =1 when and b are different bits. ^ == XOR
	cout<<"XOR value: ";
	cout<<(A^B)<<endl;

	//bit wise not (~):
	// converts 0 to 1 and 1 to 0 bitwise
	cout<<(~A)<<endl;

	//Left Shift operator
	// A << x implies shifting the bits of A to the left by x positions. 
	// The first x bits are lost this way. 
	// The last x bits have 0.
	// A = 29 ( 11101 ) and x = 2, 
 //    so A << 2 means
 //    0 0 1 1 1 0 1 << 2
	//  =============  ------> this sequence of digit shifts to the left by 2 positions
	// ----------------
	//  1 1 1 0 1 0 0  = 116. A << x is equal to multiplication by pow(2, x).
	cout<<"Left Shift operator: "<<endl;
	int t=2;
	for(int i=0;i<35;i++){
		t=t<<1;
		cout<<t<<endl;
	} 

	//Right Shift operator
	// A >> x implies shifting the bits of A to the right by x positions. 
	//The last x bits are lost this way.
	// A = 29 ( 11101 ) and x = 2, 
 //    so A >> 2 means
 //    0 0 1 1 1 0 1 >> 2
 //    ====  -> is lost 
 //    ========== -----> this sequence of digit shifts to the right by 2 positions
 //    ----------------
 //    0 0 0 0 1 1 1 = 7. A >> x is equal to division by pow(2, x). Think why. 
	
	cout<<"Right Shift operator: "<<endl;
	t=1000000000;
	for(int i=0;i<35;i++){
		t=t>>1;
		cout<<t<<endl;
	}	


	//Tricks with bits:
        // x & (x-1) will clear the lowest set bit of x
        // x & ~(x-1) extracts the lowest set bit of x (all others are clear). Pretty patterns when applied to a linear sequence.
        // x & (x + (1 << n)) = x, with the run of set bits (possibly length 0) starting at bit n cleared.
        // x & ~(x + (1 << n)) = the run of set bits (possibly length 0) in x, starting at bit n.
        // x | (x + 1) = x with the lowest cleared bit set.
        // x | ~(x + 1) = extracts the lowest cleared bit of x (all others are set).
        // x | (x - (1 << n)) = x, with the run of cleared bits (possibly length 0) starting at bit n set.
        // x | ~(x - (1 << n)) = the lowest run of cleared bits (possibly length 0) in x, starting at bit n are the only clear bits.


	return 0;
}