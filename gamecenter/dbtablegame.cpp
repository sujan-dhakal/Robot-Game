/*********************************************************************

Copyright (C) 2015 Jeffrey O. Pfaffmann

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*********************************************************************/

#include "dbtablegame.h"

DBTableGame::DBTableGame()
{

}

// Constructor for identying the dbtool and table name.
DBTableGame::DBTableGame(DBTool *db, string name) : DBTable (db, name)
{

    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
}

DBTableGame::DBTableGame(DBTableGame &obj) : DBTable (obj)
{

    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
}

void DBTableGame::operator=(DBTableGame &obj) {
    // Store table name and reference to db.
    curr_db     = obj.curr_db;
    table_name  = obj.table_name;

    // Register the different sql calls for the
    // parent class.
    store_exist_sql();
    store_create_sql();
    store_drop_sql();
    store_size_sql();

    sql_add_row = "";

    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
}

DBTableGame::~DBTableGame() {

}

void DBTableGame::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}

void DBTableGame::store_create_sql() {

    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id INT PRIMARY KEY NOT NULL, ";
    sql_create += "  player INT,";
    sql_create += "  name   TEXT NOT NULL, ";
    sql_create += "  score  INT NOT NULL";
    sql_create += " );";

}



bool DBTableGame::add_row(int id, int player, string name, int score) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, player, name, score ) ";
    sql_add_row += "VALUES (";

    sprintf (tempval, "%d", id);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sprintf (tempval, "%d", player);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += string(name);
    sql_add_row += "\", ";

    sprintf (tempval, "%d", score);
    sql_add_row += tempval;

    sql_add_row += " );";


    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

int cb_add_row(void  *data, int    argc, char **argv, char **azColName) {
    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }
    return 0;

}

int cb_select_all(void  *data,
                  int    argc,
                  char **argv,
                  char **azColName)
{


    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    DBTableGame *obj = (DBTableGame *) data;
    if (obj->pgh !=nullptr){
        obj->pgh->construct_game(argc, argv, azColName);
    }

    return 0;
}

bool DBTableGame::select_all() {

    int   retCode = 0;
    char *zErrMsg = 0;

    //sql_select_all  = "PRAGMA table_info(" + table_name + ");";
    sql_select_all = "SELECT * FROM ";
    sql_select_all += table_name;
    sql_select_all += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all.c_str(),
                           cb_select_all,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}
