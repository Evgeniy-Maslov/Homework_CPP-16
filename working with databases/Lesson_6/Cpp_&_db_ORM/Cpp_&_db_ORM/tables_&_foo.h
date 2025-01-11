#pragma once



class Book;
class Stock;
class Sale;

class Publisher
{
public:
    std::string name{};
    Wt::Dbo::collection< Wt::Dbo::ptr<Book> > book;
    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, book, Wt::Dbo::ManyToOne, "publisher");
    }
};

class Book
{
public:
    std::string title{};
    Wt::Dbo::ptr<Publisher> publisher;
    Wt::Dbo::collection< Wt::Dbo::ptr<Stock> > stock;
    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, title, "title");
        Wt::Dbo::belongsTo(a, publisher, "publisher");
        Wt::Dbo::hasMany(a, stock, Wt::Dbo::ManyToOne, "book");
    }

};

class Shop
{
public:
    std::string name{};
    Wt::Dbo::collection< Wt::Dbo::ptr<Stock> > stock;
    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, stock, Wt::Dbo::ManyToOne, "shop");
    }
};

class Stock
{
public:
    int count{};
    Wt::Dbo::collection< Wt::Dbo::ptr<Sale> > sale;
    Wt::Dbo::ptr<Shop> shop;
    Wt::Dbo::ptr<Book> book;
    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::hasMany(a, sale, Wt::Dbo::ManyToOne, "stock");
        Wt::Dbo::belongsTo(a, shop, "shop");
        Wt::Dbo::belongsTo(a, book, "book");
    }
};

class Sale {
public:
    int price{};
    int count{};
    std::string data_sale = "";
    Wt::Dbo::ptr<Stock> stock;
    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, price, "price");
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::field(a, data_sale, "data_sale");
        Wt::Dbo::belongsTo(a, stock, "stock");
    }
};

void FillTables(Wt::Dbo::Session& session, std::vector<std::vector<std::string>>& data) {
    for (size_t i = 0; i < data.size(); ++i) {
        Wt::Dbo::Transaction transaction{ session };
        if (i == 0) {
            bool author = false;
            author = session.query<bool>("SELECT publisher.id FROM publisher WHERE publisher.name= ?").bind(data[i][0]) ;
            if (not author) {
                std::unique_ptr<Publisher> publisher{ new Publisher };
                publisher->name = data[i][0];
                session.add(std::move(publisher));
                
            }
            else {
                std::cout << data[i][0] << " The publisher already exists in the database\n";
                break;
            }
        }
        else {
            std::unique_ptr<Book> book{ new Book };
            book->title = data[i][0];
            book->publisher = session.find<Publisher>().where("name='" + data[0][0] + "'");
            session.add(std::move(book));

            std::unique_ptr<Shop> shop{ new Shop };
            bool shp = false;
            shp = session.query<bool>("SELECT shop.id FROM shop WHERE shop.name= ?").bind(data[i][2]);
            if (not shp) {
                shop->name = data[i][2];
                session.add(std::move(shop));
            }
          
            std::unique_ptr<Stock> stock{ new Stock };
            stock->count = stoi(data[i][1]);
            stock->book = session.find<Book>().where("title='" + data[i][0] + "'");
            stock->shop = session.find<Shop>().where("name='" + data[i][2] + "'");
            session.add(std::move(stock));

            std::unique_ptr<Sale> sale{ new Sale };
            sale->price = stoi(data[i][3]);
            sale->data_sale = data[i][4];
            sale->count = stoi(data[i][5]);
            sale->stock = session.find<Stock>("id").orderBy("id DESC").limit(1);
            session.add(std::move(sale));

            std::unique_ptr<Sale> sale1{ new Sale };
            sale1->price = stoi(data[i][3]);
            sale1->data_sale = data[i][6];
            sale1->count = stoi(data[i][7]);
            sale1->stock = session.find<Stock>("id").orderBy("id DESC").limit(1);
            session.add(std::move(sale1));
        }
        transaction.commit();
    }
};

void GetInfo(Wt::Dbo::Session& session, std::string& name) {
    Wt::Dbo::Transaction transaction{ session };
    std::cout << "\n";
    std::cout << "Enter name author: ";
    std::cout << name << "\n";
    Wt::Dbo::ptr<Publisher> publisher = session.find<Publisher>().where("name = ?").bind(name);
    for (auto book : publisher->book) {
        std::cout << "Book '" << book->title << "' ";
        for (auto stock : book->stock) {
            std::cout << "is sold in '" << stock->shop->name << "' store.\n";
        }
    }
    std::cout << "\n";
    transaction.commit();
}