/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-13
 * 
 * @copyright Copyright (c) 2021
 *
 * 
 => compilation et link :: [°> Couak!

 gcc -Wall -g main.c -o score `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`
 
 */

#include "main.h"

///////////////// jeu de test ////////////////////////
ScoreDB* pScore_1;
ScoreDB score_1 = {1, "jean", 250, 2, 248,4};

int main(int argc, char const *argv[])
{
    /* code */
     pScore_1 = (ScoreDB *)malloc(sizeof(ScoreDB)*1 );

if(pScore_1 == NULL){
    exit(EXIT_FAILURE);
}
    pScore_1 = &score_1 ;
    printf("Test structure\n");
    scoreDB_open();
    printf("id: %d name: %s\n",pScore_1->id, pScore_1->name);
    scoreDB_write(pScore_1);
    scoreDB_read(pScore_1,1);
    return 0;
}

void scoreDB_open(){
  pScoreDB = fopen("scoreDB", "w+");
}

void scoreDB_write(ScoreDB* ps){
    fwrite(ps, sizeof(ScoreDB),1,pScoreDB);
}

ScoreDB* scoreDB_read(ScoreDB* ps, int ind){
    fseek(pScoreDB, sizeof(ScoreDB)*1, SEEK_SET);
    fread(ps, sizeof(ScoreDB), ind-1, pScoreDB);
    printf("from file id: %d name: %s\n",ps->id, ps->name);
    return ps;
}

