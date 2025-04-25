#include <iostream>
using namespace std;

class link {
public:
    double data;
    link* next;
    link(double d) : data(d), next(nullptr) {}
};

class linklist {
private:
    link* first;
public:
    linklist() : first(nullptr) {}

    // ����������� �����������
    linklist(const linklist& other) : first(nullptr) {
        link* current = other.first;
        link* last = nullptr;
        while (current) {
            link* newlink = new link(current->data);
            if (!first) {
                first = newlink;
            }
            else {
                last->next = newlink;
            }
            last = newlink;
            current = current->next;
        }
    }

    void additem(double d) {
        link* newlink = new link(d);
        newlink->next = first;
        first = newlink;
    }

    void display() const {
        link* current = first;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // ���������� ��������� ������������
    linklist& operator=(const linklist& other) {
        if (this == &other) return *this;

        // ������� �������� ������
        while (first) {
            link* temp = first;
            first = first->next;
            delete temp;
        }

        // ����������� ���������
        link* current = other.first;
        link* last = nullptr;
        while (current) {
            link* newlink = new link(current->data);
            if (!first) {
                first = newlink;
            }
            else {
                last->next = newlink;
            }
            last = newlink;
            current = current->next;
        }

        return *this;
    }

    // ����������
    ~linklist() {
        while (first) {
            link* temp = first;
            first = first->next;
            delete temp;
        }
    }
};

int main() {
    linklist* list1 = new linklist();
    list1->additem(1.5);
    list1->additem(2.7);
    list1->additem(3.2);

    cout << "������ 1: ";
    list1->display();

    linklist* list2 = new linklist();
    *list2 = *list1;

    cout << "������ 2 (����� ������������): ";
    list2->display();

    delete list1;
    cout << "������ 2 (����� �������� list1): ";
    list2->display();

    delete list2;
    return 0;
}