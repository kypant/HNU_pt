
#include "drop_table_executor.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "sql/stmt/stmt.h"
#include "sql/stmt/drop_table_stmt.h"
#include "common/log/log.h"
#include "session/session.h"
#include "storage/db/db.h"


RC DropTableExecutor::execute(SQLStageEvent* sql_event) {
    RC rc = RC::SUCCESS;
    auto* session = sql_event->session_event()->session();
    Stmt* stmt = sql_event->stmt();
    
    ASSERT(stmt->type() == StmtType::DROP_TABLE, 
        "drop table executor can not run this command: %d", static_cast<int>(stmt->type()));
    
    DropTableStmt* drop_table_stmt = dynamic_cast<DropTableStmt *>(stmt);
    
    rc = session->get_current_db()->drop_table(drop_table_stmt->table_name().c_str());
    return rc;
}