#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** z, const int rowCount, const int colCount, const int Min, const int Max);
void Print(int** z, const int rowCount, const int colCount);
void Sort(int** z, const int rowCount, const int colCount);
void Change(int** z, const int row1, const int row2, const int colCount);


void Create(int** z, const int rowCount, const int colCount, const int Min,
	const int Max)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			z[i][j] = Min + rand() % (Max - Min + 1);
}
void Print(int** z, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << z[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** z, const int rowCount, const int colCount)
{
	for (int i1 = 0; i1 < colCount - 1; i1++)
		for (int i0 = 0; i0 < colCount - i1 - 1; i0++)
			if ((z[0][i0] > z[0][i0+1])
				||
				(z[0][i0] == z[0][i0+1] &&
					z[1][i0] < z[1][i0+1])
				||
				(z[0][i0] == z[0][i0+1] &&
					z[1][i0] == z[1][i0+1] &&
					z[2][i0] < z[2][i0+1]))

				Change(z, i0+1, i0, rowCount);
}
void Change(int** z, const int col1, const int col2, const int rowCount)
{
	int tmp;
	
	for (int j=0;j<rowCount; j++)
	{
		tmp = z[j][col1];
		z[j][col1] = z[j][col2];
		z[j][col2] = tmp;
	}
}
int Calc(int** z, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (!(z[i][j] % 2 != 0 || (z[i][j] % 7 == 0)))
			{
				S += z[i][j];
				k++;
				z[i][j] = 0;
			}

	return S;
}


int main()
{
	srand((unsigned)time(NULL));
	int Min = 18;
	int Max = 74;
	int rowCount = 9;
	int colCount = 6;
	int** z = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		z[i] = new int[rowCount];
	Create(z, rowCount, colCount, Min, Max);
	Print(z, rowCount, colCount);
	Sort(z, rowCount, colCount);
	Print(z, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(z, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(z, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] z[i];
	delete[] z;
	return 0;
}