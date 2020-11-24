#include <iostream>
#include <ctime>
#include <string.h>

using namespace std;

class Author{
    public:
        Author(std::string n, std::string nat, int y)
        :name(n),
         nationality(nat),
         birth_year(y)
        {}

        ~Author(){}

        std::string getName(){ return name; }
        std::string getNationality(){ return nationality; }
        int getBirthYear(){ return birth_year; }
    private:
        std::string name;
        std::string nationality;
        int birth_year;
        Author& operator=(const Author&);
};

class Document{
    public:
        Document(Author& a)
        :author(new Author(a)),
         year(0)
        {}

        Document(const Document& rhs){
            author = new Author(*rhs.author);
            year = rhs.year;
        }

        //return reference to *this and handle assignment to self
        Document& operator=(const Document& rhs){
            Author *aOrig = author;
            author = new Author(*rhs.author);
            delete(aOrig);
            return *this;
        }

        ~Document(){
            delete author;
            cout<<"Doc destructor"<<endl;
        }
         
        void setYear(int y){ year = y; }
        std::string getAuthor(){ return author->getName(); }
        int getYear(){ return year; }
    protected:
        Author *author;
        int year;
};

class Book: public Document{
    public:
        Book(Author a, std::string t)
        :Document(a),
         title(t)
        {}

        //copy all data members of the object and all of its base class members
        Book(const Book& rhs)
        :Document(rhs),
         title(rhs.title)
        {}

        Book& operator=(const Book& rhs){
            Document::operator=(rhs);
            title = rhs.title;
            return *this;
        }

        ~Book(){}

        std::string getTitle(){ return title; }
    private:
        std::string title;
};
class EMail: public Document{
    public:
        EMail(Author a)
        :Document(a),
         subject(),
         to()
        {}

        ~EMail(){}

        void setSubject(std::string s){ subject = s; }
        void setTo(std::string t){ to = t; }
        std::string getSubject(){ return subject; }
        std::string getTo(){ return to; }
    private:
        std::string subject;
        std::string to;
        //cannot copy an EMail
        EMail(const EMail&);
        EMail operator=(const EMail&);
};


int main()
{
   Author a1("George Orwell", "british", 1903);
    Book b1(a1, "1984");
    b1.setYear(1949);
    Book b2(b1);
    Book b3 = Book(b1);

    cout<<"Book 1:\nAuthor:\t"<<b1.getAuthor()<<"\ntitle\t"<<b1.getTitle()<<"\nPublishing year\t"<<b1.getYear()<<endl<<endl;
    cout<<"Book 2:\nAuthor:\t"<<b2.getAuthor()<<"\ntitle\t"<<b2.getTitle()<<"\nPublishing year\t"<<b2.getYear()<<endl<<endl;
    cout<<"Book 3:\nAuthor:\t"<<b3.getAuthor()<<"\ntitle\t"<<b3.getTitle()<<"\nPublishing year\t"<<b3.getYear()<<endl<<endl; 
}
