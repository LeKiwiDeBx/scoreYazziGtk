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

///////////////// jeu de test jeu de vilain ///////////////////////////////////
ScoreDB *pScore_1, *pScore_2, *pScore_3;

ScoreDB score_1 = {1, "jean", 200, 2, 248, 4},
        score_2 = {2, "jacques", 290, 2, 248, 4},
        score_3 = {3, "françois", 280, 2, 248, 4};

//////////////////////////  [°> Couak! ////////////////////////////////////////
static void _scoreDB_open(); //en cours
static int _scoreDB_close(); //en cours
static int _scoreDB_add();
static void _scoreDB_remove();
static GSList * _scoreDB_trim(GSList*, int);              // limitera à LIMIT_LIST la liste score
static ScoreDB * _scoreDB_read();                         //en cours
static GSList * _scoreDB_sort();    
static void _scoreDB_write(ScoreDB *);                   //en cours
static int _listScoreSort(gconstpointer, gconstpointer); //en cours
/**
 * @brief function principal pour test 'appeler à disparaître'
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
  pScore_1 = (ScoreDB *)malloc(sizeof(ScoreDB) * 1);
  pScore_2 = (ScoreDB *)malloc(sizeof(ScoreDB) * 1);
  pScore_3 = (ScoreDB *)malloc(sizeof(ScoreDB) * 1);

  if (pScore_1 == NULL)
  {
    exit(EXIT_FAILURE);
  }
  pScore_1 = &score_1;
  pScore_2 = &score_2;
  pScore_3 = &score_3;
  printf("Test structure\n");
  _scoreDB_open("ScoreDB");
  //printf("id: %d name: %s\n",pScore_1->id, pScore_1->name);
  _scoreDB_write(pScore_1);
  _scoreDB_write(pScore_2);
  _scoreDB_write(pScore_3);
  _scoreDB_read(pScore_1, 1);
  _scoreDB_close(pScoreDB);
  
  return 0;
}

/**
 * @brief ouvre le fichier DB sur disque
 * 
 * @param nameFile 
 */

static void _scoreDB_open(char *nameFile)
{
  pScoreDB = fopen(nameFile, "w+");
  if (pScoreDB == NULL)
  {
    fprintf(stderr, "Error with file name %s\n", nameFile);
    exit(EXIT_FAILURE);
  }
}
/**
 * @brief ferme le fichier DB sur disque
 * 
 * @param nameFile 
 */
static int _scoreDB_close(char *nameFile)
{
  int retCode = fclose(pScoreDB);
  if (retCode == EOF)
  {
    fprintf(stderr, "Erreur durant la fermeture du fichier errno: %d\n", errno);
    exit(EXIT_FAILURE);
  }
  return retCode;
}

/**
 * @brief écrit dans la liste les datas du fichier DB
 * 
 * @param ps 
 */
static void _scoreDB_write(ScoreDB *ps)
{
  listScore = g_slist_append(listScore, ps);
  fwrite(ps, sizeof(ScoreDB), 1, pScoreDB);
}

/**
 * @brief fonction callback de tri de la liste (ordre croissant)
 * 
 * @param sc1 
 * @param sc2 
 * @return int 
 */
static int _listScoreSort(gconstpointer sc1, gconstpointer sc2)
{
  if (((ScoreDB *)sc1)->value > ((ScoreDB *)sc2)->value)
    return -1;
  else if (((ScoreDB *)sc1)->value < ((ScoreDB *)sc2)->value)
    return 1;
  else
    return 0;
}

/**
 * @brief lecture d'une structure du fichier sur disque DB
 *
 * @param ps
 * @param ind
 * @return ScoreDB*
 */
static ScoreDB * _scoreDB_read(ScoreDB *ps, int ind)
{

  ScoreDB *scoreTemp = (ScoreDB *)malloc(sizeof(ScoreDB) * 1);
  fseek(pScoreDB, 0, SEEK_SET); //sizeof(ScoreDB)*1
  while (fread(scoreTemp, sizeof(ScoreDB), 1, pScoreDB))
    printf("from file id: %d name: %s\n", scoreTemp->id, scoreTemp->name);

  for (iterator = listScore; iterator; iterator = iterator->next)
  {
    printf("from iterator id: %d name: %s score: %d\n", LIST_DATA(ScoreDB, id), LIST_DATA(ScoreDB, name), LIST_DATA(ScoreDB, value));
  }

  //printf("from list id: %d name: %s\n", ((ScoreDB *)listScore->data)->id, ((ScoreDB *)listScore->data)->name);
  return ps;
}

/**
 * @brief tri la liste des scores à l'aide du callback listScoreSort (ordre décroissant)
 * 
 * @param ps 
 * @return GSList* 
 */
static GSList * _scoreDB_sort(ScoreDB *ps)
{
  listScore = g_slist_sort(listScore, _listScoreSort);
  printf("\nNombre element de la liste %d\n", g_slist_length(listScore));
  for (iterator = listScore; iterator; iterator = iterator->next)
  {
    printf("from iterator id: %d name: %s\n", ((ScoreDB *)iterator->data)->id, ((ScoreDB *)iterator->data)->name);
  }
  return listScore;
}

/**
 * @brief retourne un pointeur sur tableau contenant les pointeurs de la GSlist
 * 
 * @param gsl la GSlist
 * @return ptabScore* 
 */
static ptabScore * _scoreDB_get(GSList *gsl)
{
  static ptabScore *p = NULL;
  /* code */
  return p;
}

/**
 * @brief coupe la liste au n ième élement
 * 
 * @param gsl 
 * @param ind 
 * @return GSList* 
 */
static GSList * _scoreDB_trim(GSList *gsl, int n){
  GSlist *l = NULL ;
  /*
  code
  */
  return l;
}