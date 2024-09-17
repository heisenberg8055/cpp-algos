#include <bits/stdc++.h>
#include <sstream>
using namespace std;

string getLineSingle() {
  string str;
  getline(cin, str);
  return str;
}

vector<string> getLineMultipleDelimiter() {
  vector<string> arr;
  string s, t;
  getline(cin, s);
  stringstream X(s);
  while (getline(X, t, ' ')) {
    arr.push_back(t);
  }
  return arr;
}

int main() {
  // getline single input
  //   cout << getLineSingle()<<"\n";

  // getline multiple inputs with delimiter
  //   vector<string> arr = getLineMultipleDelimiter();
  //   for (auto it : arr) {
  //     cout << it << "\n";
  //   }

  stringstream s;
  s<<123;
  string x;
  s>>x;
  cout << x;
}