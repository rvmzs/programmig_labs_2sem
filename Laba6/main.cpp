#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


int test_nat(string& check) {
    bool isFigure{ true };

    if (check[0] == '0') {
        cout << "Порядковый номер не может начинаться с нуля! Попробуйте ещё раз." << endl;
        return 0;
    }
    else {
        for (int i = 0; i < check.length(); i++) {
            if (!isdigit(check[i])) {
                isFigure = false;
                cout << "Вы ввели неправильно! Попробуйте ещё раз." << endl;
                return 0;
            }
        }

        try {
            return stoi(check);
        }
        catch (out_of_range e) {
            cout << "Неправильный формат записи числа. Слишком большое число." << endl;
            return 0;
        }
        catch (const std::exception) {
            cout << "Неправильный формат записи числа. Введено пустое значение" << endl;
            return 0;
        }
    }
}


void menu_display() {
    cout << endl;
    cout << "Выберите действие:" << endl;
    cout << "1 - Добавить элемент (после указанного по номеру)" << endl;
    cout << "2 - Вывести все элементы списка." << endl;
    cout << "3 - Присвоение всем элементам списка предустановленного значения." << endl;
    cout << "4 - Прочитать элементы списка с файла." << endl;
    cout << "5 - Сохранить элементы списка в файл." << endl;
    //cout << "6 - Удалить элемент списка по индексу." << endl;
    cout << "6 - Вывести список действий." << endl;
    cout << "7 - Выход" << endl;
}


string check_fullname(string& fullname) {
    istringstream check{ fullname };
    int amount = 0;
    string right_fullname;

    while (check >> fullname) {
        if (amount == 0) right_fullname += fullname;
        else right_fullname += " " + fullname;
        for (char c : fullname) {
            if (!(c >= 'А' && c <= 'я'))
                return " ";
        }
        amount++;
    }



    if (amount == 3)
        return right_fullname;
    else
        return " ";
}


string no_space(string& line) {
    istringstream check(line);
    string right_line;
    check >> line;
    right_line += line;
    while (check >> line) {
        right_line += " " + line;
    }

    return right_line;
}

struct Node {
    string fullname;
    string post;
    string placeOR;
    Node* next;

    Node(string fullname, string post, string placeOR) : fullname(fullname), post(post), placeOR(placeOR), next(NULL) {
    }
};

struct OneLinkedList {
    Node* head;
    Node* tail;
    int max_length_fullname;
    int max_length_post;
    int max_length_placeOR;

    OneLinkedList() {
        this->head = this->tail = NULL;
        this->max_length_fullname = 4;
        this->max_length_post = 9;
        this->max_length_placeOR = 16;
    }

    ~OneLinkedList() {
        while (head != NULL) pop_front();
    }

    /*void pop_back(){
        if (head == NULL){
            cout << "Список пуст." << endl;
            return;
        }
        if (head == tail){
            Node *node = head;
            head = tail = NULL;
            delete node;
            return;
        }

        Node *node = tail;
        head = head->next;
        delete node;
    }*/

    void pop_front() {
        if (head == NULL) {

        }
        if (head == tail) {
            Node* node = head;
            head = tail = NULL;
            delete node;
            return;
        }

        Node* node = head;
        head = head->next;
        delete node;

    }

    void push_front(string fullname, string post, string placeOR) {
        Node* node = new Node(fullname, post, placeOR);
        if (head == NULL) {
            head = tail = node;
            return;
        }
        node->next = head;
        head = node;
        return;
    }

    void push_back(string fullname, string post, string placeOR) {
        Node* node = new Node(fullname, post, placeOR);
        if (tail == NULL) {
            head = tail = node;
            return;
        }
        tail->next = node;
        tail = node;
        return;
    }

    Node* get(int k) {
        int n = 1;
        Node* node = head;
        while (node && n != k && node->next) {
            node = node->next;
            n++;
        }

        return (n == k) ? node : NULL;
    }
    
    bool push(string fullname, string post, string placeOR, int k) {
        Node* node = new Node(fullname, post, placeOR);
        Node* left = get(k);

        if (left == NULL) {
            cout << "Данный порядковый номер вне диапазона. Попробуйте ещё раз." << endl;
            return false;
        }

        node->next = left->next;
        left->next = node;

        if (node->next == NULL) {
            tail = node;
        }

        return true;
    }

    /*bool push(string fullname, string post, string placeOR, int k) {
        Node* node = new Node(fullname, post, placeOR);
        Node* left = get(k - 1);
        if (k == 1) {
            push_front(fullname, post, placeOR);
            return true;
        }
        if (left == NULL) {
            cout << "Данный порядковый номер вне диапазона. Попробуйте ещё раз." << endl;
            return false;
        }

        node->next = left->next;
        left->next = node;

        if (node->next) {
            tail = node;
            return true;
        }
        else return true;
    }
    */
    void print_all() {
        if (head == NULL) {
            cout << "Список пуст." << endl;
            return;
        }
        Node* node = head;
        max_length_fullname = 4;
        max_length_post = 9;
        max_length_placeOR = 16;

        for (; node != NULL; node = node->next)
            find_max(node->fullname, node->post, node->placeOR);

        cout << setw(max_length_fullname) << " ФИО" << setw(max_length_post + 3) << "  Возраст" << setw(max_length_placeOR + 3) << "  Семейное положение" << endl;
        for (node = head; node != NULL; node = node->next) {
            cout << setw(max_length_fullname) << node->fullname << setw(max_length_post + 3) << node->post << setw(max_length_placeOR + 3) << node->placeOR << endl;
        }

    }

    void remove_all() {
        while (head != NULL) pop_front();
        return;
    }

    void find_max(string fullname, string post, string placeOR) {
        if (max_length_fullname < fullname.length()) max_length_fullname = fullname.length();
        if (max_length_post < post.length()) max_length_post = post.length();
        if (max_length_placeOR < placeOR.length()) max_length_placeOR = placeOR.length();
        return;
    }


    void change_value() {
        if (head == NULL) {
            cout << "Список пуст." << endl;
            return;
        }

        Node* node = head;
        for (; node != NULL; node = node->next) {
            node->fullname = "Студентов Студент Студентович";
            node->post = "18";
            node->placeOR = "не женат";
        }
        cout << "Команда выполнена успешно." << endl;
        return;
    }

    void write_to_file() {
        ofstream file;
        file.open("input.txt");
        if (file.is_open()) {
            if (head == NULL) {
                cout << "Список пуст." << endl;
            }
            else {
                Node* node = head;
                max_length_fullname = 4;
                max_length_post = 9;
                max_length_placeOR = 16;

                for (; node != NULL; node = node->next)
                    find_max(node->fullname, node->post, node->placeOR);

                file << setw(max_length_fullname) << " ФИО" << setw(max_length_post + 3) << " Возраст" << setw(max_length_placeOR + 3) << " Семейное положение" << endl;
                for (node = head; node != NULL; node = node->next) {
                    file << setw(max_length_fullname) << node->fullname << setw(max_length_post + 3) << node->post << setw(max_length_placeOR + 3) << node->placeOR << endl;
                }
            }

        }
        else {
            cout << "Не удалось открыть файл для записи." << endl;
        }
        file.close();
        return;
    }


    bool read_from_file() {
        /*cout << "---------------------------------------------------------------------------------------" << endl;
        cout << "В текстовом файле данные должны быть записаны через запятую. Например:" << endl;
        cout << "Иванов Иван Иванович, 45, Женат" << endl;*/
        //cout << "Добавление пробелов не выдаст ошибку. Однако переход на новую строку напротив может вызвать ошибку." << endl;
        //cout << "Будьте внимательны с запятыми. В каждой строке должны быть ровно 2 запятых." << endl;
        cout << "---------------------------------------------------------------------------------------" << endl;
        ifstream file;
        file.open("input.txt");

        if (file.is_open()) {
            /*if (head != NULL){
                write_to_file();
                remove_all();
            }*/

            string line;
            int n = 1, flag = 1;


            while (getline(file, line)) {
                string arr[3];
                int j = 0;

                for (int i = 0; line[i] != '\0'; i++) {
                    if (line[i] == ',') {
                        j++;
                        if (j == 3) break;
                        else continue;
                    }
                    arr[j] += line[i];
                }

                if (j < 2) {
                    cout << "Проиозшла ошибка. Недостаток данных в " << n << " строке." << endl;
                    file.close();
                    flag = 0;
                    break;
                    //return false;
                }
                else if (j > 2) {
                    cout << "Проиозшла ошибка. Избыток данных в " << n << " строке." << endl;
                    file.close();
                    flag = 0;
                    break;
                }

                arr[0] = check_fullname(arr[0]);
                if (arr[0] == " ") {
                    cout << "Проиозшла ошибка. Недостаток или некорректность данных в ФИО в " << n << " строке." << endl;
                    file.close();
                    flag = 0;
                    break;
                }

                arr[1] = no_space(arr[1]);
                arr[2] = no_space(arr[2]);
                push_back(arr[0], arr[1], arr[2]);
                n++;
            }

            if (!flag) {
                for (; n != 1; n--) {
                    pop(acount());
                }
                return false;
            }

        }
        else {
            cout << "Не удалось открыть файл для чтения. \nУбедитесь в том, что текстовый файл имеет название \"input.txt\" и находиться в нужной директории " << endl;
            file.close();
            return false;
        }
        file.close();
        return true;
    }


    int pop(int k) {
        if (head == NULL) {
            cout << "---------------------------------------------------------------------------------------" << endl;
            cout << "Список пуст." << endl;
            return 2;
        }
        Node* node, * left = get(k - 1);
        if (k == 1) {
            pop_front();
            return 1;
        }
        if (!left || !left->next) {
            cout << "---------------------------------------------------------------------------------------" << endl;
            cout << "Данный порядковый номер вне диапазона. Попробуйте ещё раз." << endl;
            cout << "---------------------------------------------------------------------------------------" << endl;
            return 0;
        }

        node = left->next;
        left->next = node->next;
        delete node;

        if (left->next == NULL)
            tail = left;

        return 1;
    }

    int acount() {
        Node* node = head;
        int n = 0;
        for (; node != NULL; node = node->next)
            n++;
        return n;
    }


};



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string arr[2];


    OneLinkedList lst;
    int i;
    cout << "Данная программа реализует работу односвязного списка." << endl;
    menu_display();


    while (true) {
        cout << "---------------------------------------------------------------------------------------" << endl;
        cout << "Для просмотра команд введите число 6." << endl;
        cout << ">> ";
        string check;
        getline(cin, check);
        if (check == "1") {
            string fullname, post, placeOR, check;
            int i;

            cout << "---------------------------------------------------------------------------------------" << endl;
            cout << "Введите ФИО через пробел ." << endl;
            while (true) {
                cout << ">> ";
                getline(cin, fullname);
                fullname = check_fullname(fullname);
                if (fullname == " ")
                    cout << "Вы ввели неправильно! Попробуйте ещё раз." << endl;
                else break;
            }

            cout << "Введите ваш возраст." << endl;
            cout << ">> ";
            getline(cin, post);
            post = no_space(post);



            cout << "Введите ваше семейное положение." << endl;
            cout << ">> ";
            getline(cin, placeOR);
            placeOR = no_space(placeOR);



            cout << "Введите порядковый номер после которого следует добавить новый элемент." << endl;
            while (true) {
                cout << ">> ";
                getline(cin, check);
                i = test_nat(check);
                if (i && lst.push(fullname, post, placeOR, i)) {
                    cout << "Добавление прошло успешно." << endl;
                    break;
                }
            }
        }

        else if (check == "2") {
            cout << "---------------------------------------------------------------------------------------" << endl;
            lst.print_all();
        }

        else if (check == "3") {
            cout << "---------------------------------------------------------------------------------------" << endl;
            lst.change_value();
        }

        else if (check == "4") {
            if (lst.read_from_file())
                cout << "Чтение с текстового файла прошло успешно." << endl;
        }

        else if (check == "5") {
            cout << "---------------------------------------------------------------------------------------" << endl;
            lst.write_to_file();
            cout << "Запись в текстовый файл \"input.txt\" прошла успешно." << endl;
        }

        /*else if (check == "6") {
            cout << "Введите порядковый номер для удаления элемента из списка." << endl;
            while (true) {

                cout << ">> ";
                getline(cin, check);
                i = test_nat(check);

                if (i) {
                    int flag = lst.pop(i);
                    if (flag == 0) {
                        continue;
                    }
                    else if (flag == 1) {
                        cout << "---------------------------------------------------------------------------------------" << endl;
                        cout << "Удаление прошло успешно." << endl;
                        break;
                    }
                    else if (flag == 2) {
                        break;
                    }

                }
            }
        }
        */
        else if (check == "6") menu_display();
        else if (check == "7") break;
        else cout << "Вы ввели неправильно! Попробуйте ещё раз." << endl;
    }



    cout << "Завершение программы." << endl;

    return 0;
}
