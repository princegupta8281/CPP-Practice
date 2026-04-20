#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;

    int product = 1;

    for(int x=1; x<=n; x++){
        product *= x;
    }

    cout<<product;
}