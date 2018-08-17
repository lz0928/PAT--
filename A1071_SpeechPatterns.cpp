#include<stdio.h>
#include<string>
#include<map>
#include<iostream>

using namespace std;

const int NORMAL_STATE = 0;
const int WORD_STATE = 1;
const int NOT_WORD_STATE = 2;
int STATE = NORMAL_STATE;

bool isWord(char c){
	if(c >= 'A' && c <= 'Z') 
		return true;
	
	if(c >= 'a' && c <= 'z')
		return true;
	if(c >= '0' && c <= '9')
		return true;
	
	return false;
	
}

int main(){
	
	map<string,int> maps;
	string str;
	string tempStr;
	int strLen = 0;
	
	string resultStr = "";
	maps[resultStr] = -1;
	
	
	getline(cin,str);
	strLen = str.length();
	for(int i = 0; i < strLen; i++){
		switch(STATE){
			case NORMAL_STATE:
				if(isWord(str[i])){
					STATE = WORD_STATE;
					i--;
				}else{
					STATE = NOT_WORD_STATE;
				}
				break;
			case WORD_STATE:
				if(isWord(str[i])){
					if(str[i] >= 'A' && str[i] <= 'Z'){
						str[i] += 32;
					}
					tempStr =  tempStr + str[i];
					if(i == strLen - 1){
						if(maps.find(tempStr) == maps.end()){
							maps[tempStr] = 1;
						}else{
							maps[tempStr]++;
						}
						
						if(maps[resultStr] < maps[tempStr]){
							resultStr = tempStr;
						}
					}
				}else{
					if(maps.find(tempStr) == maps.end()){
						maps[tempStr] = 1;
					}else{
						maps[tempStr]++;
					}
					
					if(maps[resultStr] < maps[tempStr]){
						resultStr = tempStr;
					}
					tempStr.clear();
					STATE = NOT_WORD_STATE;
				}
			break;
			case NOT_WORD_STATE:
				if(isWord(str[i])){
					STATE = WORD_STATE;
					i--;
				}
			break;
		}
	}
	cout << resultStr << " " << maps[resultStr];
	
	return 0;
} 
