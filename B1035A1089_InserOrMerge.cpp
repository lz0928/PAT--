#include<stdio.h>
#include<algorithm>

using namespace std;

const int maxn = 110;

int ori_arr[maxn], temp_ori_arr[maxn], target_arr[maxn];//源数组，源数组备份，目标数组 
int n;//数组元素个数 

//判断两个数组是否相等 
bool is_same_array(){
	for(int i = 0; i < n; i++){
		if(temp_ori_arr[i] != target_arr[i]){
			return false;
		}
	}
	return true;
}

void show_array(){
	for(int i = 0; i < n; i++){
		printf("%d", temp_ori_arr[i]);
		if(i != n - 1){
			printf(" ");
		}
	}
}

bool insert_sort(){
	bool flag = false;
	for(int i = 0; i < n; i++){
		int j = i;
		int temp = temp_ori_arr[i];
		while(j > 0 && temp_ori_arr[j - 1] > temp){
			temp_ori_arr[j] = temp_ori_arr[j - 1];
			j--;
		}
		temp_ori_arr[j] = temp;
		if(flag){
			return true;
		}else if(i != 0 && is_same_array()){
			flag = true;
		}
	}
	return flag;
}

bool merge_sort(){
	
	bool flag = false;
	
	for(int step = 2; step/2 <= n; step *= 2){
		for(int i = 0; i < n; i += step){
			sort(temp_ori_arr + i, temp_ori_arr + min(i + step, n));
		}
		if(flag == true){
			break;
		}else if(is_same_array()){
			flag = true;
		}
	}
	show_array();
}

int main(){
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &ori_arr[i]);
		temp_ori_arr[i] = ori_arr[i];
	}
	
	for(int i = 0; i < n; i++){
		scanf("%d", &target_arr[i]);
	}
	
	if(insert_sort()){
		printf("Insertion Sort\n");
		show_array();
	}else{
		printf("Merge Sort\n");
		for(int i = 0; i < n; i++){
			temp_ori_arr[i] = ori_arr[i];
		}
		merge_sort();
	}
	
	return 0;
} 
