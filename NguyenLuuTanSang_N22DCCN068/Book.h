#pragma once
#include <bits/stdc++.h>

#include <vector>
#include <iostream>

using namespace std;

class Book {
private:
    string nameBook;
    string nameAuthor;
    int numberBook;
public:
    Book() {}
    Book(string nameBook, string nameAuthor, int numberBook): nameBook(nameBook), nameAuthor(nameAuthor), numberBook(numberBook) {}

    // ! Viết một hàm setBook() để nhập dữ liệu vào cho sách sẽ tốt hơn là overload operator >> nha!
    friend istream& operator >> (istream &in, Book &a) {
        cout << "--------------Enter A Book------------" << endl;
        cout << "Name: "; in >> a.nameBook; cout << endl;
        cout << "Author: "; in>> a.nameAuthor; cout << endl;
        cout << "Number: "; in>> a.numberBook; cout << endl;
        return in;
    }

    // ! Viết một hàm getBook() để in dữ liệu vào cho sách sẽ tốt hơn là overload operator << nha!
    friend ostream& operator << (ostream &out, Book a) {
        out << "=================================================" << endl;
        out << "Name Book: " << a.nameBook << endl;
        out << "Name Author: " << a.nameAuthor << endl;
        out << "Number Book: " << a.numberBook << endl;
        out << "=================================================" << endl;
        return out;
    }

    string getNameBook() {
        return nameBook;
    }
    string getNameAuthor() {
        return nameAuthor;
    }
    int getNumberBook() {
        return numberBook;
    }

    /*
     * ! These two methods can be separate into a new namespace called BookList then inside that namespace you can write
     * these two methods. It's really weird to see a book that takes in a list of book then return the size of that list
     */
    static int numOfTypeBooks(vector<Book> vb) {
        return vb.size();
    }
    static int totalNumOfBooks(vector<Book> vb) {
        long long count(0);
        for(int i(0); i<vb.size(); i++) {
            count+=vb[i].getNumberBook();
        }
        return count;
    }
};