#pragma once
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>



class Book;
class Publisher
{
public:
    std::string name = "";
    Wt::Dbo::collection< Wt::Dbo::ptr<Book> > book;
    template<class Action>
    void persist(Action& a);// {
      /*  Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, book, Wt::Dbo::ManyToOne, "publisher");
    }*/
};

//class Book
//{
//public:
//    std::string title = "";
//    Wt::Dbo::ptr<Publisher> publisher;
//    template<class Action>
//    void persist(Action& a) {
//        Wt::Dbo::field(a, title, "title");
//    }
//
//};


