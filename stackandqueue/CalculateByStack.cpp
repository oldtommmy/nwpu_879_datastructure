//
// Created by 陈远航 on 2024/6/5.
//
#include "iostream"
#include "stack"
#include "string"

using namespace std;

/**
 * 计算后缀表达式
 * @param str
 * @return
 */
int calculate(string str) {
    stack<int> s;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            s.push(str[i] - '0');
        } else {
            int num2 = s.top();
            s.pop();
            int num1 = s.top();
            s.pop();
            switch (str[i]) {
                case '+':
                    s.push(num1 + num2);
                    break;
                case '-':
                    s.push(num1 - num2);
                    break;
                case '*':
                    s.push(num1 * num2);
                    break;
                case '/':
                    s.push(num1 / num2);
                    break;
            }
        }
    }
    return s.top(); // 最后栈中只剩下一个元素，即为结果
}

int main() {
    string str;
    cin >> str; // 输入后缀表达式 34+5* 对应的中缀表达式为 (3 + 4)* 5
    cout << calculate(str) << endl;
    return 0;
}