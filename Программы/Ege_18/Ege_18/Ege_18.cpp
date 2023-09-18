#include <iostream>

using namespace std;

int main() {
	int original[10][10]{
		{1, 69, 62, 42, 54, 23, 33, 3, 68, 78},
		{65, 1, 24, 68, 57, 48, 38, 47, 45, 51},
		{4, 37, 53, 86, 100, 89, 82, 28, 89, 29},
		{2, 93, 25, 22, 78, 38, 22, 4, 66, 68},
		{3, 54, 53, 36, 99, 84, 70, 14, 76, 97},
		{23, 53, 72, 65, 19, 94, 11, 8, 3, 74},
		{100, 4, 40, 57, 24, 98, 64, 91, 53, 22},
		{100, 68, 99, 56, 49, 66, 45, 17, 31, 12},
		{9, 11, 11, 96, 24, 9, 96, 7, 85, 88},
		{24, 57, 78, 7, 66, 44, 75, 43, 96, 98}
	};
	int minimal[10][10];
	int maximum[10][10];
	for (int i = 1; i < 10; i++) {
		original[0][i] += original[0][i - 1];
		original[i][0] += original[i - 1][0];
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			minimal[i][j] = original[i][j];
			maximum[i][j] = original[i][j];
		}
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			minimal[i][j] += min(minimal[i - 1][j], minimal[i][j - 1]);
			maximum[i][j] += max(maximum[i - 1][j], maximum[i][j - 1]);
		}
	}
	cout << "Final result is: " << maximum[9][9] << minimal[9][9];
}
//for (int i = 0; i < 10; i++) {
//	for (int j = 0; j < 10; j++) {
//		cout << minimal[i][j] << " ";
//	}
//	cout << "\n";
//}
//cout << "\n";
//for (int i = 0; i < 10; i++) {
//	for (int j = 0; j < 10; j++) {
//		cout << maximum[i][j] << " ";
//	}
//	cout << "\n";
//}