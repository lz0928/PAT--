#include<stdio.h>
#include<map>

using namespace std;

int main(){
	
	map<int,int> maps;
	int m, n;
	
	scanf("%d %d", &m, &n);
	
	int tempColor;
	int result = 0;
	maps[0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &tempColor);
			if(maps.find(tempColor) == maps.end()){
				maps[tempColor] = 1;
			}else{
				maps[tempColor]++;
			}
			if(maps[result] < maps[tempColor]){
				result = tempColor;
			}
		}
	}
	
	printf("%d", result);
	
	return 0;
}
