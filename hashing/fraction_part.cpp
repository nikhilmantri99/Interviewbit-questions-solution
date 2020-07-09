#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//

// Lets simulate the process of converting fraction to decimal. Lets look at the part where we have already figured out the integer part which is floor(numerator / denominator).
// Now you are left with ( remainder = numerator%denominator ) / denominator.
// If you remember the process of converting to decimal, at each step you do the following :

// 1) multiply the remainder by 10,
// 2) append remainder / denominator to your decimals
// 3) remainder = remainder % denominator.

// At any moment, if your remainder becomes 0, you are done.

// However, there is a problem with recurring decimals. For example if you look at 1/3, the remainder never becomes 0.

// Notice one more important thing.
// If you start with remainder = R at any point with denominator d, you will always get the same sequence of digits.
// So, if your remainder repeats at any point of time, you know that the digits between the last occurrence of R will keep repeating.



bool thiswillproducerepetition(int x){
	//return true if yes, false if no
	if(x==1){
		return false;
	}
	else if(x%2==0){
		x=x/2;
		return thiswillproducerepetition(x);
	}
	else if(x%5==0){
		x=x/5;
		return thiswillproducerepetition(x);
	}
	else{
		return true;
	}
}


string fractionToDecimal(int A, int B) {
    string sol = "";
    
    long long int num = A;
    long long int den = B;
    
    bool neg = false;
    
    if(num < 0){
        neg = true;    
        num = 0 - num;
    }
    if(den < 0){
        if(neg){
            neg = false;
        }
        else{
            neg = true;
        }
        den = 0 - den;
    }
    
    unordered_map<int, int> myMap;
    
    long long int initial = num/den;
    
    if(num == 0){
        return "0";
    }
    
    if(neg){
        sol = sol + "-";
    }
    
    sol = sol + to_string(initial);
    
    num = num%den;
    
    if(num == 0){
        return sol;
    }
    
    sol = sol + ".";
    
    bool repeat = false;
    int val;
    while(num != 0 && repeat == false){
        num = num*10;
        if(myMap.find(num) != myMap.end()){
            repeat = true;
            val = myMap[num];
            break;
        }
        else{
            myMap.insert({num, sol.size()}); 
   
        }
        int temp = num/den;
        sol = sol + to_string(temp);
        num = num%den;
    }
    
    if(repeat){
        sol = sol + ")";
        sol.insert(val, "(");
    }
    
    return sol;

}

int main(){
	int A;
	cin>>A;
	cout<<thiswillproducerepetition(A)<<endl;
}
