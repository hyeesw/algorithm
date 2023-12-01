#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

//dfs
int dfs(vector<vector<int>>& v, stack<int> stack, bool visit[]){
    int subNodes = 1; //node 수 초기화
    while(!stack.empty()){
        int curN = stack.top(); stack.pop();
        int nums = v[curN][0]; //인접노드 수
        for(int i=1; i<=nums; i++){
            stack.push(v[curN][i]); //stack에 인접 노드 추가
            visit[i] = true; //방문 표시
            subNodes++;
        }
    }
    return subNodes;
}

int main (void){
    int testcase; cin >> testcase;
    for(int tc=0; tc<testcase; tc++){
        vector<vector<int> > v;
        vector<int> v2; v.push_back(v2); //0번째는 빈 배열
        
        int n; cin >> n;
        for(int i=0; i<n; i++){
            int idx, nums; cin >> idx >> nums;
            vector<int> v2;
            v2.push_back(nums);
            for(int j=1; j<=nums; j++){
                int node; cin >> node;
                v2.push_back(node);
            }
            v.push_back(v2);
        }
        // v 완성.
        // cout << "완성" << endl;
        // for(int i=0; i<v.size(); i++) {
        //     for(int j=0; j<v[i].size(); j++){
        //         cout << v[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        bool visit[n+1]; //visit 배열 만들기
        for(int i=1; i<=n; i++) visit[i] = false;

        vector<int> subG; //정답 담을 vector

        stack<int> stack; //빈 stack 생성
        for(int i=1; i<=n; i++){
            if(!visit[i]){ // 방문 안 함
                stack.push(i); visit[i] = true;
                int subNodes = dfs(v, stack, visit);
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
//0일때 출력만 살짝 관리
