#include <bits/stdc++.h>
using namespace std;
int arr[10];

int main ()
{
    string s;
    getline(cin, s);

    cout << "Radix point : ";
    int r;
    cin >> r;

    int l = s.length();
    int rad = 0, p = 0;

    for(int i=0; i<l; i++){

        if(s[i] != ' ' && s[i] != '.' && s[i] != ',' && s[i] != ';'){
            rad += s[i] * pow(r, p);
            p++;
        }

        else{
            rad %= 10;
            arr[rad] = 1;

            rad = 0;
            p = 0;
        }

    }

    int c = 0;
    for(int i=0; i<10; i++){
        if(arr[i])
            c++;
    }

    cout << "Number of unique word = " << c;

}
