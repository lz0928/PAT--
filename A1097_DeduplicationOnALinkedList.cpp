#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn = 100010;

struct node{
	int address, val, next, order;
	bool flag;
}nodes[maxn];

bool cmp(node a, node b){
	return a.order < b.order;
}

bool isExit[maxn] = {false};//当前枚举到的数是否已出现 

int main(){
	
	for(int i = 0; i < maxn; i++){
		nodes[i].order = 2 * maxn;
		nodes[i].flag = false;
	}
	
	vector<int> originVec;
	vector<int> newVec;
	int begin, n;	
	int tempAdd;
	int validCount = 0;
	int removedCount = 0; 
	
	scanf("%d %d", &begin, &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &tempAdd);
		scanf("%d %d", &nodes[tempAdd].val, &nodes[tempAdd].next);
		nodes[tempAdd].address = tempAdd;
		nodes[tempAdd].val = nodes[tempAdd].val < 0 ?  nodes[tempAdd].flag = true, -nodes[tempAdd].val : nodes[tempAdd].val;
	}
	
	tempAdd = begin;
	while(tempAdd != -1){
		
		if(isExit[nodes[tempAdd].val] == false){
			nodes[tempAdd].order = validCount++;
			isExit[nodes[tempAdd].val] = true;
		}else{
			nodes[tempAdd].order = maxn + removedCount++;
		}
		tempAdd = nodes[tempAdd].next;
	}
	
	sort(nodes, nodes + maxn, cmp);
	
	for(int i = 0; i < validCount; i++){
		if(nodes[i].flag == true){
			nodes[i].val = -nodes[i].val;
		}
		if(i == validCount - 1){
		 	printf("%05d %d -1\n", nodes[i].address, nodes[i].val);
		}else{
		 	printf("%05d %d %05d\n", nodes[i].address, nodes[i].val, nodes[i + 1].address);
		}
	}
	
	for(int i = validCount; i < validCount + removedCount; i++){
		if(nodes[i].flag == true){
			nodes[i].val = -nodes[i].val;
		}
		if(i == validCount + removedCount - 1){
		 	printf("%05d %d -1\n", nodes[i].address, nodes[i].val);
		}else{
		 	printf("%05d %d %05d\n", nodes[i].address, nodes[i].val, nodes[i + 1].address);
		}
	}	
	return 0;
}
