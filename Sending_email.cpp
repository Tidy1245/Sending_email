#include <cstdio>
#include<iostream>
#define INF 100010
using namespace std;
int main(){
    int times;
    int n, m, s, t;
    int i, j, k;
    cin>>times;
    for(i=1; i<=times; i++){
        cin>>n>>m>>s>>t;
        int cost[n][n];//紀錄初始連結距離
        int min_dis[n];//紀錄起點到每個點的最小距離
        int S[n];//走過為1，未走過為0
        for(j=0; j<n; j++)//初始化
            for(k=0; k<n; k++)
                cost[j][k] = INF;
        for(j=0; j<n; j++){
            cost[j][j] = 0;
            min_dis[j] = INF;
            S[j] = 0;
        }
        min_dis[s] = 0;
        S[s] = 1;//初始化
        while(m--){//輸入邊
            int from, to, weight;
            cin>>from>>to>>weight;
            if(from != to){//相等時必須為0
                if(cost[from][to] != INF && cost[from][to] < weight)
                    continue;//若該邊已經被輸入過則只取較小的權重
                cost[from][to] = weight;
                cost[to][from] = weight;
            }
        }
        for(j=0; j<n; j++)//先做第1次
            min_dis[j] = cost[s][j];
        int run = 1;
        int v = s;
        while(run < n){
            int m = INF;
            for(j=0; j<n; j++){
                if(S[j] == 0){
                    if(min_dis[j] < m){
                        m = min_dis[j];
                        v = j;
                    }//從未走訪中選定本回合的最小的路徑
                }
            }
            S[v] = 1;
            run++;
            for(j=0; j<n; j++){
                if(S[j] == 0){
                    min_dis[j] = min(min_dis[j], min_dis[v] + cost[v][j]);
                }//更新最短路徑
            }
        }
        if(min_dis[t] == INF)
            cout<<"Case #"<<i<<": unreachable";
        else
             cout<<"Case #"<<i<<": "<<min_dis[t];
        if(i<times)
            cout<<endl;
    }
    return 0;
}
