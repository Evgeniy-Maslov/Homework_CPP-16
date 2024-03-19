#include "Queue.h"


// Конструктор для инициализации queue
Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Деструктор для освобождения памяти, выделенной для queue
Queue::~Queue() {
    delete[] arr;
}

// Вспомогательная функция для удаления переднего элемента из очереди
int Queue::next()
{
    //// проверка на опустошение queue
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

// Вспомогательная функция для добавления элемента в queue
void Queue::add(int item)
{
    //// проверка на переполнение queue
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

// Вспомогательная функция для возврата первого элемента queue
int Queue::peek()
{
    /*if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }*/
    return arr[front];
}

// Вспомогательная функция для возврата размера queue
int Queue::size() {
    return count;
}

// Вспомогательная функция для проверки, пуста ли queue или нет
bool Queue::isEmpty() {
    return (size() == 0);
}

// Вспомогательная функция для проверки того, заполнена ли queue или нет
bool Queue::isFull() {
    return (size() == capacity);
}