#include <iostream>
#include <fstream>
#include <iomanip>
#define N 10
#define M 10

int main()
{
    std::setlocale(LC_ALL, "ua");
    int n, m, a, b;
    int MatrixA[N][M], MatrixB[N][M];
    std::ifstream inputFile("file1.txt");
    std::ofstream outputFile2("file2.txt");
    std::ofstream outputFile3("file3.txt");
    srand(time(nullptr));

    if (!inputFile)
    {
        std::cout << "Помилка відкриття файлу file1.txt";
        return 1;
    }

    inputFile >> n >> m;
    inputFile >> a >> b;

    if (inputFile.fail() || n != m || m > M)
    {
        std::cout << "\nНеправильне значення! Кількість рядків та стовпців повинна збігатися та бути цілим числом, не більшим за 10";
        inputFile.close();
        return 1;
    }

    std::cout << "Введені значення:\n";
    std::cout << "n = " << n << ", m = " << m << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << "Матриця A:\n";
    outputFile3 << "Матриця A:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            MatrixA[i][j] = rand() % (b - a + 1) + a;
            std::cout << std::setw(6) << MatrixA[i][j] << " ";
            outputFile3 << std::setw(6) << MatrixA[i][j] << " ";
        }
        std::cout << std::endl;
        outputFile3 << std::endl;
    }

    std::cout << "Матриця B:\n";
    outputFile3 << "Матриця B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            MatrixB[i][j] = MatrixA[i][j];
    for (int j = 0; j < m; j++)
        MatrixB[j][m - 1] = MatrixA[0][j] + MatrixA[n - 1][j];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << std::setw(6) << MatrixB[i][j] << " ";
            outputFile3 << std::setw(6) << MatrixB[i][j] << " ";
        }
        std::cout << std::endl;
        outputFile3 << std::endl;
    }

    outputFile2 << "Матриця B:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            outputFile2 << std::setw(6) << MatrixB[i][j] << " ";
        }
        outputFile2 << std::endl;
    }

    std::cout << "Результати було записано у файли file2.txt та file3.txt" << std::endl;

    inputFile.close();
    outputFile2.close();
    outputFile3.close();

    return 0;
}
