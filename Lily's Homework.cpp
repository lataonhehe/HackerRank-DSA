#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int lilysHomework(vector<int> arr) {
    vector<int> arr1 = arr;
    unordered_map<int,int>mp;
    unordered_map<int,int>mp1;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]=i;
        mp1[arr[i]]=i;
}
    vector<int> v(arr);
    vector<int> v1(arr1);
    sort(v.begin(),v.end());
    sort(v1.begin(),v1.end(),greater<int>());
    int c=0,c1=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=v[i]){
            c++;

            int t1=mp[v[i]];
            mp[arr[i]]=t1;
            swap(arr[i],arr[t1]);
        }
    }
     for(int i=0;i<arr1.size();i++){
        if(arr1[i]!=v1[i]){
            c1++;
            int t1=mp1[v1[i]];
            mp1[arr1[i]]=t1;
            swap(arr1[i],arr1[t1]);
        }
    }
    return min(c,c1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
