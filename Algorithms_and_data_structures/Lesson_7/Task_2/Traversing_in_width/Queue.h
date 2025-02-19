#pragma once

//  ласс дл€ хранени€ queue
class Queue
{
    int* arr;       // массив дл€ хранени€ элементов queue
    int capacity;   // максимальна€ емкость queue
    int front;      // front указывает на передний элемент в queue (если есть)
    int rear;       // задн€€ часть указывает на последний элемент в queue
    int count;      // текущий размер queue

public:
    Queue(int size);     // конструктор
    ~Queue();            // деструктор

    int next();
    void add(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};