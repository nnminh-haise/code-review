#include <iostream>
#include <string>

using namespace std;

int stt;

// ! Adding a date struct will help you a lot!
struct Date {
    int day, month, year;
};

enum Status {
    PENDING, IN_PROCESS, DONE, CANCELED, OVERDUE
};

struct congviec {
    string trang_thai, tieu_de, do_uu_tien, bat_dau, ket_thuc, note;

    int statusInput() {
        std::cout << "*---Status options---*\n";
        std::cout << "| [0]: PENDING       |\n";
        std::cout << "| [1]: IN PROCESS    |\n";
        std::cout << "| [2]: DONE          |\n";
        std::cout << "| [3]: CANCELED      |\n";
        std::cout << "| [4]: OVERDUE       |\n";
        std::cout << "*--------------------*\n";
        std::cout << "\n";

        int option = 0;
        do {
            std::cout << "Your selection: ";
            std::cin >> option;
            if (option < 0 || option > 4) {
                std::cout << "Invalid option! Choose another one!\n";
            }
            else {
                break;
            }
        } while (true);

        return option;
    }

    void them_thong_tin() {
        cout << "===================================\n";
        cout << "Nhap trang thai: "; cin >> trang_thai;
        cout << "Nhap tieu de: "; cin.ignore(); getline(cin, tieu_de);
        cout << "Nhap muc do quan trong: "; cin >> do_uu_tien;
        cout << "Nhap ngay hien tai: "; cin >> bat_dau;
        cout << "Nhap ngay ket thuc: "; cin >> ket_thuc;
        cout << "Nhap ghi chu: "; cin.ignore(); getline(cin, note);
    }

    void in_thong_tin() {
        cout << "Trang thai: " << trang_thai << '\n';
        cout << "Tieu de: " << tieu_de << '\n';
        cout << "Muc do quan trong: " << do_uu_tien << '\n';
        cout << "Ngay hien tai: " << bat_dau << '\n';
        cout << "Ngay ket thuc: " << ket_thuc << '\n';
        cout << "Ghi chu: " << note << '\n';
    }
};

void in_danh_sach(congviec a[], int n) {
    cout << "Thong tin danh sach cong viec:\n";
    for (int i = 0; i < n; i++) {
        cout << "=====================================\n";
        cout << "STT: " << i + 1 << "\n";
        a[i].in_thong_tin();
    }
}

void xoa(congviec a[], int& n, int& stt) {
    for (int i = stt + 1; i < n; i++) {
        a[i - 1] = a[i];
    }
    n -= 1;
}

void chinhsua(congviec a[], int& stt) {
    int tmp;
    cout << "1: Chinh sua trang thai\n";
    cout << "2: Chinh sua tieu de\n";
    cout << "3: Chinh sua muc do quan trong\n";
    cout << "4: Chinh sua ngay hien tai\n";
    cout << "5: Chinh sua ngay ket thuc\n";
    cout << "6: Chinh sua ghi chu\n";
    cin >> tmp;
    if (tmp == 1) {
        cin >> a[stt].trang_thai;
    }
    if (tmp == 2) {
        cin.ignore(); getline(cin, a[stt].tieu_de);
    }
    if (tmp == 3) {
        cin >> a[stt].do_uu_tien;
    }
    if (tmp == 4) {
        cin >> a[stt].bat_dau;
    }
    if (tmp == 5) {
        cin >> a[stt].ket_thuc;
    }
    if (tmp == 6) {
        cin.ignore(); getline(cin, a[stt].note);
    }
}

//THU lan 1
//void xuat_file(congviec a[], int &n){
//    freopen("COLLECT.txt" , "w" , stdout);
//	in_danh_sach(a, n);
//}


/*
 * * New menu which returns a user's selected option everytime the menu is printed!
 * * By default, menu return 0 which means shutdown the program
 */
int printMenu() {
    cout << "*===============MENU============*\n";
    cout << "| [1]: Them thong tin cong viec |\n";
    cout << "| [2]: In danh sach cong viec   |\n";
    cout << "| [3]: Xoa 1 dau cong viec      |\n";
    cout << "| [4]: Sua 1 dau viec           |\n";
    cout << "| [5]: Xuat file txt            |\n";
    cout << "| [0]: Thoat                    |\n";
    cout << "*===============================*\n";
    cout << "\n";

    int option = 0;
    do {
        std::cout << "Select option: ";
        std::cin >> option;
        if (option < 0 || option > 5) {
            std::cout << "Invalid option! Enter another one!\n";
        }
        else {
            break;
        }
    } while (true);

    return option;
}

int main() {
    congviec a[1000];
    int n = 0;

    int userOption = 0;
    bool mainLoopStop = false;
    while (!mainLoopStop) {
        userOption = printMenu();

        switch (userOption) {
            case (1): {
                break;
            }
            case (2): {
                break;
            }
            case (3): {
                break;
            }
            case (4): {
                break;
            }
            case (5): {
                break;
            }
            default: {
                mainLoopStop = true;
                break;
            }
        }

        //-- your code below!

        cout << "-------------------MENU=============\n";
        cout << "1: Them thong tin cong viec\n";
        cout << "2: In danh sach cong viec\n";
        cout << "3: Xoa 1 dau cong viec\n";
        cout << "4: Sua 1 dau viec\n";
        cout << "5: Xuat file txt\n";
        cout << "0: Thoat\n";
        cout << "=======================\n";


        cout << "Nhap lua chon: "; int chon; cin >> chon;
        if (chon == 1) {
            a[n].them_thong_tin();
            n++;
        }
        if (chon == 2) {
            cout << "=====================================\n";
            in_danh_sach(a, n);
        }
        if (chon == 3) {
            in_danh_sach(a, n);
            cout << "Nhap STT cua cong viec muon xoa: "; cin >> stt;
            stt -= 1;
            xoa(a, n, stt);
            //            cout << "\nN ne: " << n << '\n';
        }
        if (chon == 4) {
            //in danh sach de cho nguoi ta coi ne'
            //xu li
            cout << "Nhap stt cua cviec muon chinh sua: "; cin >> stt;
            stt -= 1;
            chinhsua(a, stt);
        }
        //        if (chon == 5){
         //           xuat_file(a, n);
           //     }
        else if (chon == 0) {
            break;
        }
    }
    return 0;
}