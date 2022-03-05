#include <iostream>

using namespace std;

int r(){
	static int num = 7;
	return num--;
}


void callFor(){
	
	for(r(); r(); r()){
		
			printf("%d", r());
	}
	
	cout << endl;
}

int main(){
	
	callFor();
	
	return 0;
}
