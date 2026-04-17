#include <iostream>
using namespace std;

int Factorial(int n){
	if (n==0){
		return 1;
	}
	else{
		return n*Factorial(n-1);
	}
}

int main(){
	int num;
	cout<<"enter a number:";
	cin>>num;
	cout<<"the factorial of " << num << " is " << Factorial(num);
	return 0;
}