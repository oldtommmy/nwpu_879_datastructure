#include <iostream>

/**
 * 演示引用：加上引用后就可以对传入的 a 进行修改
 * @param a 引用类型
 * @param b int类型
 */
void sumWithQuote(int &a){
    a += 10;
}
/**
 * 仅仅是值传递，不会对a修改
 * @param a
 * @param b
 */
void sum(int a) {
    a += 10;
}

int main(){
    int n1 = 10;
    sum(n1);
    std::cout<<"n1:"<<n1<<std::endl; // n1:10
    sumWithQuote(n1);
    std::cout<<"n1:"<<n1<<std::endl; // n1:20
    return 0;
}