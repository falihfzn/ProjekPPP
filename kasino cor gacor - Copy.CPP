#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include <thread>
#include <string>
using namespace std;

int i, n, guess, lucky;
long long int deposit, bet_amount;
string name;
char choice;

void input();
void draw_line(int);
void rules();
void start();
void sleep_for(string, int);

int main() {
    input();
    sleep_for("\n\n\t\t\t\t\tSELAMAT DATANG DI KASINO GA'C'OR\n", 70);
    draw_line(120);
    rules();
    draw_line(120);
    start();
}

void input() {
    cout << "Masukkan nama pemain: ";
    getline(cin, name);
    cout << "\n";
    cout << "Masukkan jumlah uang untuk deposit: Rp";
    cin >> deposit;

    system("cls");
}

void draw_line(int n) {
    cout << "\n\n\n";
    for (i = 0; i < n; i++)
        cout << "_";
    cout << "\n";
}

void rules() {
    cout << "\nATURAN BERMAIN:\n";
    cout << "\n\n";
    cout << "1.Anda harus menebak sebuah angka dari 1 sampai 10.\n\n";
    cout << "2.Jika angka yang anda tebak benar, Anda akan mendapat 10x lipat dari uang taruhan.\n\n";
    cout << "3.Jika anda salah menebak, Anda akan kehilangan seluruh uang taruhan.\n";
}

void setcolor(unsigned short color) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, color);
}

void start() {
again:
    if (deposit > 0) {
        setcolor(7);
        cout << "\n\n";
        cout << "Anda memiliki Rp" << deposit << ".";
        cout << "\n\n";
    re_enter:
        cout << "\nMasukkan jumlah taruhan: Rp";
        cin >> bet_amount;

        if (bet_amount > deposit) {
            setcolor(4);
            cout << "\n\nTaruhan anda melebihi uang yang anda miliki!\n";
            setcolor(7);
            cout << "\nAnda hanya bisa bertaruh sampai dengan Rp" << deposit << ".\n\n";
            goto re_enter;
        }

        deposit -= bet_amount;

        cout << "\nMasukkan tebakan Anda: ";
        cin >> guess;

        lucky = rand() % 10 + 1;

        if (lucky == guess) {
            setcolor(10);
            cout << "\nSelamat! Anda telah menebak angka dengan benar!\n\n";
            deposit = deposit + (bet_amount * 10);
            setcolor(7);
            cout << "Uang anda sekarang adalah Rp" << deposit << "\n\n";
        } else {
            setcolor(4);
            cout << "\nHAHAHAHAHA!! Makanya jangan judi!\n\n";
            setcolor(7);
            cout << "\nAngka keberuntungan : " << lucky << "\n";
            cout << "\nUang anda sekarang adalah Rp" << deposit << "\n\n";
        }

        setcolor(6);
        cout << "\nLanjutkan Taruhan ? (y/n)\n";
        cout << "choice: ";
        cin >> choice;

        if (choice == 'y')
            goto again;
        else
            setcolor(7);
        cout << "\n\nNanti main lagi ya !\n\n";

    } else {
        setcolor(4);
        cout << "\nUang Anda tidak cukup untuk bermain taruhan !\n\n";
        setcolor(6);
        cout << "\nMasukkan uang lagi ?(y/n)\n";
        cout << "choice: ";
        cin >> choice;

        if (choice == 'y') {
            system("cls");
            setcolor(7);
            cout << "Masukkan jumlah uang : Rp";
            cin >> deposit;
            start();
        } else
            cout << "\n\nNanti main lagi ya !\n\n";
    }
}

void sleep_for(string message, int milliseconds) {
    for (char c : message) {
        cout << c;
        this_thread::sleep_for(chrono::milliseconds(milliseconds));
    }
}
