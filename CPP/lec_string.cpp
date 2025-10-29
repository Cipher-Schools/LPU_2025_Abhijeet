#include <iostream>
#include <string>
using namespace std;

string my_substr(string s, int pos, int n) {
    string ans = "";

    if (pos < 0 || pos >= (int)s.size())
        return ans;

    for (int i = pos; i < min((int)s.size(), pos + n); i++) {
        ans += s[i];
    }
    return ans;
}


int  my_find(string s , string sub) {

    int n = s.size();
    int m = sub.size();
    for (int i =0 ;i<=n-m;i++) {
        bool found = true;
        for (int j = 0;j<m;j++) {
            if (s[i+j] != sub[j]) {
                found = false;
            }
        }
        if (found) {
            return i;
        }
    }

    return  -1 ;
}

int main() {
    string s1 = "Abhijeet";
    cout<<my_find("Abhijeet" , "jeet") ;
}
