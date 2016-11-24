#include <iostream>
using namespace std;
#define min(a,b) (a<b ? a:b)

template<typename T>
T minimo(T a, T b){
	if(a<b)
		return a;
	return b;
}

int main() {
	cout<<"2.1:: "<<min(1,4)<<endl;
	cout<<"2.2:: "<<minimo(2,5)<<endl;
	
	return 0;
}

