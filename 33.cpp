#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int memo[101][101]; //m,n<=100 and dp가 bottom up이여서 basecase 지정
string x, y;
int xlen, ylen;

void lcs(int m, int n){
	for(int i=1; i<=xlen; i++){
		for(int j=1; j<=ylen; j++){
			if(x[i-1] == y[j-1]) memo[i][j] = memo[i-1][j-1]+1;
			else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
		}
	}
}

int main(void){
	int testcase; cin >> testcase;
	for(int tc=0; tc<testcase; tc++){
		cin >> x >> y;
		xlen = x.length();
		ylen = y.length();
		
		for(int i=0; i<=xlen; i++){
			for(int j=0; j<=ylen; j++){
				memo[i][j] = 0;
			}
		}
		
		lcs(xlen, ylen);
		cout << memo[xlen][ylen] << endl;
	}
	return 0;
}