#include "sql/stmt/drop_table_stmt.h"
#include "event/sql_debug.h"

RC DropTableStmt::create(Db* db, DropTableSqlNode& sql_node, Stmt*& stmt) {
    RC rc = RC::SUCCESS;
    stmt = new DropTableStmt(sql_node.relation_name);
    sql_debug("drop table statement: table name %s", sql_node.relation_name.c_str());

    return rc;
}