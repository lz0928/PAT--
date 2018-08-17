#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
#include<algorithm>
#include<set> 

using namespace std;

void query(map<string,set<int> > &mp, string &str){
	if(mp.find(str) == mp.end()) printf("Not Found\n");
	else{
		for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++){
			printf("%07d\n", *it);
		}
	}
}

int main(){
	
	map<string,set<int> > mpTitle, mpAuthor, mpKey, mpPub, mpYear;
	
	int n, m;
	int bookId;
	string title, author, key, pub, year;
	
	scanf("%d", &n);
	getchar();
	
	for(int i = 0; i < n; i++){
		scanf("%d", &bookId);
		getchar();
		
		getline(cin, title);
		mpTitle[title].insert(bookId);
		
		getline(cin, author);
		mpAuthor[author].insert(bookId);
		
		char tempC;
		
		while(cin >> key){
			mpKey[key].insert(bookId);
			tempC = getchar();
			if(tempC == '\n') break;
		}
		
		getline(cin, pub);
		mpPub[pub].insert(bookId);
		
		getline(cin, year);
		mpYear[year].insert(bookId);
	}
	
	scanf("%d", &m);
	
	for(int i = 0; i < m; i++){
		int querId;
		string querInfo;
		scanf("%d: ", &querId);
		getline(cin, querInfo);
		cout << querId << ": " << querInfo << endl;
		if(querId == 1) query(mpTitle, querInfo);
		if(querId == 2) query(mpAuthor, querInfo);
		if(querId == 3) query(mpKey, querInfo);
		if(querId == 4) query(mpPub, querInfo);
		if(querId == 5) query(mpYear, querInfo);
	}
	
	return 0;
}
