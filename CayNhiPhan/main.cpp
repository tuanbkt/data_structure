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

// ham kiem tra so nguyen to
bool KiemTraSNT(int x) {
    if (x < 2) {
        return false;
    } else {
        if(x == 2) {
            return true;
        } else {
            for(int i = 2; i < x; i++) {
                if (x % i == 0) {
                    return false;
                }
            }
        }
    }

    return true;
}

// dem so luong so nguyen to trong cay
void SoLuongSNT(TREE t, int &dem) {
    if (t != NULL) {
        if (KiemTraSNT(t->data)) {
            dem++;
        }
        SoLuongSNT(t->pLeft, dem);
        SoLuongSNT(t->pRight, dem);
    }
}

// kiem tra xem phan tu x co ton tai trong cay hay khong
NODE* TimKiem(TREE t, int x) {
    if (t == NULL) {
        return NULL;
    } else {
        if (x > t->data) {
            // duyet qua cay con ben phai neu x > node goc
            TimKiem(t->pRight, x);
        } else if (x < t->data) {
            // duyet qua cay con ben trai neu x < node goc
            TimKiem(t->pLeft, x);
        } else {
            return t; // tra ve gia tri cua node neu x = node goc
        }
    }
}

// node co hai con
void Node_Hai_Con (TREE t) {
    if (t != NULL) {
        // kiem tra cos ton tai cay con trai va cay con phai hay khong
        if (t->pLeft != NULL && t->pRight != NULL) {
            cout << t->data << "    ";
        }

        Node_Hai_Con(t->pLeft);
        Node_Hai_Con(t->pRight);
    }
}

// node co mot con
void Node_Mot_Con (TREE t) {
    if (t != NULL) {
        // kiem tra cos ton tai cay con trai va cay con phai hay khong
        if ((t->pLeft != NULL && t->pRight == NULL) || (t->pLeft == NULL && t->pRight != NULL)) {
            cout << t->data << "    ";
        }

        Node_Mot_Con(t->pLeft);
        Node_Mot_Con(t->pRight);
    }
}

// node la
void Node_La (TREE t) {
    if (t != NULL) {
        // kiem tra cos ton tai cay con trai va cay con phai hay khong
        if (t->pLeft == NULL && t->pRight == NULL) {
            cout << t->data << "    ";
        }

        Node_La(t->pLeft);
        Node_La(t->pRight);
    }
}

// tim gia tri max trong cay
int Tim_Max (TREE t) {
    if (t != NULL) {
        if (t->pRight == NULL) {
            return t->data;
        }

        return Tim_Max(t->pRight);
    }
}

// tim gia tri min trong cay
int Tim_Min (TREE t) {
    if (t != NULL) {
        if (t->pLeft == NULL) {
            return t->data;
        }

        return Tim_Min(t->pLeft);
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
        cout << "8. Dem so luong so nguyen to trong cay" << endl;
        cout << "9. Tim kiem phan tu trong cay" << endl;
        cout << "10. Xuat cac node co 2 con" << endl;
        cout << "11. Xuat cac node co 1 con" << endl;
        cout << "12. Xuat cac node la" << endl;
        cout << "13. Tim gia tri MAX" << endl;
        cout << "14. Tim gia tri MIN" << endl;
        cout << "0. Ket thuc" << endl << endl;

        int luachon;

        cout << "Nhap lua chon: ";
        cin >> luachon;

        if (luachon < 0 || luachon > 14) {
            cout << "Lua chon khong hop le" << endl << endl;
            getchar();
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
        } else if (luachon == 8) {
            int dem = 0;
            SoLuongSNT(t, dem);
            cout << "So luong so nguyen to trong cay: " << dem;
            cout << endl << endl;
        } else if (luachon == 9) {
            int x;
            cout << "Nhap so nguyen can tim kiem: ";
            cin >> x;

            NODE *p = TimKiem(t, x);

            if(p == NULL) {
                cout << "Phan tu " << x << " khong ton tai trong cay" << endl << endl;
            } else {
                cout << "Phan tu " << x << " co ton tai trong cay" << endl << endl;
            }
        } else if (luachon == 10) {
            cout << "Node co 2 con: ";
            Node_Hai_Con(t);
            cout << endl << endl;
        } else if (luachon == 11) {
            cout << "Node co 1 con: ";
            Node_Mot_Con(t);
            cout << endl << endl;
        } else if (luachon == 12) {
            cout << "Node La: ";
            Node_La(t);
            cout << endl << endl;
        } else if (luachon == 13) {
            cout << "MAX = " << Tim_Max(t) << endl << endl;
        } else if (luachon == 14) {
            cout << "MIN = " << Tim_Min(t) << endl << endl;
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

    getchar();
    return 0;
}
