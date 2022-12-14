#include <iostream>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

using CntMap = std::map<long, long>;

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r)
{
    CntMap count1;
    CntMap count2;
    CntMap count3;

    for (auto elem : arr) {
        if (elem % r == 0) {
            auto prev = elem / r;
            count3[elem] += count2[prev];
            count2[elem] += count1[prev];
        }

        count1[elem]++;
    }
    return std::accumulate(count3.cbegin(), count3.cend(), 0L,
        [](const auto prev, const auto &pairTfu){
            return prev + pairTfu.second;
        });
}

int main()
{
    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    std::cout << ans << "\n";

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
