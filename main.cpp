#include <iostream>
#include <memory>
#include <vector>
#include <typeinfo>
#include <algorithm>

using namespace std;

class LibraryItem
{
public:
    LibraryItem(int total_copies) : total_copies_{total_copies}, copies_on_loan_{0} {}

    void returnItem()
    {
        copies_on_loan_--;
        if (total_copies_on_loan_ > 0)
        {
            total_copies_on_loan_--;
        }
    }
    void borrowItem()
    {
        copies_on_loan_++;
        total_copies_on_loan_++;
    }
    int availableCopies() { return total_copies_ - copies_on_loan_; }
    static int totalCopiesOnLoan() { return total_copies_on_loan_; }

private:
    int total_copies_;
    int copies_on_loan_;
    static int total_copies_on_loan_;
};

int LibraryItem::total_copies_on_loan_ = 0;

class Book : public LibraryItem
{
public:
    Book(const string &title, const string &author, int copies) : LibraryItem{copies}, title_{title}, author_{author} {}
    string title() { return title_; }
    string author() { return author_; }

private:
    string title_;
    string author_;
};
class DVD : public LibraryItem
{
public:
    DVD(const string &title, int runtime, int copies) : LibraryItem{copies}, title_{title}, runtime_{runtime} {}
    string title() { return title_; }
    int runtime() { return runtime_; }

private:
    string title_;
    int runtime_;
};

int main()
{

    auto b = Book{"The Great Gatsby", "F.Scott Fitzgerald", 4};
    auto d = DVD{"Star Wars: Episode V - The Empire Strikes", 124, 3};

    cout << b.author() << " " << b.title() << " " << b.availableCopies() << endl;
    cout << d.title() << " " << d.runtime() << " " << d.availableCopies() << endl;
    b.borrowItem();
    b.borrowItem();
    b.borrowItem();

    d.borrowItem();

    cout << LibraryItem::totalCopiesOnLoan() << " ";

    return 0;
}