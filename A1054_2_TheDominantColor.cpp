#include<stdio.h>

int main(){
	
	int m, n;
	scanf("%d %d", &m, &n);
	
	int ans = -1, count = 0, tempColor;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &tempColor);
			if(ans != tempColor){
				if(count == 0){
					ans = tempColor;
					count = 1;
				}else{
					count--;
				}
			}else{
				count++;
			}
		}
	}
	
	printf("%d", ans);
	return 0;
}
