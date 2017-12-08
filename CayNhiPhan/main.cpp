#include <iostream>

using namespace std;

struct node {
    int data;
    struct node *pLeft;
    struct node *pRight;
};

typedef struct node NODE;
typedef NODE* TREE;

void KhoiTaoCay (TREE &t) {
    t = NULL;
}

void ThemNodeVaoCay (TREE &t, int x) {
    if (t == NULL) {
        NODE *p = new NODE;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    } else {
        if (x > t->data) {
            ThemNodeVaoCay(t->pRight, x);
        } else if (x < t->data) {
            ThemNodeVaoCay(t->pLeft, x);
        }
    }
}

void Duyet_NLR (TREE t) {
    if (t != NULL) {
        cout << t->data << " ";
        Duyet_NLR(t->pLeft);
        Duyet_NLR(t->pRight);
    }
}

void Duyet_NRL (TREE t) {
    if (t != NULL) {
        cout << t->data << " ";
        Duyet_NRL(t->pRight);
        Duyet_NRL(t->pLeft);
    }
}

void Duyet_LNR (TREE t) {
    if (t != NULL) {
        Duyet_LNR(t->pLeft);
        cout << t->data << " ";
        Duyet_LNR(t->pRight);
    }
}

void Duyet_RNL (TREE t) {
    if (t != NULL) {
        Duyet_RNL(t->pRight);
        cout << t->data << " ";
        Duyet_RNL(t->pLeft);
    }
}

void Duyet_LRN (TREE t) {
    if (t != NULL) {
        Duyet_LRN(t->pLeft);
        Duyet_LRN(t->pRight);
        cout << t->data << " ";
    }
}

void Duyet_RLN (TREE t) {
    if (t != NULL) {
        Duyet_RLN(t->pRight);
        Duyet_RLN(t->pLeft);
        cout << t->data << " ";
    }
}

void MENU (TREE &t) {
    while (true) {
        cout << "========== MENU ==========" << endl;
        cout << "1. Nhap du lieu" << endl;
        cout << "2. Xuat du lieu cay theo NLR" << endl;
        cout << "3. Xuat du lieu cay theo NRL" << endl;
        cout << "4. Xuat du lieu cay theo thu tu tang dan (LNR)" << endl;
        cout << "5. Xuat du lieu cay theo thu tu giam dan (RNL)" << endl;
        cout << "6. Xuat du lieu cay theo LRN" << endl;
        cout << "7. Xuat du lieu cay theo RLN" << endl;
        cout << "0. Ket thuc" << endl << endl;

        int luachon;

        cout << "Nhap lua chon: ";
        cin >> luachon;

        if (luachon < 0 || luachon > 7) {
            cout << "Lua chon khong hop le" << endl << endl;
            system("pause");
        } else if (luachon == 1) {
            int x;
            cout << "Nhap so nguyen x: ";
            cin >> x;
            ThemNodeVaoCay(t, x);
            cout << endl;
        } else if (luachon == 2) {
            cout << "Duyet cay theo NLR" << endl;
            Duyet_NLR(t);
            cout << endl << endl;
        } else if (luachon == 3) {
            cout << "Duyet cay theo NRL" << endl;
            Duyet_NRL(t);
            cout << endl << endl;
        } else if (luachon == 4) {
            cout << "Duyet cay theo thu tu tang dan (LNR)" << endl;
            Duyet_LNR(t);
            cout << endl << endl;
        } else if (luachon == 5) {
            cout << "Duyet cay theo thu tu giam dan (RNL)" << endl;
            Duyet_RNL(t);
            cout << endl << endl;
        } else if (luachon == 6) {
            cout << "Duyet cay theo LRN" << endl;
            Duyet_LRN(t);
            cout << endl << endl;
        } else if (luachon == 7) {
            cout << "Duyet cay theo RLN" << endl;
            Duyet_RLN(t);
            cout << endl << endl;
        } else {
            break;
        }
    }
}

int main()
{
    TREE t;
    KhoiTaoCay(t);
    MENU(t);

    system("pause");
    return 0;
}
