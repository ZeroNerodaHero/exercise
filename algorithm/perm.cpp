#include <bits/stdc++.h>
using namespace std;

string s;
int n;

void perm(int i){
    if(i == n){
        cout << s << endl;
        return;
    }
    for(int j = i; j < n; j++){
        swap(s[i],s[j]);
        perm(i+1);
        swap(s[i],s[j]);
    }
}

void nperm(int i){
    if(i == n){
        cout << s << endl;
        return;
    }
    for(int j = i; j < n; j++){
        char tmp = s[j];
        for(int k = j; k > i; k--){
            s[k] = s[k-1];
        }
        s[i] = tmp;
        nperm(i+1);
        for(int k = i; k < j; k++){
            s[k] = s[k+1];
        }
        s[j] = tmp;
    }
}

int main(){
    s = "1234";
    n = s.size();
    nperm(0);
    cout << endl;
    perm(0);
}
