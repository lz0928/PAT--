#include<stdio.h>
#include<algorithm>

using namespace std;

const int maxn = 100010;

struct node{
	int address, value, next;	
	int order;
}nodes[maxn];

bool cmp(node a, node b){
	return a.order < b.order;
}

int main(){
	
	for(int i = 0; i < maxn; i++){
		nodes[i].order = maxn;
	}
	
	
	int startAdd, n, k;//链表起始地址， 结点总个数， 要求反转的子链节点的个数
	scanf("%d %d %d", &startAdd, &n, &k);
	
	int tempAdd;
	for(int i = 0; i < n; i++){
		scanf("%d", &tempAdd);//读入当前节点地址 
		scanf("%d %d", &nodes[tempAdd].value, &nodes[tempAdd].next);//读入当前节点的值和下一个节点 
		nodes[tempAdd].address = tempAdd;
	}
	
	int begin = startAdd;
	int nodesCount = 0;
	while(begin != -1){
		nodes[begin].order = nodesCount++;
		begin = nodes[begin].next;
	}
	
	sort(nodes, nodes + maxn, cmp);
	
	int group = nodesCount / k;
	int cur;
	for(int i = 1; i <= group; i++){
		for(int j = 1; j < k; j++){
			cur = i * k - j;
			printf("%05d %d %05d\n", nodes[cur].address, nodes[cur].value, nodes[cur-1].address);
		} 
		cur = i * k - k;
		if(cur + k == nodesCount)
		{
			printf("%05d %d -1\n", nodes[cur].address, nodes[cur].value);
		}
		else{
			if(i == group)
				printf("%05d %d %05d\n", nodes[cur].address, nodes[cur].value, nodes[i * k].address);
			else{
				printf("%05d %d %05d\n", nodes[cur].address, nodes[cur].value, nodes[(i+1) * k - 1].address);
			}
		}
	}
	
	int leftNodesCount = nodesCount % k;
	for(int i = 0; i < leftNodesCount - 1; i++){
		cur = nodesCount - leftNodesCount + i;
		printf("%05d %d %05d\n", nodes[cur].address, nodes[cur].value, nodes[cur].next);
	}
	if(leftNodesCount > 0)
		printf("%05d %d %d\n", nodes[nodesCount - 1].address, nodes[nodesCount - 1].value, nodes[nodesCount - 1].next);
	return 0;
}
