#include <iostream>
#include <fstream>
#include <limits>
const int MAX_SIZE = 100;

struct ABIT {
    std::string NAME;
    std::string GENDER;
    std::string SPEC;
    int EXAM[3];
};

void inputABIT(ABIT& abit) {
    std::cout << "Введіть прізвище та ініціали вступника: ";
    std::getline(std::cin >> std::ws, abit.NAME);
    std::cout << "Введіть гендер: ";
    std::getline(std::cin >> std::ws, abit.GENDER);
    std::cout << "Введіть спеціальність: ";
    std::getline(std::cin >> std::ws, abit.SPEC);
    std::cout << "Введіть результати екзаменів (три результати через пробіл): ";
    for (int i = 0; i < 3; i++) {
        std::cin >> abit.EXAM[i];
    }
}

void printABIT(const ABIT& abit) {
    std::cout << "Прізвище та ініціали вступника: " << abit.NAME << std::endl;
    std::cout << "Гендер: " << abit.GENDER << std::endl;
    std::cout << "Спеціальність: " << abit.SPEC << std::endl;
    std::cout << "Результати екзаменів: ";
    for (int i = 0; i < 3; i++) {
        std::cout << abit.EXAM[i] << " ";
    }
    std::cout << std::endl;
}

void writeABITToFile(const ABIT& abit, std::ofstream& file) {
    file << "Прізвище та ініціали вступника: " << abit.NAME << std::endl;
    file << "Гендер: " << abit.GENDER << std::endl;
    file << "Спеціальність: " << abit.SPEC << std::endl;
    file << "Результати екзаменів: ";
    for (int i = 0; i < 3; i++) {
        file << abit.EXAM[i] << " ";
    }
    file << std::endl;
}

void appendABITToFile(const ABIT& abit, std::ofstream& file) {
    file << "Прізвище та ініціали вступника: " << abit.NAME << std::endl;
    file << "Гендер: " << abit.GENDER << std::endl;
    file << "Спеціальність: " << abit.SPEC << std::endl;
    file << "Результати екзаменів: ";
    for (int i = 0; i < 3; i++) {
        file << abit.EXAM[i] << " ";
    }
    file << std::endl;
}

void printSpecializationsBelowPassing(const ABIT abits[], int size, int passingScore) {
    bool found = false;
    std::cout << "Абітурієнти, що не набрали прохідний бал (" << passingScore << "):\n";
    for (int i = 0; i < size; i++) {
        int totalScore = (abits[i].EXAM[0] + abits[i].EXAM[1] + abits[i].EXAM[2]) / 3;
        if (totalScore < passingScore) {
            printABIT(abits[i]);
            found = true;
        }
    }
    if (!found) {
        std::cout << "Всі абітурієнти набрали прохідний бал.\n";
    }
}

int main() {
    int N;
    std::cout << "Увага! Весь текст повинен бути введений латиницею.\nВведіть кількість абітурієнтів: ";
    std::cin >> N;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    ABIT abiturients[MAX_SIZE];

    std::ofstream file1("file1.txt");

    for (int i = 0; i < N; i++) {
        std::cout << "Введіть деталі абітурієнта " << i + 1 << ":\n";
        inputABIT(abiturients[i]);
        writeABITToFile(abiturients[i], file1);
    }

    file1.close();

    std::ifstream file1Read("file1.txt");

    std::ofstream file2("file2.txt", std::ios::trunc);

    std::string line;
    while (std::getline(file1Read, line)) {
        std::cout << line << std::endl;
        file2 << line << std::endl;
    }

    file1Read.close();

    int passingScore;
    std::cout << "Введіть прохідний бал: ";
    std::cin >> passingScore;

    bool found = false;
    std::cout << "Абітурієнти, що не набрали прохідний бал (" << passingScore << "):\n";
    for (int i = 0; i < N; i++) {
        int totalScore = (abiturients[i].EXAM[0] + abiturients[i].EXAM[1] + abiturients[i].EXAM[2]) / 3;
        if (totalScore < passingScore) {
            printABIT(abiturients[i]); // Вивід на екран
            file2 << "Абітурієнти, що не набрали прохідний бал (" << passingScore << "):\n";
            appendABITToFile(abiturients[i], file2);
            found = true;
        }
    }

    if (!found) {
        std::cout << "Всі абітурієнти набрали прохідний бал.\n";
    }

    file2.close();

    return 0;
}
