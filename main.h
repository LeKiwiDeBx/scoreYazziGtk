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
    gint id;
    gchar *name; 
    gint value; /* somme des scores gagnant */
    gint victory_number; /* nombre de victoire */
    gint value_avg; /* moyenne des points de la victoire */
    gint party_number; /* nombre de partie */

} ScoreDB, *ptr_ScoreDB; 

int scoreDB_open();
void scoreDB_close();
int scoreDB_add();
void scoreDB_remove();
ptr_ScoreDB scoreDB_read(); //en cours
void scoreDB_sort();
void scoreDB_write(); //en cours

#endif // _MAIN_H
