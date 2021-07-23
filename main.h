#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <gmodule.h>
/*
code
*/
FILE *pScoreDB ;
GSList *listScore = NULL; 

typedef struct s_ScoreDB
{
    /* data */
    int id;
    char *name; 
    int value; /* somme des scores gagnant */
    int victory_number; /* nombre de victoire */
    int value_avg; /* moyenne des points de la victoire */
    int party_number; /* nombre de partie */

} ScoreDB;
ScoreDB *ptr_ScoreDB; 

void scoreDB_open();
void scoreDB_close();
int scoreDB_add();
void scoreDB_remove();
ScoreDB* scoreDB_read(); //en cours
void scoreDB_sort();
void scoreDB_write(ScoreDB*); //en cours

#endif // _MAIN_H
