#include<fstream>
#include<iostream>
#include<windows.h>


char** create_two_dim_array(int r, int c)  // ������� ������ ���������
{
	char** arr = new char* [r];
	for (int i = 0; i < r; i++)
	{
		arr[i] = new char[c]();
	}
	return arr;
}
void fill_two_dim_array(char** arr, int r, int c, int** ptr, int& x)  // ��������� ������ ������� (-) � (*)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			arr[i][j] = char('-');
		}
	}
	for (int i = 0; i < x; i++)
	{
		arr[(ptr[i][0])][(ptr[i][1])] = char('*');
	}
}
bool arr__old_arr(char** arr, char** old_arr, int r, int c) // ���������� ��������� ��������� � ���� ������ 
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] != old_arr[i][j]) return false;
		}
	}
	return true;
}
void print_two_dim_array(char** arr, int r, int c)  // ������� �� ������� ������� ���������
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << "\n";
	}
}
int check_cells_for_life(char** arr, int r, int c, int I, int J)  // ������� ����� (*) ������ ������ ������
{
	int k{};
	int n = I - 1;
	if (n < 0) n = 0;
	int n_k = I + 2;
	if (I + 1 >= r) n_k = r;
	int m = J - 1;
	if (m < 0) m = 0;
	int m_k = J + 2;
	if (J + 1 >= c) m_k = c;
	for (int i = n; i < n_k; i++)
	{
		for (int j = m; j < m_k; j++)
		{
			if (I == i && J == j) continue;
			if (arr[i][j] == '*') k += 1;
		}
	}
	return k;
}
void evolution_two_dim_array(char** arr, int r, int c, int ** ptr, int &x) // ��������� ������ �� ������� - "�����"
{
	x = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == '-')
			{
				int k = check_cells_for_life(arr, r, c, i, j);
				if (k == 3)
				{
					ptr[x][0] = i;
					ptr[x][1] = j;
					x += 1;
				}
			}
			else if (arr[i][j] == '*')
			{
				int k = check_cells_for_life(arr, r, c, i, j);
				if (k < 4 && k > 1)
				{
					ptr[x][0] = i;
					ptr[x][1] = j;
					x += 1;
				}
			}
		}
	}
}

void del_dim_array(char** arr, char** old_arr, int r, int** ptr, int l_x)  // ������� ������ �� ���. ��������
{
	for (int i = 0; i < l_x; i++) delete[] ptr[i];
	delete[] ptr;
	for (int i = 0; i < r; i++)
	{
		delete[] arr[i];
		delete[] old_arr[i];
	}
	delete[] arr;
	delete[] old_arr;
}

int main(int argc, char** argv)
{
	int rows{};
	int cols{};
	int n_ptr = 0; // ������� ���-�� (*)
	int Generation = 1;
	std::ifstream data("t.txt");
	if (data.is_open())
	{
		data >> rows >> cols;  // ��������� ������ ������� ���������
	}
	else
	{
		std::cout << "�� ���������� ������� ��� ������������� ��������� ����!";
		return 0;
	}
	int l_m = rows * cols;
	int** cells_ptr = new int*[l_m];  // �������� ������ ��� �������� ��������� (*)
	for (int i = 0; i < l_m; i++)     //
	{								  //	
		cells_ptr[i] = new int[2];    //
	}
	if (data.eof() != true)			  //�������� ��������� �����
	{
		for (int i = 0; i < l_m; i++) // ��������� ���������� (*)
		{
			if (data >> cells_ptr[i][0] >> cells_ptr[i][1])
			{
				n_ptr++;
			}
			else break;
		}
	}
	data.close();
	char** world = create_two_dim_array(rows, cols);
	char** old_world = create_two_dim_array(rows, cols); // �������� ����������� ���������
	while (true)
	{
		fill_two_dim_array(world, rows, cols, cells_ptr, n_ptr);
		std::system("Cls");
		print_two_dim_array(world, rows, cols);
		std::cout << "Generation: " << Generation << ". Alive cells: " << n_ptr << "\n";
		Generation++;
		if (arr__old_arr(world, old_world, rows, cols))
		{
			std::cout << "The world has stagnated. Game over.";
			std::cout << "\n";
			break;
		}
		else
		{
			fill_two_dim_array(old_world, rows, cols, cells_ptr, n_ptr);
			if (n_ptr == 0)
			{
				std::cout << "All cells are dead. Game over.";
				std::cout << "\n";
				break;
			}
			Sleep (500);
			evolution_two_dim_array(world, rows, cols, cells_ptr, n_ptr);
		}
	}
	del_dim_array(world, old_world, rows, cells_ptr, l_m);
	return 0;
}