#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <gtk/gtk.h>
#include <gmodule.h>

FILE *pScoreDB = NULL;
GSList *listScore = NULL, *iterator = NULL; 
/*
MACROS
*/
#define LIST_DATA(str, field) (((str *)iterator->data)->field)

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

void scoreDB_open(); //en cours
int scoreDB_close(); //en cours
int scoreDB_add();
void scoreDB_remove();
ScoreDB* scoreDB_read(); //en cours
GSList* scoreDB_sort(); //en cours
void scoreDB_write(ScoreDB*); //en cours
int listScoreSort(gconstpointer, gconstpointer); //en cours
#endif // _MAIN_H
