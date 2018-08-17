#include<stdio.h>
#include<string>
#include<map>
#include<iostream>

using namespace std;


//[0,12]的火星文
string  unitDigit[13] = {"tret", "jan", "feb", "mar", "apr",
	"may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"
};

//13的[0,12]倍的火星文 
string tenDigit[13] = {"tret" , "tam", "hel", "maa", "huh", "tou", "kes",
	"hei", "elo", "syy", "lok", "mer", "jou"
};

string numToStr[170];
map<string, int> strToNum;

void init(){
	for(int i = 0; i < 13; i++){
		//火星文十位为0 
		numToStr[i] = unitDigit[i];
		strToNum[unitDigit[i]] = i; 
		//火星文个位为0 
		numToStr[i * 13] = tenDigit[i];
		strToNum[tenDigit[i]] = i * 13;
	}
	
	//十位 
	for(int i = 1; i < 13; i++){
		//个位 
		for(int j = 1; j < 13; j++){
			string tempStr = tenDigit[i] + " " + unitDigit[j];//十位+个位组成的火星文
			numToStr[i * 13 + j] = tempStr;
			strToNum[tempStr] = i * 13 + j;			 
		}
	}
	
}

int main(){
	
	init();
	
	int n;
	scanf("%d%*c", &n); 
	while(n--){
		string str;
		getline(cin, str);
				
		if(str[0] >= '0' && str[0] <= '9'){
			//地球文
			int num = 0;
			int strlen = str.length();
			for(int i = 0; i < strlen; i++){
				num = num * 10 + str[i] - '0';
			} 
			cout << numToStr[num]  << endl;		
		}else{
			//火星文 			
			cout << strToNum[str] << endl;
		}
	}
	return 0;
} 
