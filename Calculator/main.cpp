#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        std::cout << s.top() << '\n';
        s.pop();
    }

    return 0;
}
