#include <stdio.h>
#include <stdlib.h>
#define COST_INGREDIENT 2      // COST PER INGREDIENT
#define MAX_NUM_INGREDIENTS 10 // NUMARUL MAXIM DE INGREDIENTE
#define MAX_NUM_COMANDA 5      // NUMARUL MAXIM DE ITEME IN COS

void render_choices();
void render_menu();
void render_custom_shaworma_menu();
void add_shaworma_to_basket();
void close_order();

// ARRAY CU INGREDIENTELE
const char *INGREDIENTE[13] = {
    "porc",                // 0
    "pui",                 // 1
    "vita",                // 2
    "berbecut",            // 3
    "maioneza simpla",     // 4
    "maioneza cu usturoi", // 5
    "ketchup dulce",       // 6
    "ketchup picant",      // 7
    "varza alba",          // 8
    "varza rosie",         // 9
    "ceapa",               // 10
    "castraveti simpli",   // 11
    "castraveti murati"    // 12
};

// STRUCTURA TIP SHAWORMA CARE TINE PRETUL SI INGREDIENTELE FIECAREI SHAWORMA
struct Shaworma
{
  int price;                            // PRETUL SHAWORMEI
  int ing_size;                         // NUMARUL DE INGREDIENTE AL SHAWORMEI
  int ingredients[MAX_NUM_INGREDIENTS]; // INDICELE DIN ARRAYUL DE INGREDIENTE AL SHAWORMEI
};

// INGREDIENTELE PENTRU SHAWORMELE "PREFACUTE"
const int ING_SHAWORMA_CLASICA[MAX_NUM_INGREDIENTS] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
const int ING_COUNT_SHAWORMA_CLASICA = 10;
const int ING_SHAWORMA_DOMNISOARE[MAX_NUM_INGREDIENTS] = {1, 4, 6, 8, 9, 11, 12};
const int ING_COUNT_SHAWORMA_DOMNISOARE = 7;

// VARIABILA IN CARE TINEM NUMARUL INGREDIENTELOR DIN SHAWORMA
int ingredient_no = 0;
// VARIABILA IN CARE TINEM MARIMEA COSULUI
int basket_length = 0;
// SHAWORMA TEMPORARA IN CARE TINEM FIECARE SHAWORMA PERSONALIZATA INAINTE SA O ADAUGAM IN COS
struct Shaworma temp_shaworma;
// SHAWORMA FARA NIMIC, CU CARE REINITIALIZAM SHAWORMA TEMPORARA DUPA CE O ADAUGAM IN COS
static const struct Shaworma empty_shaworma;
// COSUL DE CUMPARATURI
struct Shaworma basket[MAX_NUM_COMANDA];

int main()
{
  // MESAJ INTAMPINARE
  printf("Bine ati venit la Shaworma Boierului!\n");
  // PREZENTAM MENIUL PRINCIPAL
  render_choices();
  return 0;
}

void render_menu()
{
  printf("\n=== MENIU ===\n");
  printf("[0] Nimic, doar ma uitam\n");
  printf("[1] Clasica (berbecut, cu de toate)\n");
  printf("[2] De domnisoare (pui, fara ceapa, maioneza simpla)\n");
  printf("[3] Cum vrei tu\n");
  // DACA AVEM CEVA IN COS, PRINTAM OPTIUNEA DE A CERE NOTA
  if (basket_length > 0)
  {
    printf("[4] Atat sa fie, nota va rog\n");
  }
}

void add_shaworma_to_basket()
{
  // CALCULAM PRETUL SHAWORMEI IN FUNCTIE DE INGREDIENTE SI COSTUL PER INGREDIENT
  temp_shaworma.price = ingredient_no * COST_INGREDIENT;
  // ADAUGAM NR DE INGREDIENTE
  temp_shaworma.ing_size = ingredient_no;
  // ADAUGAM SHAWORMA IN COS
  basket[basket_length] = temp_shaworma;
  // MARIMEA COSULUI CRESTE CU 1
  basket_length++;
  // REINITIALIZAM SHAWORMA CU UNA GOALA
  temp_shaworma = empty_shaworma;
  // REINITIALIZAM NUMARUL INGREDIENTELOR
  ingredient_no = 0;

  if (basket_length >= MAX_NUM_COMANDA)
  {
    // DACA AVEM DEJA NUMARUL MAXIM DE SHAWORME IN COS, PRINTAM NOTA DE PLATA
    printf("\nHai ca nu facem comanda pentru tot biroul, da?\n");
    close_order();
  }
  else
  {
    // ALTFEL, PRINTAM MENIUL
    render_choices();
  }
}

void close_order()
{
  // INITIALIZAM TOTALUL CU 0
  int total = 0;
  // TRAVERSAM COSUL
  for (int i = 0; i < basket_length; i++)
  {
    // ADAUGAM PRETUL SHAWORMELOR LA TOTAL
    total += basket[i].price;
    // TRAVERSAM INGREDIENTELE FIECAREI SHAWORMA
    printf("\nAvem una bucata cu: \n");
    for (int j = 0; j < basket[i].ing_size; j++)
    {
      // PRINTAM NUMELE INGREDIENTELOR
      printf("- %s \n", INGREDIENTE[basket[i].ingredients[j]]);
    }
    // PRINTAM PRETUL
    printf("\nPret: %d\n", basket[i].price);
  }
  printf("\n\n*** Avem %d shaworma la pretul de %d de lei, mergeti cu bonuletul la casa va rog *** \n\n", basket_length, total);
  printf("\nUrmatorul, va rog! Hai, ca lumea asteapta!\n\n");

  // REINITIALIZAM LUNGIMEA COSULUI
  basket_length = 0;
  // NU TREBUIE SA GOLIM COSUL, PRODUSELE SE VOR SCRIE DOAR IN ORDINE SI NOTA DE PLATA SE VA FACE IN FUNCTIE DE basket_length
}

void render_custom_shaworma_menu()
{
  char line[100];
  int answer;
  int sscanf_result;
  answer = -1;
  // CAT TIMP RASPUNSUL NU ESTE 13 - FINALIZAREA CONFIGURARII
  while (answer != 13)
  {
    printf("\n=== MENIU INGREDIENTE ===\n");
    // trecem prin arrayul ingrediente si printam fiecare optiune
    for (int i = 0; i < 13; i++)
    {
      printf("[%d] %s \n", i, INGREDIENTE[i]);
    }
    // daca utilizatorul a adaugat cel putin un ingredient, poate termina shaworma si o poate adauga in cos
    if (ingredient_no > 1)
    {
      printf("[13] Atat boss\n");
    }

    fgets(line, sizeof(line), stdin);
    sscanf_result = sscanf(line, "%d", &answer);
    // DACA RASPUNSUL NU ESTE UNUL VALID, PUNEM ANSWER CA INVALID PENTRU A INTRA IN RAMURA CORECTA DE SWITCH
    if ((sscanf_result == 0) | (sscanf_result == EOF))
    {
      printf("\nD-astea n-avem! Doar ce-i pe meniu, totusi...\n");
      answer = -1;
    }
    switch (answer)
    {
    case 13:
      add_shaworma_to_basket();
      break;
    default:
      // DACA MAI AVEM LOC IN SHAWORMA, PUNEM INGREDIENTUL IN SHAWORMA TEMPORARA SI MARIM NUMARUL ACTIV DE INGREDIENTE
      if (answer == -1)
      {
        break;
      }
      printf("\nPunem %s, avem %d ingrediente\n", INGREDIENTE[answer], ingredient_no + 1);
      // PUNEM INDICELE INGREDIENTULUI IN SHAWORMA TERMPORARA
      temp_shaworma.ingredients[ingredient_no] = answer;
      // MARIM NUMARUL DE INGREDIENTE
      ingredient_no++;
      // VERIFICAM DACA NUMARUL DE INGREDENTE MAXIM A FOST ATINS
      if (ingredient_no >= 10)
      {
        printf("Am pus maximul de %d ingrediente !\n", MAX_NUM_INGREDIENTS);
        // NUMARUL MAXIM DE INGREDIENTE A FOST ATINS, ADAUGAM SHAWORMA IN COS
        add_shaworma_to_basket();
      }
      break;
    }
  }
}

void render_choices()
{
  char line[100];
  int answer;
  int sscanf_result;
  answer = -1;
  // CAT TIMP RASPUNSUL ESTE DIFERIT DE "DOAR MA UITAM" SI "CONFIGURARE DE SHAWORMA"
  while (answer != 0 && answer != 3)
  {
    // PREZENTAM MENIUL PRINCIPAL
    render_menu();
    printf("\nCe sa fie, sefu?");
    fgets(line, sizeof(line), stdin);
    sscanf_result = sscanf(line, "%d", &answer);
    if ((sscanf_result == 0) | (sscanf_result == EOF))
    {
      printf("\n *** Doar ce-i pe meniu, va rog! ***\n");
      answer = -1;
    }
    switch (answer)
    {
    case 0:
      printf("\nHai ca tii coada, boss!\n");
      break;
    case 1:
      // CONFIGURAM SHAWORMA CLASICA
      ingredient_no = ING_COUNT_SHAWORMA_CLASICA;
      for (int i = 0; i < ingredient_no; i++)
      {
        temp_shaworma.ingredients[i] = ING_SHAWORMA_CLASICA[i];
      }
      printf("\nS-a pus o clasica.\n");
      add_shaworma_to_basket();
      break;
    case 2:
      // CONFIGURAM SHAWORMA DOMNISOARE
      ingredient_no = ING_COUNT_SHAWORMA_DOMNISOARE;
      for (int i = 0; i < ingredient_no; i++)
      {
        temp_shaworma.ingredients[i] = ING_SHAWORMA_DOMNISOARE[i];
      }
      printf("\nS-a pus una de domnisoare.\n");
      add_shaworma_to_basket();
      break;
    case 3:
      render_custom_shaworma_menu();
      break;
    case 4:
      // PRINTAM NOTA
      printf("\nAsta e nota, boss\n");
      answer = 4;
      close_order();
      break;
    default:
      break;
    }
  }
}
