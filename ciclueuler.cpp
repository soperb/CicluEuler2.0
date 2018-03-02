#include<iostream>
#include<fstream>
using namespace std;
int G[100][100];
int n;
int C1[10000];
int nc1;
int C2[10000];
int nc2;
int V[100];
int grades[100];


int read_data()
{
ifstream f;
f.open("input.txt", ios::in);
f>>n;
for(int i=0;i<n;i++)
   {for(int j=1;j<=n;j++)
    f>>G[i][j];
   }
f.close();
}

int insertion(int C1[],int *nc1,int C2[],int nc2,int k)
{
    for(int i=k; i<(*nc1);i++)
        C1[i+nc2]=C1[i];
    for(int i=0;i<nc2;i++)
        C1[i+k]=C2[i];
    (*nc1)+=nc2;
}



int init_data()
{
// calculeaza in grades[100]  gradele tuturor varfurilor

}

int explore(int G[100][100],int n,int node,int solution[100])
{
// parcurge DFS graful G cu n noduri  incepand cu nod "node"
// lista nodurilor parcurse pana la inchiderea ciclului urmand a
// fi depusa in 'solution'
// att : decrementez gradele nodurilor prin care trec
}

int euler()
{
// strategie ma grabesc , iterativ , dfs iterativ
// caut prim nod nevizitat ( pentru a porni explorare din el )
int gasit=1;
while  (gasit==1)
  {
        gasit=0;
        for(int i=1;i<=n;i++)
        {
            if ( V[i]==0 ) {   int counter;
                                    counter=explore(G,n,i,C1);
                                    for (int j=1;j<=counter;j++)
                                       {
                                            if (grades[C1[j]]>0) {
                                                int numbers;
                                                numbers=explore(G,n,j,C2);
                                                insertion(C1,&counter,C2,numbers,j);
                                                                          }
                                       }
                                }
        }
  }
}

int print_data()
{
// afiseaza C1
}

int main()
{
read_data();
init_data();
euler();
print_data();
}

/*

                 5
            *
               |   \
  1*----*2-----* 6
   |     |
   |     |
 4 *----*3

C1 : 1 2 3 4 1
C2 : 2 5 6 2
----
in 2 din C1 inserez C2 => ciclul eulerian cautat

*/
