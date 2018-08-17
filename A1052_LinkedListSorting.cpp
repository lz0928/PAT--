#include<stdio.h>
#include<algorithm>

using namespace std;

const int maxn = 100010;

struct node{
	int address, val, next, flag;
}nodes[maxn];

bool cmp(node a, node b){
	if(a.flag == 0 || b.flag == 0){
		return a.flag > b.flag;
	}
	return a.val < b.val;
}

int main(){
	
	for(int i = 0; i < maxn; i++){
		nodes[i].flag = 0;
	}
	
	int n, begin;
	
	scanf("%d %d", &n, &begin);
	
	int tempAdd;
	for(int i = 0; i < n; i++){
		scanf("%d", &tempAdd);
		scanf("%d %d", &nodes[tempAdd].val, &nodes[tempAdd].next);
		nodes[tempAdd].address = tempAdd;
	}
	
	int p = begin;
	int count = 0;
	while(p != -1){
		nodes[p].flag = 1;
		count++;
		p = nodes[p].next;
	}
	
	if(count == 0){
		printf("0 -1");
	}else{
		sort(nodes, nodes + maxn, cmp);
		printf("%d %05d\n", count, nodes[0].address);
		for(int i = 0; i < count; i++){
			if(i < count - 1)
				printf("%05d %d %05d\n", nodes[i].address, nodes[i].val, nodes[i + 1].address);
			else{
				printf("%05d %d -1\n", nodes[i].address, nodes[i].val);
			}
		}
	}
	
	
	return 0;
}
