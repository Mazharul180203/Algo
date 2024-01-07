//Sliding Window problem
#include <bits/stdc++.h>
using namespace std;

void printKMax(int arr[], int N, int K)
{

    std::deque<int> Qi(K);

    int i;
    for (i = 0; i < K; ++i) {

        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])

            Qi.pop_back();
        Qi.push_back(i);
    }
    int mini = 99999999;
    for (; i < N; ++i) {


       if(arr[Qi.front()] < mini){
           mini = arr[Qi.front()];
       }

        while ((!Qi.empty()) && Qi.front() <= i - K)


            Qi.pop_front();

        while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();

        Qi.push_back(i);
    }
    if(arr[Qi.front()] < mini){
        mini = arr[Qi.front()];
    }
    cout<<mini<<"\n";

}


int main()
{
    int N, K;
    cin>>N>>K;
    int arr[N],ara[K];
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    for(int i= 0; i<K; i++){
        cin>>ara[i];
    }
    int l = 0;
    while(K--) {
        printKMax(arr, N, ara[l]);
        l++;
    }
    return 0;
}
