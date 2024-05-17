#include <iostream>
#include <stack>
#include <queue>
#include <list>
using namespace std;

void printS(stack<int> stack) {
    if (stack.empty()) {
        cout << "Empty stack" << endl;
        return;
    }
    int i = stack.size();
    while (i--) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}


void printQ(queue<string> que) {
    if (que.empty()) {
        cout << "Empty queue" << endl;
        return;
    }
    int i = que.size();
    while (i--) {
        cout << que.front() << " ";
        que.pop();
    }
    cout << endl;
}

void printL(list<int> lis) {
    if (lis.empty()) {
        cout << "Empty list" << endl;
        return;
    }
    for (auto i: lis) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Stack" << endl << endl;

    // Stacks
    stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    printS(stack);
    
    stack.pop();
    printS(stack);

    cout << stack.size() << endl;

    cout << stack.empty() << endl;




    cout << endl << "Queue" << endl << endl;

    // Queues
    queue<string> que;
    que.push("Hello");
    que.push("everyone");
    que.push("I");
    que.push("am");
    que.push("Kushagra");

    printQ(que);

    que.pop();
    printQ(que);

    que.pop();
    printQ(que);

    cout << que.size() << endl;

    cout << que.empty() << endl;





    cout << endl << "List" << endl << endl;

    // Lists
    list<int> lis;
    lis.push_front(3);
    lis.push_front(2);
    lis.push_front(1);
    lis.push_back(3);
    lis.push_back(4);
    lis.push_back(5);

    printL(lis);
    lis.pop_front();
    printL(lis);
    lis.pop_back();
    printL(lis);
    lis.push_front(1);
    lis.push_back(5);
    printL(lis);

    lis.reverse();
    printL(lis);

    lis.sort();
    printL(lis);

    lis.unique();
    printL(lis);

    cout << lis.empty() << endl;

    cout << lis.size() << endl;

    lis.clear();
    printL(lis);

    list<int> lis2;

    lis2.push_back(6);
    lis2.push_back(7);
    lis2.push_back(8);
    lis2.push_back(9);
    lis2.push_back(10);

    printL(lis2);

    lis.push_back(1);
    lis.push_back(2);
    lis.push_back(3);
    lis.push_back(4);
    lis.push_back(5);

    printL(lis);

    lis.merge(lis2);
    printL(lis);

    return 0;
}