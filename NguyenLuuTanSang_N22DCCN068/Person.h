#pragma once

#include "Book.h"
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Person {
private:
    string name;
    int age;
    string add;
    vector<Book> vb;
public:
    Person() {}
    Person(string name, int age, string add, vector<Book> vb) : name(name), age(age), add(add), vb(vb) {}

    // ! Viết một hàm setPerson() để in dữ liệu vào cho sách sẽ tốt hơn là overload operator << nha!
    friend istream& operator >> (istream &in, Person &a) {
        cout << "--------------Enter A Person------------" << endl;
        cout << "Name: "; in >> a.name; cout << endl;
        cout << "Age: "; in >> a.age; cout << endl;
        cout << "Address: "; in >> a.add; cout << endl; 
        int n;
        cout << "Enter the number of books borrowed: "; in >> n;
        a.vb.clear(); // Clear the vector before adding new books
        for (int i = 0; i < n; i++) {
            Book b;
            cin >> b;
            a.vb.push_back(b);
        }
        return in;
    }
    // friend ostream& operator <<(ostream &out, Person& a) {
	// 	cout << "Name: " << a.name << endl;
	// 	cout << "Age: " << a.age << endl;
	// 	cout << "Add: " << a.add << endl;
	// 	cout << "List Book Borrowed:" << endl;
	// 	for (int i = 0; i < a.vb.size(); i++)
	// 	{
	// 		cout << a.vb[i];
	// 	}
	// 	cout << "Money Pay: " << a.moneyPay() << endl;
    // }

    virtual void display()
	{
        cout << "=================================================" << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Add: " << add << endl;
		cout << "List Book Borrowed:" << endl;
		for (int i = 0; i < vb.size(); i++)
		{
			cout << vb[i];
		}
		cout << "Money Pay: " << moneyPay() << endl;
        cout << "=================================================" << endl;
	}

    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
    string getAdd() {
        return add;
    }
    vector<Book> getVB() {
        return vb;
    }

    // ! The same comment inside the Book header
    static int numOfPeople(vector<Person*> vp) {
        return vp.size();
    }
    void setName(string name) {
        this->name=name;
    }
    void setAge(int age) {
        this->age=age;
    }
    void setAdd(string add) {
        this->add=add;
    }
    void addBook(Book book) {
        vb.push_back(book);
    }
    virtual long moneyPay() =0;

    // ! The same comment inside the Book header
    static void sortPersonAge(vector<Person*> &vt) {
        for(int i=0; i< vt.size()-1; i++) {
            int min=i;
            for(int j=i+1; j<vt.size(); j++) {
                if(vt[j]->age<vt[min]->age) {
                    min=j;
                }
            }
            swap(vt[i], vt[min]);
        }
    }

    // ! The same comment inside the Book header
    // ! Performance and logic bottle necking
    static vector<int> getListAge(vector<Person*> vt) {
        vector<int> result;
        for(int i(0); i<vt.size(); i++) {
            auto it =find(result.begin(), result.end(), vt[i]->age);
            if (it==result.end())
            {
                result.push_back(vt[i]->age);
            }
        }
        return result;
    }

    // ! The same comment inside the Book header
    static vector<Book> getMaxBookBorrowed(vector<Person*> vp, vector<Book> vb) {

        vector<int> cnt(vb.size(), 0);

        // Count the number of time that this book is being borrowed =))
        // ! This in real-life is not that simple =))) but good idea! could be a lot better!
        for(int i(0); i<vb.size(); i++) {
            for(int j(0); j<vp.size(); j++) {
                // * List of book that this vp[i] is borrowing
                vector<Book> b(vp[j]->getVB());

                for(int k(0); k<b.size(); k++) {
                    if(vb[i].getNameBook()==b[k].getNameBook()) {
                        cnt[i]++;
                    }
                }
            }
        }

        vector<int> copycat=cnt;
        // * Sort to get five the most popular books
        sort(copycat.rbegin(), copycat.rend());

        /*
         * * The result vector returns the list of 5 books may contains duplicates right?
         * * You can sort that out by ensure that no duplicates in the vector<Book>!
         */
        vector<Book> result;
        for (int i = 0; i < 5; i++) {
                for (int j = 0; j < vb.size(); j++) {
                    if (cnt[j] == copycat[i] && result.size()<5) {
                        bool ok=0;

                        // * Check duplicates?
                        for(int k(0); k<result.size(); k++) {
                            if(result[k].getNameBook()==vb[j].getNameBook()) {
                                ok=1;
                                break;
                            }
                        }
                            if(!ok) {
                                result.push_back(vb[j]);
                            }
                    }
                }
            }
        return result;
    } 


};
