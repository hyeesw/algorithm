#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int memo[101][101]; //최대 부분 수열 길이 기억 m,n<=100 and dp가 bottom up이여서 basecase 지정
int path[101][101]; //경로 기억
string x, y;
int xlen, ylen;

void lcs(int m, int n){
	for(int i=1; i<=xlen; i++){
		for(int j=1; j<=ylen; j++){
			if(x[i-1] == y[j-1]) { //같다면
				memo[i][j] = memo[i-1][j-1]+1;
				path[i][j] = 0; //대각선으로 부터 왔음을 기록
			}
			else {
				memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
				//왼쪽에서 왔는지 위에서 왔는지 기록
				if(memo[i][j] == memo[i][j-1]) path[i][j]=1; //왼쪽
				else path[i][j]=2; //위
			}
		}
	}
}

void printLCS(int m, int n){
	if(m == 0 || n == 0) return;
	
	int dirc = path[m][n];
    //대각선
	if(dirc == 0){
		printLCS(m-1, n-1);
		cout << x[m-1];
	}
	else if(dirc == 1) printLCS(m, n-1); //왼쪽
	else if(dirc == 2) printLCS(m-1, n); //위
}

int main(void){
	int testcase; cin >> testcase;
	for(int tc=0; tc<testcase; tc++){
		cin >> x >> y;
		xlen = x.length();
		ylen = y.length();
		
        //memo 초기화
		for(int i=0; i<=xlen; i++){
			for(int j=0; j<=ylen; j++){
				memo[i][j] = 0;
			}
		}
		
		lcs(xlen, ylen);
        int resLen = memo[xlen][ylen];

		cout << resLen << " ";

        printLCS(xlen, ylen);
        cout << endl; //testcase 별로 개행을 넣지 않으면 알고랩은 틀린 거로 판단
	}
	return 0;
}