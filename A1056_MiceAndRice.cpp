#include<stdio.h>
#include<queue>

using namespace std;

const int maxn = 1010;

struct Mouse{
	int weitght;
	int rank;
}mouse[maxn];

queue<int> que;

int main(){
	
	int np, ng;//���ӵ����� ÿ������� 
	scanf("%d %d", &np, &ng);
	for(int i = 0; i < np; i++){
		scanf("%d", &mouse[i].weitght);//����ÿֻ���ӵ����� 
	}
	
	int order;
	for(int i = 0; i < np; i++){
		scanf("%d", &order);
		que.push(order);//��˳�������ı����� 
	}
	
	int temp = np, group;
	
	while(que.size() != 1){
		group = temp %ng == 0 ? temp / ng : temp / ng + 1;
		for(int i = 0; i < group; i++){
			int k = que.front();
			for(int j = 0; j < ng; j++){
				if(i * ng + j >= temp) break;
				int front = que.front();
				if(mouse[front].weitght > mouse[k].weitght){
					k = front;
				}
				mouse[front].rank = group + 1;
				que.pop();
			}
			que.push(k);
		}
		temp = group;
	}
	mouse[que.front()].rank = 1;
	
	for(int i = 0; i < np; i++){
		printf("%d", mouse[i].rank);
		if(i < np - 1) printf(" ");
	}
	 
	return 0;
}
