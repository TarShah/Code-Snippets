//Test Case Generator
#include<bits/stdc++.h>
using namespace std;

int rand(int a,int b){
	return a + rand()%(b-a+1);
}

int main(int argc, char* argv[]){
	srand(atoi(argv[1]));
	
	return 0;
}
// random_shuffle(all(array)) -- randomly shuffles the whole array
