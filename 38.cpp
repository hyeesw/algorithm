#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//dfs
int dfs(vector<vector<int>>& v, queue<int> queue, bool visit[]){
    int subNodes = 1; //node 수 초기화
    while(!queue.empty()){
        int curN = queue.front(); queue.pop();
        int nums = v[curN][0]; //인접노드 수
        for(int i=1; i<=nums; i++){
            int adjN = v[curN][i];
            if(!visit[adjN]){ //방문 안 한 애
                queue.push(adjN); //stack에 인접 노드 추가
                subNodes++;
                visit[adjN] = true; //미래에 방문할 것 방문 표시
            }
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
    // int testcase = 1;
    // for(int tc=0; tc<testcase; tc++){
    //     vector<vector<int> > v = {
    //         {},
    //         {1, 3},
    //         {1, 3},
    //         {3, 1, 2, 7},
    //         {0},
    //         {1, 6},
    //         {1, 5},
    //         {3, 3, 8, 9},
    //         {2, 7, 9},
    //         {2, 7, 8}
    //     };
    //     int n = 9;
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

        queue<int> queue; //빈 queue 생성
        for(int i=1; i<=n; i++){
            if(!visit[i]){ // 방문 안 함
                queue.push(i); visit[i] = true;
                int subNodes = dfs(v, queue, visit);
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