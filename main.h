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
#define LIMIT_LIST 10
typedef struct s_ScoreDB
{
    /* data */
    int id;
    char *name;
    int value;          /* somme des scores gagnant */
    int victory_number; /* nombre de victoire */
    int value_avg;      /* moyenne des points de la victoire */
    int party_number;   /* nombre de partie */

} ScoreDB;

typedef ScoreDB *ptr_ScoreDB;
typedef ptr_ScoreDB ptabScore[LIMIT_LIST];

                      
ptabScore *scoreDB_get(GSList *);                //retourne un pointeur sur tableau qui contient les LIMIT_LIST pointeurs sur les structures score
void scoreDB_set(const char*, int);

#endif                                           // _MAIN_H
