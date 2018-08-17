#include<stdio.h>
#include<cmath>
using namespace std;

const int maxn = 100010;
struct node{
	char val;
	int next;
}nodes[maxn];

int main(){
	
	int begin1, begin2, n;
	int word1Len = 0, word2Len = 0;
	scanf("%d %d %d", &begin1, &begin2, &n);
	
	int tempAdd;
	for(int i = 0; i < n; i++){
		scanf("%d ", &tempAdd);
		scanf("%c %d", &nodes[tempAdd].val, &nodes[tempAdd].next);
	}
	
	tempAdd = begin1;
	while(tempAdd != -1){
		word1Len++;
		tempAdd = nodes[tempAdd].next;
	}
	
	tempAdd = begin2;
	while(tempAdd != -1){
		word2Len++;
		tempAdd = nodes[tempAdd].next;
	}
	
	if(word2Len > word1Len){
		int temp = begin1;
		begin1 = begin2;
		begin2 = temp;
	}
	
	int sub = abs(word1Len - word2Len);
	while(sub){
		begin1 = nodes[begin1].next;
		sub--;
	}
	
	bool flag = false;
	while(begin1 != -1 && begin2 != -1){
		if(begin1 == begin2){
			flag = true;
			break;
		}
		begin1 = nodes[begin1].next;
		begin2 = nodes[begin2].next;
	}
	
	if(flag){
		printf("%05d",begin1);
	}else{
		printf("-1");
	}
	
	return 0;
}
