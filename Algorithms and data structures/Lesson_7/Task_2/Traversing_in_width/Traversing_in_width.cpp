#include <iostream>
#include <fstream>
#include "Queue.h"
#include <format>


void Breadth_first_search(int** graph, int N, int start)
{
    int vertex;
    bool* visited = new bool[N + 1]();
    Queue queue_bfs(N);
    for (int v = start; v <= N; v++)
    {
        if (!visited[v])
            queue_bfs.add(v);

        while (!queue_bfs.isEmpty())
        {
            vertex = queue_bfs.next();
            std::cout << std::format("{} ", vertex);
            visited[vertex] = true;
            for (int i = 1; i <= N; i++)
            {
                if (graph[vertex][i])
                    if (!visited[i])
                    {
                        queue_bfs.add(i);
                        visited[i] = true;
                    }
            }
        }
    }
    delete[] visited;
}

void delete_arr(int** arr, int n)
{
    for (int i = 0; i <= n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
int main(int argc, char** argv)
{
    int N;
    int start_vertex;
    std::ifstream data("input.txt");
    if (data.is_open())
    {
        data >> N;
    }
    else
    {
        std::cout << "Can't open a text file for initialization!";
        return 0;
    }
    int** graph_ptr = new int* [N + 1];
    for (int i = 0; i <= N; i++)
    {
        graph_ptr[i] = new int[N + 1];
    }
    if (data.eof() != true)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                data >> graph_ptr[i][j];
            }
        }
    }
    data.close();
    do
    {
        std::cout << std::format("In the graph {} vertexes.\nEnter the number of the vertex from which the walk will begin: ", N);
        std::cin >> start_vertex;
    } while (start_vertex < 1 or start_vertex > N);
    std::cout << "Order of vertex traversal: ";
    Breadth_first_search(graph_ptr, N, start_vertex);
    std::cout << std::endl;
    delete_arr(graph_ptr, N);

    return 0;
}