#include<iostream>
#include<fstream>
using namespace std;
int option_input(int option, int limit);
bool open_for_reading(ifstream& fin, char filename[]);
int** matrix_on_console(int** matrix, int& rows, int& columns);
bool name_validity_checker(char* filename, int count);
int axis_input(int n);
void sum_of_all();
void transpose();
void column_wise_sorting();
void subtraction_of_matrices();
void addition_of_matrices();
void product_of_all();
void row_wise_average();
void whole_matrix_avg();
void column_wise_average();
int** input_type(int** matrix, int& rows, int& columns);
int** matrix_input(int** matrix, ifstream& fin, int& rows, int& columns);
char* file_name_input(char* filename);
char* name_entry(char* filename, bool& flag);
char* dynamic_memory_inserter(char* filename, char arr[], int count);
int size_counter(char arr[]);
void row_wise_sorting();
int** matrix_through_files(int** matrix, int& rows, int& columns);
int** memory_allocater(int** matrix, int rows, int columns);
int** input(int** matrix, int rows, int columns);
int main()
{
	int option_selection = 0;
	do
	{
		cout << "******	MENU	******" << endl;
		cout << "1.  SUM OF ALL MATRIX" << endl;
		cout << "2.  PRODUCT OF ALL MATRIX" << endl;
		cout << "3.  ROW WISE AVERAGE" << endl;
		cout << "4.  COLUMN WISE AVERAGE" << endl;
		cout << "5.  AVERAGE OF WHOLE MATRIX" << endl;
		cout << "6.  ROW WISE SORTING" << endl;
		cout << "7.  COLUMN WISE SORTING" << endl;
		cout << "8.  ADDITION OF TWO MATRICES" << endl;
		cout << "9.  SUBTRACTION OF TWO MATRICES" << endl;
		cout << "10. TRANSPOSE OF A MATRIX" << endl;
		cout << "11. EXIT" << endl;
		option_selection = option_input(option_selection, 11);

		if (option_selection == 1)
		{
			sum_of_all();
		}
		else if (option_selection == 2)
		{
			product_of_all();
		}
		else if (option_selection == 3)
		{
			row_wise_average();
		}
		else if (option_selection == 4)
		{
			column_wise_average();
		}
		else if (option_selection == 5)
		{
			whole_matrix_avg();
		}
		else if (option_selection == 6)
		{
			row_wise_sorting();
		}
		else if (option_selection == 7)
		{
			column_wise_sorting();
		}
		else if (option_selection == 8)
		{
			addition_of_matrices();
		}
		else if (option_selection == 9)
		{
			subtraction_of_matrices();
		}
		else if (option_selection == 10)
		{
			transpose();
		}
	} while (option_selection != 11);
}
int mode_checker()
{
	int mode = 0;
	do
	{
		cout << "****OUTPUT MODE****" << endl;
		cout << "1. to place data in a file" << endl;
		cout << "2. to show data on console" << endl;
		cout << "enter your option: " << endl;
		cin >> mode;
		if (mode < 1 || mode>2)
		{
			cout << "please enter valid option" << endl;
		}
	} while (mode < 1 || mode>2);
	cin.ignore();
	return mode;
}
void addition_of_matrices()
{
	int** matrix_1 = {};
	int** matrix_2 = {};
	int rows_1 = 0;
	int columns_1 = 0;
	int rows_2 = 0;
	int columns_2 = 0;
	do
	{
		rows_1 = 0;
		columns_1 = 0;
		rows_2 = 0;
		columns_2 = 0;
		cout << "ENTER FIRST ARRAY FILE" << endl;
		matrix_1 = input_type(matrix_1, rows_1, columns_1);
		cout << "enter second array file" << endl;
		matrix_2 = input_type(matrix_2, rows_2, columns_2);
		if (rows_1 != rows_2 || columns_1 != columns_2)
		{
			cout << "both matrixes have different dimensions" << endl;
			cout << "PLEASE TRY AGAIN" << endl;
		}
	} while (rows_1 != rows_2 || columns_1 != columns_2);

	int** new_matrix = {};
	new_matrix = memory_allocater(new_matrix, rows_1, columns_1);
	for (int i = 0; i < rows_1; i++)
	{
		for (int j = 0; j < columns_1; j++)
		{
			new_matrix[i][j] = matrix_1[i][j] + matrix_2[i][j];
		}
	}

	ofstream fout;
	char* filename = {};
	int mode = 0;
	mode = mode_checker();

	if (mode == 1)
	{
		filename = file_name_input(filename);
		fout.open(filename);
		for (int i = 0; i < rows_1; i++)
		{
			for (int j = 0; j < columns_1; j++)
			{
				fout << new_matrix[i][j] << " ";
			}
			fout << endl;
		}
	}
	else
	{
		cout << "**************************" << endl;
		for (int i = 0; i < rows_1; i++)
		{
			for (int j = 0; j < columns_1; j++)
			{
				cout << new_matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << "**************************" << endl;
	}
}
void subtraction_of_matrices()
{
	int** matrix_1 = {};
	int** matrix_2 = {};
	int rows_1 = 0;
	int columns_1 = 0;
	int rows_2 = 0;
	int columns_2 = 0;
	do
	{
		rows_1 = 0;
		columns_1 = 0;
		rows_2 = 0;
		columns_2 = 0;
		cout << "ENTER FIRST ARRAY FILE" << endl;
		matrix_1 = input_type(matrix_1, rows_1, columns_1);
		cout << "enter second array file" << endl;
		matrix_2 = input_type(matrix_2, rows_2, columns_2);
		if (rows_1 != rows_2 || columns_1 != columns_2)
		{
			cout << "both matrixes have different dimensions" << endl;
			cout << "PLEASE TRY AGAIN" << endl;
		}
	} while (rows_1 != rows_2 || columns_1 != columns_2);

	int** new_matrix = {};
	new_matrix = memory_allocater(new_matrix, rows_1, columns_1);
	for (int i = 0; i < rows_1; i++)
	{
		for (int j = 0; j < columns_1; j++)
		{
			new_matrix[i][j] = matrix_1[i][j] - matrix_2[i][j];
		}
	}

	ofstream fout;
	char* filename = {};
	int mode = 0;
	mode = mode_checker();

	if (mode == 1)
	{
		filename = file_name_input(filename);
		fout.open(filename);
		for (int i = 0; i < rows_1; i++)
		{
			for (int j = 0; j < columns_1; j++)
			{
				fout << new_matrix[i][j] << " ";
			}
			fout << endl;
		}
	}
	else
	{
		cout << "**************************" << endl;
		for (int i = 0; i < rows_1; i++)
		{
			for (int j = 0; j < columns_1; j++)
			{
				cout << new_matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << "**************************" << endl;
	}
}
void transpose()
{
	int** matrix = {};
	int rows = 0;
	int columns = 0;
	matrix = input_type(matrix, rows, columns);
	int** duplicate_matrix = {};
	duplicate_matrix = memory_allocater(duplicate_matrix, columns, rows);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			duplicate_matrix[j][i] = matrix[i][j];
		}
	}

	ofstream fout;
	char* filename = {};
	int mode = 0;
	mode = mode_checker();

	if (mode == 1)
	{
		filename = file_name_input(filename);
		fout.open(filename);
		for (int i = 0; i < columns; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				fout << duplicate_matrix[i][j] << " ";
			}
			fout << endl;
		}
	}
	else
	{
		cout << "**************************" << endl;
		for (int i = 0; i < columns; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				cout << duplicate_matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << "**************************" << endl;
	}

}
void column_wise_sorting()
{
	int** matrix = {};
	int rows = 0;
	int columns = 0;
	matrix = input_type(matrix, rows, columns);
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			for (int k = 0; k < rows - 1; k++)
			{
				if (matrix[k][i] > matrix[k + 1][i])
				{
					int temp = matrix[k + 1][i];
					matrix[k + 1][i] = matrix[k][i];
					matrix[k][i] = temp;
				}
			}
		}
	}
	ofstream fout;
	char* filename = {};
	int mode = 0;
	mode = mode_checker();

	if (mode == 1)
	{
		filename = file_name_input(filename);
		fout.open(filename);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				fout << matrix[i][j] << " ";
			}
			fout << endl;
		}
	}
	else
	{
		cout << "**************************" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << "**************************" << endl;
	}

}
void row_wise_sorting()
{
	int** matrix = {};
	int rows = 0;
	int columns = 0;
	matrix = input_type(matrix, rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			for (int k = 0; k < columns - 1; k++)
			{
				if (matrix[i][k] > matrix[i][k + 1])
				{
					int temp = matrix[i][k];
					matrix[i][k] = matrix[i][k + 1];
					matrix[i][k + 1] = temp;
				}
			}
		}
	}

	ofstream fout;
	char* filename = {};
	int mode = 0;
	mode = mode_checker();

	if (mode == 1)
	{
		filename = file_name_input(filename);
		fout.open(filename);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				fout << matrix[i][j] << " ";
			}
			fout << endl;
		}
	}
	else
	{
		cout << "**************************" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << "**************************" << endl;
	}

}
void whole_matrix_avg()
{
	double avg = 0;
	int** matrix = {};
	int rows = 0;
	int columns = 0;
	matrix = input_type(matrix, rows, columns);
	int sum = 0;
	int total_index = rows * columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			sum = sum + matrix[i][j];
		}
		avg = (sum + 0.0) / total_index;
	}
	ofstream fout;
	char* filename = {};
	int mode = 0;
	mode = mode_checker();

	if (mode == 1)
	{
		filename = file_name_input(filename);
		fout.open(filename);
		fout << avg;
	}
	else
	{
		cout << "**************************" << endl;
		cout << avg << endl;
		cout << "**************************" << endl;
	}

}
void column_wise_average()
{
	double* arr = {};
	int** matrix = {};
	int rows = 0;
	int columns = 0;
	matrix = input_type(matrix, rows, columns);
	arr = new double[columns];
	double avg = 0;
	int sum = 0;
	for (int i = 0; i < columns; i++)
	{
		sum = 0;
		for (int j = 0; j < rows; j++)
		{
			sum = sum + matrix[j][i];
		}
		avg = (sum + 0.0) / rows;
		arr[i] = avg;
	}
	ofstream fout;
	char* filename = {};
	int mode = 0;
	mode = mode_checker();

	if (mode == 1)
	{
		filename = file_name_input(filename);
		fout.open(filename);
		for (int i = 0; i < columns; i++)
		{
			fout << arr[i] << " ";
		}
	}
	else
	{
		cout << "**************************" << endl;
		for (int i = 0; i < columns; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		cout << "**************************" << endl;
	}
}
void row_wise_average()
{
	double* arr = {};
	int** matrix = {};
	int rows = 0;
	int columns = 0;
	matrix = input_type(matrix, rows, columns);
	arr = new double[rows];
	double avg = 0;
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		sum = 0;
		for (int j = 0; j < columns; j++)
		{
			sum = sum + matrix[i][j];
		}
		avg = (sum + 0.0) / columns;
		arr[i] = avg;
	}
	ofstream fout;
	char* filename = {};
	int mode = 0;
	mode = mode_checker();

	if (mode == 1)
	{
		filename = file_name_input(filename);
		fout.open(filename);
		for (int i = 0; i < rows; i++)
		{
			fout << arr[i] << endl;
		}
	}
	else
	{
		cout << "**************************" << endl;
		for (int i = 0; i < rows; i++)
		{
			cout << arr[i] << endl;
		}
		cout << endl;
		cout << "**************************" << endl;
	}
}
void product_of_all()
{
	int** matrix = {};
	int rows = 0;
	int columns = 0;
	matrix = input_type(matrix, rows, columns);
	int product = 1;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			product = product * matrix[i][j];
		}
	}
	ofstream fout;
	char* filename = {};
	int mode = 0;
	mode = mode_checker();

	if (mode == 1)
	{
		filename = file_name_input(filename);
		fout.open(filename);
		fout << product;
	}
	else
	{
		cout << "**************************" << endl;
		cout << product << endl;
		cout << "**************************" << endl;
	}
}
void sum_of_all()
{
	int** matrix = {};
	int rows = 0;
	int columns = 0;
	matrix = input_type(matrix, rows, columns);
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			sum = sum + matrix[i][j];
		}
	}
	ofstream fout;
	char* filename = {};
	int mode = 0;
	mode = mode_checker();

	if (mode == 1)
	{
		filename = file_name_input(filename);
		fout.open(filename);
		fout << sum;
	}
	else
	{
		cout << "**************************" << endl;
		cout << sum << endl;
		cout << "**************************" << endl;
	}

}
int** input_type(int** matrix, int& rows, int& columns)
{
	int option_selection_1 = 0;
	cout << "****INPUT MODE****" << endl;
	cout << "press 1 if you want to enter matrix on console" << endl;
	cout << "press 2 if you want to enter matrix through files" << endl;
	cout << "press 3 to exit" << endl;
	option_selection_1 = option_input(option_selection_1, 2);
	if (option_selection_1 == 1)
	{
		matrix = matrix_on_console(matrix, rows, columns);
	}
	else if (option_selection_1 == 2)
	{
		matrix = matrix_through_files(matrix, rows, columns);
	}

	return matrix;
}
int** matrix_through_files(int** matrix, int& rows, int& columns)
{
	ifstream fin;
	cin.ignore();
	char* filename = {};
	filename = file_name_input(filename);
	if (open_for_reading(fin, filename))
	{
		matrix = matrix_input(matrix, fin, rows, columns);
	}
	return matrix;
}
int** matrix_input(int** matrix, ifstream& fin, int& rows, int& columns)
{

	fin >> rows;
	fin >> columns;
	matrix = memory_allocater(matrix, rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			fin >> matrix[i][j];
		}
	}


	return matrix;
}
char* file_name_input(char* filename)
{

	bool flag = false;
	do
	{
		filename = name_entry(filename, flag);
	} while (flag == false);
	return filename;
}
char* name_entry(char* filename, bool& flag)
{
	const int size = 50;
	char arr[size] = {};

	cout << "enter name of file with .txt extention" << endl;
	cin.getline(arr, size);
	int count = size_counter(arr);
	filename = dynamic_memory_inserter(filename, arr, count);
	filename[count] = '\0';
	flag = name_validity_checker(filename, count);
	if (flag == false)
	{
		cout << "please enter valid name" << endl;
	}
	return filename;
}
bool name_validity_checker(char* filename, int count)
{
	bool flag = false;
	if (filename[count - 1] == 't' && filename[count - 2] == 'x' && filename[count - 3] == 't' && filename[count - 4] == '.')
	{
		flag = true;
	}
	else
	{
		flag = false;
	}
	return flag;
}
char* dynamic_memory_inserter(char* filename, char arr[], int count)
{
	filename = new char[count];
	for (int i = 0; i < count; i++)
	{
		filename[i] = arr[i];
	}
	return filename;
}
int size_counter(char arr[])
{
	int count = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}
int** matrix_on_console(int** matrix, int& rows, int& columns)
{
	cout << "enter number of rows" << endl;
	rows = axis_input(rows);
	cout << "enter number of columns" << endl;
	columns = axis_input(columns);

	matrix = memory_allocater(matrix, rows, columns);
	matrix = input(matrix, rows, columns);
	return matrix;
}
int** input(int** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		cout << "enter elements of row " << i + 1 << endl;
		for (int j = 0; j < columns; j++)
		{
			cin >> matrix[i][j];
		}
	}
	return matrix;
}
int** memory_allocater(int** matrix, int rows, int columns)
{
	matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[columns];
	}
	return matrix;
}
int axis_input(int n)
{
	do
	{
		cin >> n;
		if (n < 1)
		{
			cout << "please enter valid number" << endl;
		}
	} while (n < 1);
	return n;
}
int option_input(int option, int limit)
{
	do
	{
		cout << endl;
		cout << "enter your option: " << endl;
		cin >> option;
		if (option < 1 || option>limit)
		{
			cout << "please enter valid option" << endl;
		}
	} while (option<1 || option>limit);
	return option;
}
bool open_for_reading(ifstream& fin, char filename[])
{
	bool p = false;
	fin.open(filename);
	if (fin.is_open())
	{
		p = true;
	}
	else
	{
		p = false;
		cout << "cannot open file" << endl;
	}
	return p;
}