#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector <string> table(100);
ll arr[100];
ll radix;

ll h(ll k){
    return k%13;
}

void hashmap(string s){
    ll key = 0;
    for(ll i=0; i<s.length(); i++){
        key += pow(s[i], i);
    }

    ll b = 0;
    //cout << ind <<endl;
    here:

    ll ind = h(key) + b * b;

    if(!arr[ind]){
        arr[ind]++;
        table[ind] = s;
    }

    else if(table[ind] == s){
        arr[ind]++;
    }

    else{
        b++;
        goto here;
    }
}


int main ()
{
    cout << "Give your string :\n";
    string txt;
    getline(cin, txt);
    txt = ' '+txt;
    cout << txt <<endl;

    ll in;
    cout << "radix point :\n";
    cin >> in;
    radix = in;

    ll suru = 0;
    for(ll i=0; i<txt.length(); i++){

        if(txt[i] == ' ' || txt[i] == '.' || txt[i] == ',' || txt[i] == ';' || txt[i] == ':'){
            suru = i+1;

            for(i=suru; i<txt.length(); i++){

                if(txt[i] == ' ' || txt[i] == '.' || txt[i] == ',' || txt[i] == ';' || txt[i] == ':'){
                    string s = txt.substr(suru, i-suru);
                    //cout << s <<endl;
                    hashmap(s);
                    i--;
                    break;
                }
            }
        }
    }

    for(ll i=0; i<100; i++){
        if(arr[i]>0)
            cout <<"collite : "<<arr[i] << " index : "<< i << "\t" << table[i] << endl;
    }

    return 0;
}
