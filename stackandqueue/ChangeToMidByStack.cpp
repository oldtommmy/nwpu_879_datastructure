//
// Created by 陈远航 on 2024/6/4.
// 中缀表达式转后缀表达式

#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 * 判断是否是操作符
 * @param c
 * @return
 */
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

/**
 * 判断操作符优先级
 * @param c
 * @return
 */
int priority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

/** 拓展 🌟
 * 中缀表达式转后缀表达式
 * @param str
 * @return
 */
string changeToMid(string str) {
    stack<char> s;
    string res;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            res += str[i];
        } else if (str[i] == '(') {
            s.push(str[i]);
        } else if (str[i] == ')') {
            while (s.top() != '(') {
                res += s.top();
                s.pop();
            }
            s.pop();
        } else if (isOperator(str[i])) {
            while (!s.empty() && priority(s.top()) >= priority(str[i])) {
                res += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while (!s.empty()) {
        res += s.top();
        s.pop();
    }
    return res;
}

int main() {
    string str;
    cin >> str; // 1+2*3-(4+5)/6
    cout << changeToMid(str) << endl;
    return 0;
}
