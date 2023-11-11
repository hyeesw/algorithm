//lcs - recursion
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int lcs(string x, string y, int m, int n){
	if(m<=-1 || n<=-1) return 0;
	else if(x[m]==y[n]) return lcs(x, y, m-1, n-1)+1;
	else return max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));
}

int main(void){
	int testcase; cin >> testcase;
	for(int tc=0; tc<testcase; tc++){
		string x, y;
		cin >> x >> y;
		int result = lcs(x, y, x.length()-1, y.length()-1);
		cout << result << endl;
	}
	return 0;
}