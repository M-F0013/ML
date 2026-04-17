#include <iostream>
using namespace std;

void TowerOfHanoi(int n, char s, char d, char a){
	if (n==1){
		cout<<"move "<<n<<" from "<<s<<" to "<<d<<endl;
		return;
	}
	TowerOfHanoi(n-1,s,a,d);
	cout<<"move "<<n<<" from "<<s<<" to "<<d<<endl;
	TowerOfHanoi(n-1,a,d,s);
}

int main(){
	int n=3;
	TowerOfHanoi(n,'a','c','b');
	return 0;
}
