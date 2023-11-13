#include <iostream>
#include <algorithm> //min
#include <climits> //INT_MAX

using namespace std;

int cmcMemo[101][101]; //m(i,k) 배열에 기록해서 재활용
int path[101][101]; //잘라지는 부분 기록
int d[101]; //dimension
int arrNum;

void cmc(int s, int e){
    for(int i=1; i<=arrNum; i++){
        cmcMemo[i][i] = 0; //대각선 0으로 채우기
    }

    for(int diag=1; diag<=arrNum-1; diag++){
        for(int i=1; i<=arrNum-diag; i++){ //행
            int j=i+diag; //열
            int min_multi = INT_MAX;
            int cut_idx = 0;
            for(int k=i; k<=j-1; k++){
                int temp_multi = cmcMemo[i][k]+cmcMemo[k+1][j]+d[i-1]*d[k]*d[j];
                if(temp_multi < min_multi){
                    min_multi = temp_multi;
                    cut_idx = k;
                }
            }
            cmcMemo[i][j] = min_multi;
            path[i][j] = cut_idx;
        }
    }

}
void printCMC(int s, int e){
	if(s==e){
		cout << "M" << s;
	}
	else{
		int k = path[s][e];
		cout << "(";
		printCMC(s, k);
		printCMC(k+1, e);
		cout << ")";
	}
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
		
        printCMC(1, arrNum); cout << endl;
		cout << cmcMemo[1][arrNum] << endl;

	}
	return 0;
}