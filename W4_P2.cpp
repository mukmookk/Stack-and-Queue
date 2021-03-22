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
    int isEmpty();          // concern is Stack empty
    int stackTop();         // return top
};

/* constructor */
Stack::Stack() {    
    top = nullptr; // top이 포인터가 아무것도 가리키지 않는 경우 Stack은 비게 된다
}

/* destructor */
Stack::~Stack()
{
    Node* p = top;
    while (top)
    {
        top = top->next;                        // 이후의 Node를 가리키게 하고
        delete p;                               // 해당 노드 삭제
        p = top;                                // 현재의 top값은 다시 p에 저장
    }                                           // 순회하며 모든 노드 파괴
}
 
void Stack::push(int x) 
{
    Node* t = new Node;                         // New node
    if (t == nullptr)                           // t가 할당에 실패할 경우
    {
        cout << "Stack Overflow" << endl;
    }
    else                                        // 정상적으로 할당이 가능한 경우
    {
        t->data = x;                            // 해당 노드에 데이터 대입
        t->next = top;                          // 현재 top을 새로 생성한 노드의 뒤로 미루고
        top = t;                                // t를 top으로 할당
    }
}
 
int Stack::pop() 
{
    Node* p;                                   
    int x = -1;                                 // 제거되는 노드의 데이터
    if (top == nullptr)                         // stack이 빈 경우
    {
        cout << "Stack Underflow" << endl;
    } 
    else
    {
        p = top;                                // top을 p에 미리 빼두고
        x = p->data;                                                      
        top = top->next;                        // top을 밀고 
        delete p;                               // top을 제거
    }
    return x;
}
 
int Stack::isEmpty() 
{
    return top ? 0 : 1;                         // return true if top equals NULL
}
 
int Stack::stackTop() {
    if (top)
    {
        return top->data;
    }
    return -1;
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
    for (int i=0; postfix[i]!='\0'; i++)            // postfix를 순회
    {
        if (!isOperand(postfix[i]))                 // 숫자인 경우
        {
            stk.push(postfix[i]-'0');               // atoi를 통해 stack에 저장 
        }
        else
        {
            y = stk.pop();                          // 아닌 경우 맨 위의 두 element를 뽑아서
            x = stk.pop();
            result = operation(postfix[i], x, y);   // 계산 수행
            stk.push(result);                       // 계산 결과는 이후 연산에서 재활용
        }
    }
    result = stk.pop();                             // 최종적으로 남은 하나의 숫자 대입
    return result;                                  // 리턴
}
 
int main() {
 
    char postfix[] = "452-+";
    cout << Evaluate(postfix) << endl;
 
    return 0;
}
