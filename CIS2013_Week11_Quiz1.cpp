#include <iostream>
#include <exception>
using namespace std;

int** genMap(int, int*);
void printMap(int**, int, int*);
void changeGrade(int**, int, int, int);
int main()
{
	
	int rows = 0;
	
	cout << "Please enter a number of rows: ";
	cin >> rows;
	int* arrayOfColumns = new int[rows];
	for(int i = 0; i < rows; ++i)
	{
		int columns = 0;
		cout << "Please enter a number of computers: ", cin >> columns;		
		arrayOfColumns[i] = columns;
	}
	int** map = genMap(rows, arrayOfColumns);
	printMap(map, rows, arrayOfColumns);
	
	bool continuation = true;

	while(continuation)
	{
		int x = 0;
		int y = 0;
		int grade = 0;

		cout << "Pick a row/computer to set a grade on.\n";
		cout << "X: ";
		cin >> x;
		
		cout << "Y: ";
		cin >> y;

		cout << "Grade: ";
		cin >> grade;

		changeGrade(map, x, y, grade);

		printMap(map, rows, arrayOfColumns);

	}

	return 0;
}
void changeGrade(int** map, int x, int y, int grade)
{
	map[x-1][y-1] = grade;
}
int** genMap(int rows, int* arrayOfColumns)
{
	//Allocate a two dimensional row x column array
	int** map = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		map[i] = new int[arrayOfColumns[i]];
	}

	//Fill array with Blank Tiles
	for (int i = 0; i < rows; ++i)
	{
		int columns = arrayOfColumns[i];
		for (int j = 0; j < columns; ++j)
		{
			//Blank or Clear Tile
			map[i][j] = 0;
		}
	}
	return map;
}

void printMap(int** map, int rows, int* arrayOfColumns)
{	
	for(int i = 0; i < rows; ++i)
	{
		int columns = arrayOfColumns[i];
		for(int j = 0; j < columns; ++j)
		{
			if(map[i][j] == 0)
			{
				cout << "empty" << " ";
			}
			else
			{
				cout << map[i][j] << " ";
			}
			
		}
		cout << endl;
	}
}