#include <iostream>
#include <bitset>
#include <string>
using namespace std;

// ������� ��� ��������� ������ ����� ����� �� ��������� ���������� ���
long long shiftEvenBitsLeft(long long number, unsigned int shift) {
    // ����� ��� ������ ������ ������ �����
    long long mask = 0xAAAAAAAAAAAAAAAA;
    long long mask2 = 0x5555555555555555;
    long long number2;

    // ��������� ����� � �����
    number2 = number & mask2;
    number &= mask;


    // ��������� �������� ����� ����� �� ��������� ���������� ���
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
    std::cout << "������, �������� ���������� ����������" << std::endl;
    return 0;
  }


    long long number;
    unsigned int shift = stoull(argv[2]);
    try {
    number = stoull(argv[1]);
  }
  catch (out_of_range) {
    std::cout << "������� ������� ������� �����";
    return 0;
  }

    //std::cout << "������� �����: ";
    //std::cin >> number;
    //std::cout << "������� ���������� ��� ��� ������: ";
    //std::cin >> shift;

    // ����� ������� ��� ��������� ������ �����
    long long shiftedNumber = shiftEvenBitsLeft(number, shift);

    std::cout << "���������: " << shiftedNumber << std::endl;
    std::bitset<64> binary(number);
    std::bitset<64> binar(shiftedNumber);
    std::cout <<"��������� ����� " << binary << endl;
    cout <<"�������� ����� " << binar << endl;
    return 0;
}
