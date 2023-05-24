#include <iostream>
#include <bitset>
#include <string>
using namespace std;

// Функция для побитного сдвига числа влево на указанное количество бит
long long shiftEvenBitsLeft(long long number, unsigned int shift) {
    // Маска для выбора только четных битов
    long long mask = 0xAAAAAAAAAAAAAAAA;
    long long mask2 = 0x5555555555555555;
    long long number2;

    // Применяем маску к числу
    number2 = number & mask2;
    number &= mask;


    // Выполняем побитный сдвиг влево на указанное количество бит
    if (shift >= 64) {
        for (int i = 1; i <= shift * 2; i++) {
            number <<= 1;
            number &= 0;
        }
    }
    else {
        number <<= shift * 2;
    }
    number += number2;

    std::cout <<"number2: " <<std::bitset<64>(number2)<<std::endl;
    std::cout <<"mask2: " <<std::bitset<64>(mask2)<<std::endl;
    std::cout <<"mask: " <<std::bitset<64>(mask)<<std::endl;
    return number;
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    if (argc != 3) {
    std::cout << "ошибка, неверное количество параметров" << std::endl;
    return 0;
  }


    long long number;
    unsigned int shift = stoull(argv[2]);
    try {
    number = stoull(argv[1]);
  }
  catch (out_of_range) {
    std::cout << "Введено слишком большое число";
    return 0;
  }

    //std::cout << "Введите число: ";
    //std::cin >> number;
    //std::cout << "Введите количество бит для сдвига: ";
    //std::cin >> shift;

    // Вызов функции для побитного сдвига числа
    long long shiftedNumber = shiftEvenBitsLeft(number, shift);

    std::cout << "Результат: " << shiftedNumber << std::endl;
    std::bitset<64> binary(number);
    std::bitset<64> binar(shiftedNumber);
    std::cout <<"Начальное число " << binary << endl;
    cout <<"Конечное число " << binar << endl;
    return 0;
}
