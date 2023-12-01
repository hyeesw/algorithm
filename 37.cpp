#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

//dfs
int dfs(vector<vector<int> >& v, stack<int> stack, bool visit[]){
    int subNodes = 1; //node 수 초기화
    while(!stack.empty()){
        int curN = stack.top(); stack.pop();
        int nums = v[curN][0]; //인접노드 수
        for(int i=1; i<=nums; i++){
            int adjN = v[curN][i];
            if(!visit[adjN]){ //방문 안 한 애
                stack.push(adjN); //stack에 인접 노드 추가
                subNodes++;
            }
            visit[adjN] = true; //미래에 방문할 것 방문 표시
        }
    }
    return subNodes;
}

int main (void){
    int testcase = 1;
    for(int tc=0; tc<testcase; tc++){
        vector<vector<int> > vec = {
            {},
            {1, 3},
            {1, 3},
            {3, 1, 2, 7},
            {0},
            {1, 6},
            {1, 5},
            {3, 3, 8, 9},
            {2, 7, 9},
            {2, 7, 8}
        };
        int n = 9;

        // v 완성.
        bool visit[n+1]; //visit 배열 만들기
        for(int i=1; i<=n; i++) visit[i] = false;

        vector<int> subG; //정답 담을 vector

        stack<int> stack; //빈 stack 생성
        for(int i=1; i<=n; i++){
            if(!visit[i]){ // 방문 안 함
                stack.push(i); visit[i] = true;
                int subNodes = dfs(vec, stack, visit);
                subG.push_back(subNodes); //정답 기록
            }
        }
        //모두 방문함.
        sort(subG.begin(), subG.end()); //subG 오름차순 정렬
        cout << subG.size() << " ";
        for(int i=0; i<subG.size(); i++) {
            cout << subG[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
