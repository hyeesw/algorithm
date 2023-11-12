#include <iostream>
#include <algorithm>
#include <climits> //INT_MAX

using namespace std;

int d[11]; //dimension
int arrNum;

int cmc(int s, int e){
	if(s==e) return 0;
	
	int min_multi = INT_MAX;
	
	for(int k=s; k<=e-1; k++){
		int temp_multi = cmc(s,k) + cmc(k+1, e) + d[s-1]*d[k]*d[e];
		min_multi = min(temp_multi, min_multi);
	}
	return min_multi;
}

int main(void){
	int testcase; cin >> testcase;
	for(int tc=0; tc<testcase; tc++){
		cin >> arrNum; // 행렬 총 개수
		//dimension 배열 채우기 (n+1)개
		for(int i=0; i<=arrNum; i++){
			cin >> d[i];
		}
		int res = cmc(1, arrNum); // 1~4개의 행렬 곱에 대해
		
		cout << res << endl;
	}
	return 0;
}