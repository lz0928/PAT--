#include<stdio.h>
#include<iostream>
#include<map>
#include<string>

using namespace std;

bool check(char c){
	if(c >= 'a' && c <= 'z') return true;
	if(c >= 'A' && c <= 'Z') return true;
	if(c >= '0' && c <= '9') return true;
	return false;
}

int main(){
	
	map<string,int> count;
	string str;
	int strLen;
	
	getline(cin, str);
	strLen = str.length();
	int i = 0;
	
	while(i < strLen){
		string word;
		while(i < strLen && (check(str[i]) == true)){
			if(str[i] >= 'A' && str[i] <= 'Z'){
				str[i] += 32;
			}
			word += str[i];
			i++;
		}
		if(word != ""){
			if(count.find(word) == count.end()){
				count[word] = 1;
			}else{
				count[word]++;
			}
		}
		
		while(i < strLen && (check(str[i]) == false)){
			i++;
		}
	}
	
	string resultStr;
	int maxCount = -1;
	for(map<string,int>::iterator it = count.begin(); it != count.end(); it++){
		if(maxCount < it->second){
			maxCount = it->second;
			resultStr = it->first;
		}
	}
	
	cout << resultStr << " " << maxCount;
	
	return 0;
}
