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

#ifndef DBTABLEGAME_H
#define DBTABLEGAME_H


#include <iostream>
#include <string>
#include <sqlite3.h>

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

#include "dbtool.h"
#include "dbtable.h"
#include "playergamehistory.h"



class PlayerGameHistory;

class DBTableGame : public DBTable
{
public:
    DBTableGame();
    DBTableGame(DBTool *db, string name);
    DBTableGame(DBTableGame &obj);
    void operator=(DBTableGame &obj);
    ~DBTableGame();

    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_add_row_sql();

    bool add_row(int id, int player, string name, int score);

    bool select_all();

    PlayerGameHistory *pgh;
    void set_pgh(PlayerGameHistory *p){pgh=p;}

protected:
    string sql_select_all;
    string sql_update;
};

// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_add_row(void  *data,
               int    argc,
               char **argv,
               char **azColName);


// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_select_all(void  *data,
                  int    argc,
                  char **argv,
                  char **azColName);

#endif // DBTABLEGAME_H
