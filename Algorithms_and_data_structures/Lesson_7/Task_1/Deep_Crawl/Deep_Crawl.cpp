#include <iostream>
#include <fstream>
#include <format>

void depth_first_search(int** graph,int N, int vertex, bool* visited)
{
    std::cout << std::format("{} ", vertex);
    visited[vertex] = true;
    for (int i = 1; i <= N; i++)
    {
        if (graph[vertex][i])
            if (!visited[i])
            {
                depth_first_search(graph, N, i, visited);
            }
    }
}

void depth_first_search(int** graph, int N)
{
    bool* visited = new bool[N + 1]();
    for (int v = 1; v <= N; v++)
    {
        if (!visited[v])
            depth_first_search(graph, N, v, visited);
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

    std::cout << "The order of traversing the vertices: ";
    depth_first_search(graph_ptr, N);
    std::cout << std::endl;
    delete_arr(graph_ptr, N);

    return 0;
}
