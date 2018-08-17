#include<stdio.h>
#include<stack>
#include<iostream>

using namespace std;

const int maxn = 1010;
int arr[maxn];
stack<int> st;

int main(){
	
	int m, n, k;//栈容量 序列长度  要检查的序列个数 
	scanf("%d %d %d", &m, &n, &k);
	
	for(int i = 0; i < k; i++){
		
		while(!st.empty()){
			st.pop();
		}
		
		for(int j = 1; j <= n; j++){
			scanf("%d", &arr[j]);
		}
		
		bool flag = true;
		int current = 1;		
		for(int j = 1; j <= n; j++){
			st.push(j);
			if(st.size() > m){
				flag = false;
				break;
			}
			
			while(!st.empty() && st.top() == arr[current]){
				st.pop();
				current++;
			}
		}
		if(st.empty() == true && flag == true){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

	return 0;
}
