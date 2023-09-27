
// Coded By Pujaa


// Including bigInt Library ------ :)
#include "header_file\bigInt.h"     

int main(){
	
    bigInt b1("152");
	int exp = 123;
	cout<<"Power : "<<pow(b1,exp)<<"\n";  

	bigInt num1("12345678945627896413354833146998");
	bigInt num2("45697637638632751519126931376536931");

	cout<<"GCD : "<<gcd(num1, num2)<<"\n";

	cout<<"Square Root : "<<sqrt(num1)<<"\n";

	bigInt sum = num1 + num2;
	cout<<"Sum : "<<sum<<"\n";
	
	cout<<"Minus : "<<num1 - num2<<"\n";

	cout<<"Multiply : "<< num1*num2 <<"\n";

	cout<<"Absolute Value : "<<abs(num1 - num2)<<"\n";

	num1 += 1;
	cout<<num1<<"\n";

	num1 ++;
	cout<<num1<<"\n";

	return 0;
    
}