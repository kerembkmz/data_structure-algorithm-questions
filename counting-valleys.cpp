#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */


int countingValleys(int steps, string path) {
    int valleyNumber = 0;
    stack<int> mountainStack;
    int level = 0;
    
    
    for (int i = 0; i < steps; i++) {
        if (level == 0) {
            if (path[i] == 'D'){
                valleyNumber += 1;
                level -= 1;
            }
            if (path[i] == 'U'){
                level += 1;
            }
        } else {
            if (path[i] == 'D'){
                level -= 1;
            }
            if (path[i] == 'U'){
                level += 1;
            }
        }
    }

    return valleyNumber;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

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
