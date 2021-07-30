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
ScoreDB *pScore_1, *pScore_2, *pScore_3;

ScoreDB score_1 = {1, "jean", 250, 2, 248, 4},
        score_2 = {2, "jacques", 270, 2, 248, 4},
        score_3 = {3, "françois", 260, 2, 248, 4};

int main(int argc, char const *argv[])
{
    /* code */
     pScore_1 = (ScoreDB *)malloc(sizeof(ScoreDB)*1 );
     pScore_2 = (ScoreDB *)malloc(sizeof(ScoreDB)*1 );
     pScore_3 = (ScoreDB *)malloc(sizeof(ScoreDB)*1 );

if(pScore_1 == NULL){
    exit(EXIT_FAILURE);
}
    pScore_1 = &score_1 ;
    pScore_2 = &score_2 ;
    pScore_3 = &score_3 ;
    printf("Test structure\n");
    scoreDB_open();
    printf("id: %d name: %s\n",pScore_1->id, pScore_1->name);
    scoreDB_write(pScore_1);
    scoreDB_write(pScore_2);
    scoreDB_write(pScore_3);
    scoreDB_read(pScore_1,1);
    return 0;
}

void scoreDB_open(){
  pScoreDB = fopen("scoreDB", "w+");
}

void scoreDB_write(ScoreDB* ps){
    fwrite(ps, sizeof(ScoreDB),1,pScoreDB);
    listScore = g_slist_append(listScore, ps);
}

int listScoreSort(gconstpointer sc1, gconstpointer sc2){
    if(((ScoreDB *)sc1)->value > ((ScoreDB *)sc2)->value) return -1;
    if(((ScoreDB *)sc1)->value < ((ScoreDB *)sc2)->value) return 1;
    return 0;

}

ScoreDB* scoreDB_read(ScoreDB* ps, int ind){
    fseek(pScoreDB, sizeof(ScoreDB)*1, SEEK_SET);
    fread(ps, sizeof(ScoreDB), ind-1, pScoreDB);
    printf("from file id: %d name: %s\n",ps->id, ps->name);
    for(iterator = listScore; iterator; iterator = iterator->next){
         printf("from iterator id: %d name: %s\n" , LIST_DATA(ScoreDB,id) ,  LIST_DATA(ScoreDB,name));
    }
    listScore = g_slist_sort(listScore, listScoreSort);
    for(iterator = listScore; iterator; iterator = iterator->next){
     printf("from iterator id: %d name: %s\n", ((ScoreDB *)iterator->data)->id, ((ScoreDB *)iterator->data)->name);
}
    printf("from list id: %d name: %s\n", ((ScoreDB *)listScore->data)->id, ((ScoreDB *)listScore->data)->name);

    return ps;
}

