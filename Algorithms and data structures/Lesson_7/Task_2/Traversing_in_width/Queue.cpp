#include "Queue.h"


// ����������� ��� ������������� queue
Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// ���������� ��� ������������ ������, ���������� ��� queue
Queue::~Queue() {
    delete[] arr;
}

// ��������������� ������� ��� �������� ��������� �������� �� �������
int Queue::next()
{
    //// �������� �� ����������� queue
    //if (isEmpty())
    //{
    //    cout << "Underflow\nProgram Terminated\n";
    //    exit(EXIT_FAILURE);
    //}

    int x = arr[front];
    //cout << "Removing " << x << endl;

    front = (front + 1) % capacity;
    count--;

    return x;
}

// ��������������� ������� ��� ���������� �������� � queue
void Queue::add(int item)
{
    //// �������� �� ������������ queue
    //if (isFull())
    //{
    //    cout << "Overflow\nProgram Terminated\n";
    //    exit(EXIT_FAILURE);
    //}

    //cout << "Inserting " << item << endl;

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

// ��������������� ������� ��� �������� ������� �������� queue
int Queue::peek()
{
    /*if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }*/
    return arr[front];
}

// ��������������� ������� ��� �������� ������� queue
int Queue::size() {
    return count;
}

// ��������������� ������� ��� ��������, ����� �� queue ��� ���
bool Queue::isEmpty() {
    return (size() == 0);
}

// ��������������� ������� ��� �������� ����, ��������� �� queue ��� ���
bool Queue::isFull() {
    return (size() == capacity);
}