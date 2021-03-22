#include <iostream>
#include<cstring>


using namespace std;

/*
 * 스택은 1.array 2.list를 통해 구현이 가능하다
 * 물론 두 방법 모두 top에서 접근하기에 시간 복잡도는 O(1)로 동일하다.
 * 1. 그러나 Array의 경우, resize하기가 어렵다는 단점이 있다. 그러나 이는 array를 dynamic하게 구현할 경우 상쇄되며,
 * 이 과정에서 Array의 사이즈가 불필요하게 늘어나는 것이 걱정된다면, 이를 적당한 알고리즘을 채택하여 이를 해결할 수 있다.
 * 2. 리스트의 경우 resize를 해줄 필요는 없다. 그러나 새로운 노드가 추가될 때마다, 계속해서 할당이 요구되고, 이는 다양한 문제를 낳는다.
 * 이에 대표적인 예로 heap fragmentation이 있다.
 * (참고: https://cpp4arduino.com/2018/11/06/what-is-heap-fragmentation.html)
 * 또한 리스트는 Node *next를 포함하며, 이는 곧 공간 복잡도의 증가로 이어진다. 이는 곧 메모리 오버헤드 가능성의 증가를 의미한다.
 * 각각의 방식이 장단이 있다, 그럼에도 array를 구현하는 것을 더 선호하는 이유는 구현이 좀 더 용이하고 공간을 덜 사용하기 때문일 것이다.
 */

/* Singly Linked list를 활용한 스택 구현 */
class Node
{
public:
    int data;
    Node* next;
};
 
class Stack
{
private:
    Node* top;              // 스택은 오로지 맨 위에서만 접근이 가능하다
public:
    Stack();                // constructor
    ~Stack();               // destructor
    void push(int x);       // push to top
    int pop();              // pop from top
    int peek();             // return element from top
    int isEmpty();          // concern is Stack empty
    int isFull();           // concern is Stack full
    int stackTop();
};
 
Stack::Stack() {
    top = nullptr; // top이 포인터가 아무것도 가리키지 않는 경우 Stack은 비게 된다
}
 
Stack::~Stack()
{
    Node* p = top; //
    while (top)
    {
        top = top->next;
        delete p;
        p = top;
    }
}
 
void Stack::push(int x) {
    Node* t = new Node;
    if (t == nullptr)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
 
int Stack::pop() {
    Node* p;
    int x = -1;
    if (top == nullptr){
        cout << "Stack Underflow" << endl;
    } else {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}
 
int Stack::isFull() {
    Node* t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}
 
int Stack::isEmpty() {
    return top ? 0 : 1;
}
 
int Stack::stackTop() {
    if (top){
        return top->data;
    }
    return -1;
}
 
int Stack::peek()
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        Node* p = top;
 
        for (int i=0; p != nullptr; i++)
        {
            p = p->next;
        }
 
        if (p != nullptr)
        {
            return p->data;
        }
        else
        {
            return -1;
        }
    }
}
 
 
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 1;
    return 0;
}
 
int operation(char op, int x, int y)
{
    if (op == '+')
        return x + y;
    else if (op == '-')
        return x - y;
    else if (op == '*')
        return x * y;
    else if (op == '/')
        return x / y;

    return 0;
}
 
int Evaluate(char* postfix){
    Stack stk;
    int x;
    int y;
    int result;
    for (int i=0; postfix[i]!='\0'; i++)
    {
        if (!isOperand(postfix[i]))
        {
            stk.push(postfix[i]-'0');
        }
        else
        {
            y = stk.pop();
            x = stk.pop();
            result = operation(postfix[i], x, y);
            stk.push(result);
        }
    }
    result = stk.pop();
    return result;
}
 
int main() {
 
    char postfix[] = "452-+";
    cout << Evaluate(postfix) << endl;
 
    return 0;
}
