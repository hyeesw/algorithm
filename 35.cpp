#include <iostream>
#include <algorithm>
#include <climits> //INT_MAX

using namespace std;

int cmcMemo[101][101]; //m(i,k) 배열에 기록해서 재활용
int d[101]; //dimension
int arrNum;

void cmc(int s, int e){
	if(s==e) return;

	int min_multi = INT_MAX;
	
	for(int k=s; k<=e-1; k++){
		//저장된 값이 있는지 확인 (memoization은 그냥 사용 전 값이 있는지 확인하는 방식으로 가야함.)
		if(cmcMemo[s][k] == -1) cmc(s,k);
		if(cmcMemo[k+1][e] == -1) cmc(k+1,e);
		
		int temp_multi = cmcMemo[s][k] + cmcMemo[k+1][e] + d[s-1]*d[k]*d[e];
		min_multi = min(temp_multi, min_multi);
	}
	cmcMemo[s][e] = min_multi;
}

int main(void){
	int testcase; cin >> testcase;
	for(int tc=0; tc<testcase; tc++){
		cin >> arrNum; // 행렬 총 개수
		//dimension 배열 채우기 (n+1)개
		for(int i=0; i<=arrNum; i++){
			cin >> d[i];
		}
		//cmcMemo 초기화
		for(int i=1; i<=arrNum; i++){
			for(int j=1; j<=arrNum; j++){
				if(i==j) cmcMemo[i][i] = 0;
				else if(i<j) cmcMemo[i][j] = -1;
			}
		}
		cmc(1, arrNum); // 1~4개의 행렬 곱에 대해
		
		cout << cmcMemo[1][arrNum] << endl;
	}
	return 0;
}