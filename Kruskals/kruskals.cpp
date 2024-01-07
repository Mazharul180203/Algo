//
// Kruskals algorithm ** DSU **
//
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e4+5;
typedef long long ll;
int id[MAX], nodes, edges;
pair<ll, pair<ll,ll> > p[MAX];
void initialize(){
    for (int i = 0; i < MAX; ++i) {
        id[i] = i;
    }
}

int root(int x){   /// Checking cycle or not

    while(id[x] != x){

        id[x] = id[id[x]]; /// a base parent
        x = id[x];
    }
    return x;
}

void union1(int x, int y){
    int p = root(x);
    int q = root(y);

    id[p] = id[q];  /// assign the base parent to the index
}


ll kruskals(pair<ll,pair<ll,ll>>p[]){
    int x,y;
    ll cost, minimumCost = 0;
    for (int i = 0; i <edges ; ++i) {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;

        if(root(x) != root(y)){
            minimumCost += cost;
            union1(x,y);
        }

    }
    return minimumCost;
}
int main(){

    int x,y;
    ll weight, cost, minimumCost;
    initialize();
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++){
        cin>>x>>y>>weight;
        p[i] = make_pair(weight, make_pair(x,y));
    }

    sort(p,p+edges);

    minimumCost = kruskals(p);

    cout<<minimumCost<<"\n";

}