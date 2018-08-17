#include<stdio.h>
#include<map>
#include<string> 

using namespace std;

int main(){
	
	map<string,int> maps;
	char tempC;
	char cArr[100];
	int cArrLen = 0;
	scanf("%c", &tempC);
	cArr[cArrLen++] = tempC;
	while(tempc != '\n'){
		scanf("%c", &tempC);
		if((tempC >= 'A' && tempC <= 'Z') || (tempC >= 'a' && tempC <= 'z') || (tempC >= '0' && tempC <= '9')){
			cArr[cArrLen++] = tempC;
		}else{
			
		}
	}
	
	return 0;
}
