//lcs - memoization
#include <iostream>
#include <string>
#include <algorithm> //max

using namespace std;

int memo[100][100]; //m,n<=100
string x, y;
int xlen, ylen;

int lcs(int m, int n){
	if(m<=-1 || n<=-1) return 0; //재귀 basecase
	if(memo[m][n] != -1) return memo[m][n]; //계산된 결과가 있는지
	
	//재귀로 파고 들어가기
	int result;
	if(x[m]==y[n]) result = lcs(m-1, n-1)+1;
	else result = max(lcs(m-1, n), lcs(m, n-1));
	
	memo[m][n] = result; //memo에 저장
    
    return result;
	}

int main(void){
	int testcase; cin >> testcase;
	// int testcase = 1;
	for(int tc=0; tc<testcase; tc++){
		cin >> x >> y;
        // x = "abcb"; y = "aceb";
        int xlen = x.length();
        int ylen = y.length();
		// xlen = 4; ylen = 4;

        //memo 초기화
        for(int i=0; i<xlen; i++){
            for(int j=0; j<ylen; j++){
                memo[i][j] = -1;
            }
        }

		lcs(xlen-1, ylen-1);
        // for(int i=0; i<xlen; i++){
        //     for(int j=0; j<ylen; j++){
        //         cout << memo[i][j] << " ";
        //     }
		// 	cout << endl;
        // }
		cout << memo[xlen-1][ylen-1] << endl;
	}
	return 0;
}