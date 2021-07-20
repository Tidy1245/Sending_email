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
        int cost[n][n];//������l�s���Z��
        int min_dis[n];//�����_�I��C���I���̤p�Z��
        int S[n];//���L��1�A�����L��0
        for(j=0; j<n; j++)//��l��
            for(k=0; k<n; k++)
                cost[j][k] = INF;
        for(j=0; j<n; j++){
            cost[j][j] = 0;
            min_dis[j] = INF;
            S[j] = 0;
        }
        min_dis[s] = 0;
        S[s] = 1;//��l��
        while(m--){//��J��
            int from, to, weight;
            cin>>from>>to>>weight;
            if(from != to){//�۵��ɥ�����0
                if(cost[from][to] != INF && cost[from][to] < weight)
                    continue;//�Y����w�g�Q��J�L�h�u�����p���v��
                cost[from][to] = weight;
                cost[to][from] = weight;
            }
        }
        for(j=0; j<n; j++)//������1��
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
                    }//�q�����X����w���^�X���̤p�����|
                }
            }
            S[v] = 1;
            run++;
            for(j=0; j<n; j++){
                if(S[j] == 0){
                    min_dis[j] = min(min_dis[j], min_dis[v] + cost[v][j]);
                }//��s�̵u���|
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
