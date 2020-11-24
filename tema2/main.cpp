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


int main()
{
    
}