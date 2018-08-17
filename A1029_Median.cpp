#include<stdio.h>

const int maxn = 200010;
const int INF = 0x7fffffff;
int s1[maxn], s2[maxn];


int main(){
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &s1[i]);
	}
	s1[n] = INF;
	
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &s2[i]);
	}
	
	s2[m] = INF;
	
	int mid = (n + m - 1) /2;
	int i = 0, j = 0, count = 0;
	
	while(count < mid){
		if(s1[i] < s2[j])
			i++;
		else 
			j++;
		count++;
	}
	
	if(s1[i] > s2[j]){
		printf("%d",s2[j]);
	}else{
		printf("%d", s1[i]);
	}
	return 0;
}
