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
        cout << "���������� ����� �� ����� ���������� � ����! ���������� ��� ���." << endl;
        return 0;
    }
    else {
        for (int i = 0; i < check.length(); i++) {
            if (!isdigit(check[i])) {
                isFigure = false;
                cout << "�� ����� �����������! ���������� ��� ���." << endl;
                return 0;
            }
        }

        try {
            return stoi(check);
        }
        catch (out_of_range e) {
            cout << "������������ ������ ������ �����. ������� ������� �����." << endl;
            return 0;
        }
        catch (const std::exception) {
            cout << "������������ ������ ������ �����. ������� ������ ��������" << endl;
            return 0;
        }
    }
}


void menu_display() {
    cout << endl;
    cout << "�������� ��������:" << endl;
    cout << "1 - �������� ������� (����� ���������� �� ������)" << endl;
    cout << "2 - ������� ��� �������� ������." << endl;
    cout << "3 - ���������� ���� ��������� ������ ������������������ ��������." << endl;
    cout << "4 - ��������� �������� ������ � �����." << endl;
    cout << "5 - ��������� �������� ������ � ����." << endl;
    //cout << "6 - ������� ������� ������ �� �������." << endl;
    cout << "6 - ������� ������ ��������." << endl;
    cout << "7 - �����" << endl;
}


string check_fullname(string& fullname) {
    istringstream check{ fullname };
    int amount = 0;
    string right_fullname;

    while (check >> fullname) {
        if (amount == 0) right_fullname += fullname;
        else right_fullname += " " + fullname;
        for (char c : fullname) {
            if (!(c >= '�' && c <= '�'))
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
            cout << "������ ����." << endl;
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
            cout << "������ ���������� ����� ��� ���������. ���������� ��� ���." << endl;
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
            cout << "������ ���������� ����� ��� ���������. ���������� ��� ���." << endl;
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
            cout << "������ ����." << endl;
            return;
        }
        Node* node = head;
        max_length_fullname = 4;
        max_length_post = 9;
        max_length_placeOR = 16;

        for (; node != NULL; node = node->next)
            find_max(node->fullname, node->post, node->placeOR);

        cout << setw(max_length_fullname) << " ���" << setw(max_length_post + 3) << "  �������" << setw(max_length_placeOR + 3) << "  �������� ���������" << endl;
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
            cout << "������ ����." << endl;
            return;
        }

        Node* node = head;
        for (; node != NULL; node = node->next) {
            node->fullname = "��������� ������� �����������";
            node->post = "18";
            node->placeOR = "�� �����";
        }
        cout << "������� ��������� �������." << endl;
        return;
    }

    void write_to_file() {
        ofstream file;
        file.open("input.txt");
        if (file.is_open()) {
            if (head == NULL) {
                cout << "������ ����." << endl;
            }
            else {
                Node* node = head;
                max_length_fullname = 4;
                max_length_post = 9;
                max_length_placeOR = 16;

                for (; node != NULL; node = node->next)
                    find_max(node->fullname, node->post, node->placeOR);

                file << setw(max_length_fullname) << " ���" << setw(max_length_post + 3) << " �������" << setw(max_length_placeOR + 3) << " �������� ���������" << endl;
                for (node = head; node != NULL; node = node->next) {
                    file << setw(max_length_fullname) << node->fullname << setw(max_length_post + 3) << node->post << setw(max_length_placeOR + 3) << node->placeOR << endl;
                }
            }

        }
        else {
            cout << "�� ������� ������� ���� ��� ������." << endl;
        }
        file.close();
        return;
    }


    bool read_from_file() {
        /*cout << "---------------------------------------------------------------------------------------" << endl;
        cout << "� ��������� ����� ������ ������ ���� �������� ����� �������. ��������:" << endl;
        cout << "������ ���� ��������, 45, �����" << endl;*/
        //cout << "���������� �������� �� ������ ������. ������ ������� �� ����� ������ �������� ����� ������� ������." << endl;
        //cout << "������ ����������� � ��������. � ������ ������ ������ ���� ����� 2 �������." << endl;
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
                    cout << "��������� ������. ���������� ������ � " << n << " ������." << endl;
                    file.close();
                    flag = 0;
                    break;
                    //return false;
                }
                else if (j > 2) {
                    cout << "��������� ������. ������� ������ � " << n << " ������." << endl;
                    file.close();
                    flag = 0;
                    break;
                }

                arr[0] = check_fullname(arr[0]);
                if (arr[0] == " ") {
                    cout << "��������� ������. ���������� ��� �������������� ������ � ��� � " << n << " ������." << endl;
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
            cout << "�� ������� ������� ���� ��� ������. \n��������� � ���, ��� ��������� ���� ����� �������� \"input.txt\" � ���������� � ������ ���������� " << endl;
            file.close();
            return false;
        }
        file.close();
        return true;
    }


    int pop(int k) {
        if (head == NULL) {
            cout << "---------------------------------------------------------------------------------------" << endl;
            cout << "������ ����." << endl;
            return 2;
        }
        Node* node, * left = get(k - 1);
        if (k == 1) {
            pop_front();
            return 1;
        }
        if (!left || !left->next) {
            cout << "---------------------------------------------------------------------------------------" << endl;
            cout << "������ ���������� ����� ��� ���������. ���������� ��� ���." << endl;
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
    cout << "������ ��������� ��������� ������ ������������ ������." << endl;
    menu_display();


    while (true) {
        cout << "---------------------------------------------------------------------------------------" << endl;
        cout << "��� ��������� ������ ������� ����� 6." << endl;
        cout << ">> ";
        string check;
        getline(cin, check);
        if (check == "1") {
            string fullname, post, placeOR, check;
            int i;

            cout << "---------------------------------------------------------------------------------------" << endl;
            cout << "������� ��� ����� ������ ." << endl;
            while (true) {
                cout << ">> ";
                getline(cin, fullname);
                fullname = check_fullname(fullname);
                if (fullname == " ")
                    cout << "�� ����� �����������! ���������� ��� ���." << endl;
                else break;
            }

            cout << "������� ��� �������." << endl;
            cout << ">> ";
            getline(cin, post);
            post = no_space(post);



            cout << "������� ���� �������� ���������." << endl;
            cout << ">> ";
            getline(cin, placeOR);
            placeOR = no_space(placeOR);



            cout << "������� ���������� ����� ����� �������� ������� �������� ����� �������." << endl;
            while (true) {
                cout << ">> ";
                getline(cin, check);
                i = test_nat(check);
                if (i && lst.push(fullname, post, placeOR, i)) {
                    cout << "���������� ������ �������." << endl;
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
                cout << "������ � ���������� ����� ������ �������." << endl;
        }

        else if (check == "5") {
            cout << "---------------------------------------------------------------------------------------" << endl;
            lst.write_to_file();
            cout << "������ � ��������� ���� \"input.txt\" ������ �������." << endl;
        }

        /*else if (check == "6") {
            cout << "������� ���������� ����� ��� �������� �������� �� ������." << endl;
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
                        cout << "�������� ������ �������." << endl;
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
        else cout << "�� ����� �����������! ���������� ��� ���." << endl;
    }



    cout << "���������� ���������." << endl;

    return 0;
}
