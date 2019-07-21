#include <bits/stdc++.h>
using namespace std;
int radix;
int arr[13];

void hashmap(string s){
    int r = 0;

    for(int i=0; i<s.length(); i++){
        r += s[i] * pow(radix, i);
    }

    r %= 13;
    cout << r << endl;
    arr[r]++;
}

int main ()
{
    cout << "I'm sorry for collision.\nGive your string :\n";
    string txt;
    getline(cin, txt);
    txt = ' '+txt;

    int in;
    cout << "radix point :\n";
    cin >> in;
    radix = in;

    int suru = 0;
    for(int i=0; i<txt.length(); i++){

        if(txt[i] == ' ' || txt[i] == '.' || txt[i] == ',' || txt[i] == ';' || txt[i] == ':'){
            suru = i+1;

            for(i=suru; i<txt.length(); i++){

                if(txt[i] == ' ' || txt[i] == '.' || txt[i] == ',' || txt[i] == ';' || txt[i] == ':'){
                    string s = txt.substr(suru, i-suru-1);
                    hashmap(s);
                    i--;
                    break;
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<13; i++){
        if(arr[i] > 0)
            ans++;
    }

    cout << ans;

    return 0;
}

