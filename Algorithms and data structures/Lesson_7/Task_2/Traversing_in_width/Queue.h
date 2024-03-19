#pragma once

// ����� ��� �������� queue
class Queue
{
    int* arr;       // ������ ��� �������� ��������� queue
    int capacity;   // ������������ ������� queue
    int front;      // front ��������� �� �������� ������� � queue (���� ����)
    int rear;       // ������ ����� ��������� �� ��������� ������� � queue
    int count;      // ������� ������ queue

public:
    Queue(int size);     // �����������
    ~Queue();            // ����������

    int next();
    void add(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};