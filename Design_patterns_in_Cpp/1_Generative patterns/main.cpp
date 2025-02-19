#include <cassert>
#include <string>
#include <iostream>
#include <map>
#include <vector>

class sql_query_builder 
{
public:
    std::string column;
    std::string from;
    std::string where;
    std::string select;
    void AcceptQuest() 
    {
        std::cout << "Accepted request: " << select << std::endl;
    }
};


class SqlSelectQueryBuilder
{
protected:
    sql_query_builder _SqlQueryBuilder_;
public:
    SqlSelectQueryBuilder& AddColumn(const std::string& name_column)
    {
        if (_SqlQueryBuilder_.column.empty())
        {
            _SqlQueryBuilder_.column = name_column;
        }
        else
        {
            _SqlQueryBuilder_.column += ", " + name_column;
        }
        return *this;
    }

    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept
    {
        for (const auto& name_column : columns)
        {
            AddColumn(name_column);
        }
        return *this;
    }

    SqlSelectQueryBuilder& AddFrom(const std::string& name_table)
    {
        _SqlQueryBuilder_.from = name_table;
        return *this;
    }
    SqlSelectQueryBuilder& AddWhere(const std::string& name_column, const std::string& row)
    {
        if (_SqlQueryBuilder_.where.empty())
        {
            _SqlQueryBuilder_.where = name_column + "=" + row;
        }
        else
        {
            _SqlQueryBuilder_.where += " AND " + name_column + "=" + row;
        }
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept
    {
        for (const auto& [name_column, row] : kv)
        {
            AddWhere(name_column, row);
        }
        return *this;
    }

    std::string BuildQuery()
    {
        _SqlQueryBuilder_.column.empty() ? _SqlQueryBuilder_.select = "SELECT *" : _SqlQueryBuilder_.select = "SELECT " + _SqlQueryBuilder_.column;
        _SqlQueryBuilder_.select += " FROM " + _SqlQueryBuilder_.from;
        _SqlQueryBuilder_.select += " WHERE " + _SqlQueryBuilder_.where;
        _SqlQueryBuilder_.select += ";";
        _SqlQueryBuilder_.column.clear();
        _SqlQueryBuilder_.from.clear();
        _SqlQueryBuilder_.where.clear();
        _SqlQueryBuilder_.AcceptQuest();
        return _SqlQueryBuilder_.select;
    }
};

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder
{
public:
    AdvancedSqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv, const char* condition) noexcept
    {
        switch(*condition)
        {
        case '>':
            DerivedMethod(kv, condition);
            break;
        case '<':
            DerivedMethod(kv, condition);
            break;
        default:
            std::cout << "  --- The conditional operator does not meet the requirements !!! ---" << std::endl;
            break;
        }
        return *this;
    }
    AdvancedSqlSelectQueryBuilder& DerivedMethod(const std::map<std::string, std::string>& kv, const char* condition)
    {
        for (const auto& [name_column, row] : kv)
        {
            if (_SqlQueryBuilder_.where.empty())
            {
                _SqlQueryBuilder_.where = name_column + condition + row;
            }
            else
            {
                _SqlQueryBuilder_.where += " AND " + name_column + condition + row;
            }
            return *this;
        }
    }
};


int main()
{
    // Task 1
    std::cout << "Task 1" << std::endl;
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");
    assert(query_builder.BuildQuery() == "SELECT name, phone FROM students WHERE id=42 AND name=John;");
    std::cout << std::endl;
 
    query_builder.AddFrom("teacher");
    query_builder.AddWhere("department", "physics");
    assert(query_builder.BuildQuery() == "SELECT * FROM teacher WHERE department=physics;");
    std::cout << std::endl;

    // Task 2
    std::cout << "Task 2" << std::endl;
    query_builder.AddColumns({ "name", "phone" });
    query_builder.AddFrom("teacher");
    query_builder.AddWhere({ {"id", "16"}, {"name", "Ivan"} });
    assert(query_builder.BuildQuery() == "SELECT name, phone FROM teacher WHERE id=16 AND name=Ivan;");
    std::cout << std::endl;

    // Task 3
    std::cout << "Task 3" << std::endl;
    AdvancedSqlSelectQueryBuilder adv_query_builder;
    adv_query_builder.AddColumns({ "name", "phone" });
    adv_query_builder.AddFrom("students");
    adv_query_builder.AddWhere({ {"id", "42"} }, ">"); 
    assert(adv_query_builder.BuildQuery() == "SELECT name, phone FROM students WHERE id>42;");

    return 0;
}
