#include <iostream>
#include <string>
using namespace std;

// ������� ����� publication
class publication {
protected:
    string title;
    float price;
public:
    publication() : title(""), price(0.0) {}
    publication(const string& t, float p) : title(t), price(p) {}

    virtual void getdata() {
        cout << "������� ��������: ";
        cin >> title;
        cout << "������� ����: ";
        cin >> price;
    }

    virtual void putdata() const {
        cout << "��������: " << title << ", ����: $" << price;
    }

    // ����� ����������� ������� isOversize
    virtual bool isOversize() const = 0;

    // ����������� ����������
    virtual ~publication() {}
};

// ����������� ����� book
class book : public publication {
private:
    int pages;
public:
    book() : pages(0) {}
    book(const string& t, float p, int pg) : publication(t, p), pages(pg) {}

    void getdata() override {
        publication::getdata();
        cout << "������� ���������� �������: ";
        cin >> pages;
    }

    void putdata() const override {
        publication::putdata();
        cout << ", �������: " << pages << endl;
    }

    bool isOversize() const override {
        return pages > 800;
    }
};

// ����������� ����� tape
class tape : public publication {
private:
    float playtime; // ����� ��������������� � �������
public:
    tape() : playtime(0.0) {}
    tape(const string& t, float p, float pt) : publication(t, p), playtime(pt) {}

    void getdata() override {
        publication::getdata();
        cout << "������� ����� ��������������� (� �������): ";
        cin >> playtime;
    }

    void putdata() const override {
        publication::putdata();
        cout << ", �����: " << playtime << " �����" << endl;
    }

    bool isOversize() const override {
        return playtime > 90;
    }
};

int main() {
    publication* pubarr[100]; // ������ ���������� �� publication
    int n = 0; // ������� ���������� ��������
    char choice;

    // ���� ������
    do {
        cout << "�������� ����� (b) ��� ������� (t)? ";
        cin >> choice;
        if (choice == 'b') {
            pubarr[n] = new book();
        }
        else if (choice == 't') {
            pubarr[n] = new tape();
        }
        else {
            cout << "�������� �����!\n";
            continue;
        }
        pubarr[n]->getdata();
        n++;
        cout << "���������� (y/n)? ";
        cin >> choice;
    } while (choice == 'y' && n < 100);

    // ����� ������ � �������� �� ���������� �������
    cout << "\n������ ����������:\n";
    for (int i = 0; i < n; i++) {
        pubarr[i]->putdata();
        if (pubarr[i]->isOversize()) {
            cout << "���������� �������!\n";
        }
        cout << endl;
    }

    // ������������ ������
    for (int i = 0; i < n; i++) {
        delete pubarr[i];
    }

    return 0;
}