#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll radix;
ll arr[13];

void hashmap(string s){
    ll r = 0;

    for(ll i=0; i<s.length(); i++){
        r += s[i] * pow(radix, i);
    }

    r %= 13;
    //cout << r << endl;
    arr[r]++;
}

int main ()
{
    cout << "I'm sorry for collision.\nGive your string :\n";
    string txt;
    getline(cin, txt);
    txt = ' '+txt;

    ll in;
    cout << "radix poll :\n";
    cin >> in;
    radix = in;

    ll suru = 0;
    for(ll i=0; i<txt.length(); i++){

        if(txt[i] == ' ' || txt[i] == '.' || txt[i] == ',' || txt[i] == ';' || txt[i] == ':'){
            suru = i+1;

            for(i=suru; i<txt.length(); i++){

                if(txt[i] == ' ' || txt[i] == '.' || txt[i] == ',' || txt[i] == ';' || txt[i] == ':'){
                    string s = txt.substr(suru, i-suru);
                    hashmap(s);
                    i--;
                    break;
                }
            }
        }
    }

    ll ans = 0;
    for(ll i=0; i<13; i++){
        if(arr[i] > 0)
            ans++;
    }

    cout <<"Number of unique words : "<< ans;

    return 0;
}

