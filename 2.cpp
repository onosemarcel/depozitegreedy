#include <iostream>
#include <fstream>
using namespace std;

ifstream f("input_1.dat");
ofstream o("output_1.dat");

int n;
int C[100];
int M[100][2];

void read(){

    f>>n;
    for(int i = 1; i <= n; i++)
        f>>C[i];
}

int suma(int st, int sf){

    int s = 0;

    for(int j = st; j <= sf; j++)
        s=s+C[j];
    return s;
}

int rest(int index){

    return M[index][0] % n;
}

void calcul_resturi(){

    for(int i = 1; i <= n; i++){

        M[i][0] = suma(1,i);
        M[i][1] = rest(i);
    }
}

int main()
{
    read();
    calcul_resturi();

    for(int i = 1; i <= n; i++)
        if(M[i][1] == 0){
            for(int j = 1; j <= i; j++) o<<j<<" ";
            return 0;
        }

    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if(M[i][1] == M[j][1]){
                for(int k = i + 1; k <= j; k++) o<<k<<" ";
                return 0;
            }

    return 0;
}
