#include<stdio.h>
#include<string>
#include<map>
#include<iostream>

using namespace std;


//[0,12]�Ļ�����
string  unitDigit[13] = {"tret", "jan", "feb", "mar", "apr",
	"may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"
};

//13��[0,12]���Ļ����� 
string tenDigit[13] = {"tret" , "tam", "hel", "maa", "huh", "tou", "kes",
	"hei", "elo", "syy", "lok", "mer", "jou"
};

string numToStr[170];
map<string, int> strToNum;

void init(){
	for(int i = 0; i < 13; i++){
		//������ʮλΪ0 
		numToStr[i] = unitDigit[i];
		strToNum[unitDigit[i]] = i; 
		//�����ĸ�λΪ0 
		numToStr[i * 13] = tenDigit[i];
		strToNum[tenDigit[i]] = i * 13;
	}
	
	//ʮλ 
	for(int i = 1; i < 13; i++){
		//��λ 
		for(int j = 1; j < 13; j++){
			string tempStr = tenDigit[i] + " " + unitDigit[j];//ʮλ+��λ��ɵĻ�����
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
			//������
			int num = 0;
			int strlen = str.length();
			for(int i = 0; i < strlen; i++){
				num = num * 10 + str[i] - '0';
			} 
			cout << numToStr[num]  << endl;		
		}else{
			//������ 			
			cout << strToNum[str] << endl;
		}
	}
	return 0;
} 
