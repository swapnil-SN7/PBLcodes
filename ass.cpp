#include<bits/stdc++.h>
using namespace std;

void countfreq(int arr[],int n){
   vector<bool> visited(n,false);
   for(int i=0;i<n;i++){
    if(visited[i]==true){
        continue;
    }

    int count =1;
    for(int j=i+1;j<n;j++){
        if(arr[i] == arr[j]){
            visited[i]==true;
            count++;
        }
    }

    cout<< arr[i]<<" "<<count<<endl;
   }

}
int main(){
    int arr[100];
    int n;
    cout<<"Enter the number of elements in array: ";
    cin>> n;
    for(int i=0;i<n;i++){
        cout<<"Element "<<i+1<<": ";
        cin >>arr[i];
    }

    countfreq(arr,n);
}