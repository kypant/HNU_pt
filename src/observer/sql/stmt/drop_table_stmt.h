#pragma once

#include "sql/stmt/stmt.h"

class Db;

class DropTableStmt : public Stmt {
public:
    DropTableStmt(const std::string& name): table_name_(name) {}

    virtual ~DropTableStmt() = default;

    StmtType type() const override {
        return StmtType::DROP_TABLE;
    }

    const std::string &table_name() { return table_name_; }

    static RC create(Db* db, DropTableSqlNode& sql_node, Stmt*& stmt);

private:
    std::string table_name_;
};