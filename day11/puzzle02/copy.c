#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include <utility>
#include <vector>
#include <cstdlib>
#include <string.h>

using namespace std::chrono;

using namespace std;
#define ll long long

int main() {
  auto start = high_resolution_clock::now();

  string str;
  vector<vector<ll>> items; //stores all the items contained by the monkeys;
  vector<string> operation; //stores the operation performed by monkey on each item
  vector<int> test; //stores the divisibility test
  vector<pair<int, int>> options; //stores where the monkey throws the item to

    std::ifstream	fd("input.txt");
  // parsing the data
  while (getline(fd, str)) {
    if (str[0] == 'M') { //this is a monkey
      // first line of monkey is the starting item
      getline(fd, str);
      stringstream s(str);
      string word;
      int cnt = 0;
      while (cnt < 2) {
        s >> word;
        cnt++;
      }
      vector<ll> tempItem;
      while (s >> word) {
        tempItem.push_back(stoi(word));
      }
      items.push_back(tempItem);

      //next is the operation
      getline(fd, str);
      stringstream s1(str);
      cnt = 0;
      while (cnt < 4) {
        s1 >> word;
        cnt++;
      }
      string tempOp;
      while (s1 >> word) {
        tempOp += word;
      }
      operation.push_back(tempOp);

      //next is the divisibility test;
      getline(fd, str);
      cnt = 0;
      stringstream s2(str);
      while (cnt < 4) {
        s2 >> word;
        cnt++;
      }
      s2 >> word;
      test.push_back(stoi(word));

      //next are the two options
      getline(fd, str);
      int op1 = str.back() - '0';
      getline(fd, str);
      int op2 = str.back() - '0';
      options.push_back(make_pair(op1, op2));
    }
  }

  int monkeys = items.size();
  ll lcm = 1;
  for (int i = 0; i < monkeys; i++) {
    lcm *= test[i];
  }
  vector<ll> inspection(monkeys, 0ll);

  for (int round = 1; round <= 10000; round++) {
    for (int i = 0; i < monkeys;  i++) {
      inspection[i] += items[i].size();
      for (int j = 0; j < items[i].size(); j++) {
        if (operation[i].substr(1) == "old") {
          switch (operation[i][0]) {
          case '+':
            items[i][j] += items[i][j];
            break;
          case '-':
            items[i][j] -= items[i][j];
            break;
          case '*':
            items[i][j] *= items[i][j];
            break;
          case '/':
            items[i][j] /= items[i][j];
            break;
          }
          items[i][j] %= lcm;
          std::cout << lcm << std::endl;
          if (items[i][j] % test[i]) {
            items[options[i].second].push_back(items[i][j]);
          }
          else {
            items[options[i].first].push_back(items[i][j]);
          }
        }
        else {
          switch (operation[i][0]) {
          case '+':
            items[i][j] += stoi(operation[i].substr(1));
            break;
          case '-':
            items[i][j] -= stoi(operation[i].substr(1));
            break;
          case '*':
            items[i][j] *= stoi(operation[i].substr(1));
            break;
          case '/':
            items[i][j] /= stoi(operation[i].substr(1));
            break;
          }
          items[i][j] %= lcm;
          if (items[i][j] % test[i]) {
            items[options[i].second].push_back(items[i][j]);
          }
          else {
            items[options[i].first].push_back(items[i][j]);
          }
        }
      }
      items[i].clear();
    }
  }

  
  sort(inspection.rbegin(), inspection.rend());
  ll ans = inspection[0] * inspection[1];
  cout << ans << endl;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Time: " << duration.count() << " microseconds:" << endl;
}