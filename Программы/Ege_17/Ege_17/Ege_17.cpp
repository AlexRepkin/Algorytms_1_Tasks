#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int n1, n2, amount = 0, sredniy = 0, maximum = 0;
    ifstream file("C:\\Users\\yabuz\\source\\Algorythms\\Ege_17\\17.txt");
    vector<int> values;
    int value;
    while (file >> value) {
        values.push_back(value);
        if (value % 2 == 0) {
            sredniy += value;
            amount++;
        }
    }
    file.close();
    sredniy /= amount;
    amount = 0;
    for (int i = 1; i < values.size(); i++) {
        n1 = values[i - 1];
        n2 = values[i];
        if ((n1 % 3 == 0 && n2 < sredniy) || (n2 % 3 == 0 && n1 < sredniy)) {
            amount++;
            maximum = max(maximum, n1 + n2);
        }
    }
    cout << "Answer for Task 17 is " << amount << " " << maximum;
}