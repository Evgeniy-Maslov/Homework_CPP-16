#pragma once
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include "Publisher.h"



class Book
{
public:
    std::string title = "";
    Wt::Dbo::ptr<Publisher> publisher;
    template<class Action>
    void persist(Action& a);
};

