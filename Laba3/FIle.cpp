#include <iostream>
#include <fstream>
#include <istream>
#include <string>

#include "Header_File.h"
#include "MyFunc_header.h"
using namespace std;

bool fileExists(const string& filename) {
    ifstream file(filename); // открываем файл для чтения
    if (file) { // если файл успешно открыт
        return true; // файл существует
    }
    else {
        return false; // файл не существует
    }
}

void WriteToFile(float** matrix, int n, int m) {
    ofstream file("output.txt");
    double sumA = 0; // point a
    for (int i = 0; i < n; i++) {
        sumA += matrix[i][0];
    }
    file << "a) The sum of elements of the first column: " << sumA << endl;
    file << "------------------------------------" << endl;

    double sumB = 0; // point b
    for (int i = 0; i < n; i++) {
        sumB += matrix[i][i]; // главная диагональ
        sumB += matrix[i][n - i - 1]; // побочная диагональ
    }
    file << "b) The sum of the elements of the main and secondary diagonals: " << sumB << endl;
    file << "------------------------------------" << endl;

    double max_first = matrix[0][0]; // point c
    double max_last = matrix[n - 1][0];
    for (int i = 1; i < n; i++) {
        if (matrix[0][i] > max_first) {
            max_first = matrix[0][i];
        }
        if (matrix[n - 1][i] > max_last) {
            max_last = matrix[n - 1][i];
        }
    }
    double result_v = max(max_first, max_last);
    file << "c) The largest of the values of the first and last rows: " << result_v << endl;
    file << "------------------------------------" << endl;

    double min_diag = matrix[0][n - 1];  // point d
    double min_line1 = matrix[1][n - 2];
    double min_line2 = matrix[2][n - 3];
    for (int i = 1; i < n - 1; i++) {
        if (matrix[i][n - i - 1] < min_diag) {
            min_diag = matrix[i][n - i - 1];
        }
        if (matrix[i - 1][n - i] < min_line1) {
            min_line1 = matrix[i - 1][n - i];
        }
        if (matrix[i + 1][n - i - 2] < min_line2) {
            min_line2 = matrix[i + 1][n - i - 2];
        }
    }
    double result_g = min(min_diag, min(min_line1, min_line2));
    file << "d) The smallest of the values of the elements of the secondary diagonal and two adjacent lines: " << result_g << endl;
    file << "------------------------------------" << endl;

    double sumE = 0;   // point e
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j +2 == m) {
                sumE += matrix[i][j];
            }
        }
    }
    file << "e) The sum of those matrix elements whose sum of indices is equal to m: " << sumE << endl;
    file << "------------------------------------" << endl;

    double max_diagf = matrix[0][0];   // point f
    double min_diag2f = matrix[0][n - 1];
    for (int i = 1; i < n; i++) {
        if (matrix[i][i] > max_diagf) {
            max_diagf = matrix[i][i];
        }
        if (matrix[i][n - i - 1] < min_diag2f) {
            min_diag2f = matrix[i][n - i - 1];
        }
    }
    bool result_e = max_diagf > min_diag2f;
    file << "f) is it true that the largest of the values of the elements of the main diagonal" << endl;
    file << " is greater than the smallest of the values of the elements of the secondary diagonal: " << result_e << endl;
    file << "------------------------------------" << endl;
    file << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file << matrix[i][j] << " ";
        }
        file << endl;
    }

}

float** matrixfromfile() {
    int count = 0;
    ifstream file("input.txt");
    string firstline;
    string secondline;
    int firstlineint;
    getline(file, firstline);
    getline(file, secondline);
    if (!contains_letterforint(firstline) && !contains_letterforint(secondline)) {
        firstlineint = stoi(firstline);
    }
    else {
        cout << "File has an invalid values!" << endl;
        return 0;
    }
    float** matrix = new float* [firstlineint];
    string val;
    float val1;
    for (int i = 0; i < firstlineint; i++) {
        matrix[i] = new float[firstlineint];
    }
    for (int i = 0; i < firstlineint; i++) {
        for (int j = 0; j < firstlineint; j++) {
            file >> val;
            if (contains_letter(val)) {
                cout << "Error. File contains invalid values!" << endl;
                j--;
                return 0;
            }
            else {
                val1 = stof(val);
                matrix[i][j] = val1;
            }
        }
    }
    file.close();
    return matrix;
}

bool is_file_empty(std::string filename) {
    std::ifstream file(filename);
    return file.peek() == std::ifstream::traits_type::eof();
}
