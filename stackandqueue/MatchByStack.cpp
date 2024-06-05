//
// Created by 陈远航 on 2024/6/4.
// 用栈实现括号匹配
//
#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 * 判断括号是否匹配
 * @param str
 * @return
 */
bool match(string str) {
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            if ((top == '(' && str[i] == ')') || (top == '[' && str[i] == ']') || (top == '{' && str[i] == '}')) {
                s.pop();
            } else {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    string str;
    cin >> str;
    cout << (match(str) ? "匹配" : "不匹配") << endl;
    return 0;
}
