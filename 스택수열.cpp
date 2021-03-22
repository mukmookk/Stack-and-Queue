#include <vector>
#include <iostream>
using namespace std;
 
class Stack{
private:
    int size;
    int _top;
    int* S;
public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int isFull();
    int isEmpty();
    void display();
    int top();
};
 
Stack::Stack(int size)
{
    this->size = size;
    _top = -1;
    S = new int[size];
}
 
Stack::~Stack()
{
    delete[] S;
}
 
void Stack::push(int x)
{
    if (isFull())
    {
        cout << "FULL" << endl; // stack Overflow
    }
    else
    {
        _top++;
        S[_top] = x;
    }
}
 
int Stack::pop()
{
    int x = 1;
    if (_top == -1)
    {
        cout << "-1" << endl;   // stack Overflow
    }
    else
    {
        x = S[_top];
        cout << x << endl;
        _top--;
    }
    return x;
}
 
int Stack::peek(int index)
{
    int x = -1;
    if (_top-index+1 < 0 || _top-index+1 == size)
    {
        cout << "Index error" << endl;
    }
    else
    {
        x = S[_top-index+1];
    }
    return x;
}
 
int Stack::isFull()
{
    if (_top == size-1)
    {
        return 1;
    }
    return 0;
}
 
int Stack::isEmpty()
{
    if (_top == -1)
    {
        cout << "1" << endl;
        return 1;
    }
    cout << "0" << endl;
    return 0;
}
 
void Stack::display()
{
    for (int i = _top; i>=0; i--){
        cout << S[i] << " | " << flush;
    }
    cout << endl;
}
 
int Stack::top()
{
    if (_top == -1)
    {
        cout << "-1" << endl;
        return -1;
    }
    cout << S[_top] << endl;
    return S[_top];
}

int main(int argc, const char * argv[])
{
    int n, i, j = 0;
    Stack s(100);       // 1 ~ n까지의 수를 오름차순으로 담을 스택
    vector <char> v;    // 부호를 담을 스택
    scanf("%d", &n);    // 배열 크기 입력
    int arr[n];         // 입력된 수열
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);   // 예제 입력 4 3 6 8 7 5 2 1
    }
    
    for (i = 1; i <= n; i++)
    {
        s.push(i);                              // 1 ~ n까지 오름차순으로 입력
        v.push_back('+');                       // push가 이루어지므로 이후 활용할 vector에 '+' push
        
        while (!s.isEmpty() && s.top() == arr[j]) // s에 값이 있고 동시에 top == arr[j]라면 값을 찾았다는 의미이므로
        {
            s.pop();                            // 해당 값 pop
            v.push_back('-');                   // pop이 이뤄졌으므로 '-' push
            j++;                                // 다음 target으로 이동
        }
    }
    
    if (!s.isEmpty())                             // 무언가 값이 남았다면, 어떤 값이 남았다는 얘기므로 에러
        printf("NO\n");
    else
    {
        for (i = 0; i < v.size(); i++)          // 아니라면 담았던 부호를 순차적으로 출력
            printf("%c\n", v[i]);
    }
    return 0;
}
