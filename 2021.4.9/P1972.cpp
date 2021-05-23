// Problem: [SDOI2009]HH的项链
// Contest: 题目列表
// URL: https://www.luogu.com.cn/problem/P1972
// Memory Limit: 500 MB
// Time Limit: 1500 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
class Module {
  virtual std::string getClassName() = 0;
  virtual bool isDataClass() = 0;
};
class User : public Module {
  std::string getClassName() { return "User"; }
  bool isDataClass() { return true; }
};
