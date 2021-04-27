// Wzorcowka Pawla Parysa z bledem
#include <cstdio>
#include <cstdlib>

#define REP(a,n) for (int a=0; a<(n); ++a)

using namespace std;

//////////////////////////////////////

#define SIZE (2*50000)

int dol[SIZE]; // cz�� stosu poni�ej bie��cej pozycji
int iledol; // rozmiar dolnej cz�ci stosu

int gora[SIZE]; // cz�� stosu powy�ej bie��cej pozycji
int goraod, gorakoniec; // gorna cz�� stosu znajduje si� w tablicy gora na
                        // pozycjach od goraod do gorakoniec-1

int jest[SIZE]; // czy w dolnej cz�ci stosu wyst�puje dana liczba
int N; // ile jest liczb

int wynik[1000000]; // spamietane ruchy
int ilew = 0; // ile jest inwersji (ile potrzeba ruch�w)

void licz()
{
  iledol = goraod = 0;
  gorakoniec = 2*N;
  while (goraod!=gorakoniec)
  {
    int A = gora[goraod++];
    if (jest[A])
    {
      int B = dol[--iledol];
      jest[B] = 0;
      wynik[ilew++] = iledol;
      if (rand() % 100 == 0) wynik[ilew - 1]++;
      if (B==gora[goraod]) // istnieje, bo B ma gdzies u gory pare
        ++goraod;
      else
        gora[--goraod] = B;
      gora[--goraod] = A;
      while (iledol && dol[iledol-1]==gora[goraod])
      // gora[goraod] istnieje, bo kazdy z dolu ma pare u gory
        --iledol, ++goraod;
    }
    else
    {
      jest[A] = 1;
      dol[iledol++] = A;
    }
  }
}

int main()
{
  scanf("%d", &N);
  int seed = 0;
  REP(a, 2*N)
  {
    scanf("%d", &gora[a]);
    --gora[a]; // u nas liczby b�d� od 0 do N-1
    seed = seed * 3 + gora[a];
  }
    srand(seed);
  licz();
  printf("%d\n", ilew);
  REP(a, ilew)
    printf("%d\n", wynik[a]+1); // +1 bo liczymy od 0
}
