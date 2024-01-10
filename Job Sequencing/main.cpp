//Job Sequencing Problem

#include<bits/stdc++.h>
using namespace std;

bool comaparesecond(const pair<int,pair<int,int>> &a, const pair<int,pair<int,int>> &b){
    return a.second.first >  b.second.first;
}


int main(){

    vector<pair<char,pair<int,int>>> data;   // job, deadline, profit

    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int second,third;
        char first;
        cin>>first>>second>>third;
        data.push_back(make_pair(first, make_pair(second,third)));
    }

    sort(data.begin(),data.end(),comaparesecond);
    bool ara[n];
    char res[n];
    for(int i=0; i<n; i++) {
        ara[i] = false;
        res[i] = '\0';
    }
    int cost = 0;
    for(int i=0; i<n; i++){
        for(int j = data[i].second.first - 1; j>=0; j--){
            if(!ara[j]){
                res[j] = data[i].first;
                ara[j] = true;
                cost+= data[i].second.second;
                break;
            }
        }
    }

    for(int i=0; i<n; i++){
        if(res[i]!='\0') cout<<res[i]<<" ";
    }
    cout<<"\n";
    cout<<cost<<"\n";
}