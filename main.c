#include<sqlite3.h>
#include<stdio.h>
#include<stdlib.h>
#include"db/connection.h"
#include"modules/utils.h"



int main(){
    int rc;
    char *ERR;
    int is_exit = 1;
    char command[200];
    int gui_state = MAIN_SCREEN;
    int screen_update_require = 1;
    // Connect to db
    sqlite3 *db = db_connect("db/hello.sqlite3");

    while (is_exit){
        if(screen_update_require){
            draw_screen(gui_state);
            screen_update_require = 0;
        }
        //draw_screen(MAIN_SCREEN);
        fgets(command, 200, stdin);
        printf("%s\n", command);
    } 

    sqlite3_close(db);
    return 0;
}