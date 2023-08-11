#include <iostream>
#include <cmath>
using namespace std;

class Matrix
{
public:
    float **value;
    int rows,col;

    Matrix(int l, int c, int modo)     //se quiser perguntar a matriz tem que enviar l=0 e c=0
    {   
        int i,j;

        if(!l && !c) //pergunta n de linha e coluna
        {   
           cout << "\nSelecione o numero de linhas x colunas, separados por espaco.\n";
           cin >> rows >> col;
        }
        else
        {
            rows = l;
            col = c;
        }

        value = (float**) calloc(rows,sizeof(float*)); //cria matriz em si
        for(i=0;i<col;i++)
        {
            value[i] = (float*) calloc(col,sizeof(float));
        }

        if(modo==1) //preenche valores, se requisitado
        {
            for(i=0;i<rows;i++)
            {
                for(j=0;j<col;j++)
                    cin >> value[i][j];
            }
        }
        
    }

    void printa()
    {
        int i,j;
        printf("\n\tMatriz %d X %d\n\n",rows,col);
        for(i=0;i<rows;i++)
        {
            for(j=0;j<col;j++)
            {
                cout << " " <<value[i][j]<<' ';
            }
            cout << "\n";
        }
    }
    
    void switch_row(int r1,int r2) //troca as duas linhas de lugar
    {
        float temp;
        int i;

        for(i=0;i<col;i++)
        {
            temp = value[r1][i];
            value[r1][i] = value[r2][i];
            value[r2][i] = temp;
        }
    }

    void mult_row_const(int r,float c) //multiplica linha r pela constante c
    {
        int i;
        for(i=0;i<col;i++)
        {
            value[r][i]*=c;
        }
    }

    void add_rows(int r1,int r2, int r_final) //adiciona r1 a r2 e coloca em r_final
    {
        int i;

        for(i=0;i<col;i++)
        {
            value[r_final][i] = value[r1][i] + value[r2][i];
        }
    }

    Matrix* mat_mult(Matrix m2)
    {   
        int i,j,k;


        Matrix *result = new Matrix(rows,m2.col,0);

        if(col!=m2.rows)
        {
            cout << "\n\tDimensoes inapropriadas para a multiplicacao, vai dar merda!\n";
            printf("\tMatriz 1: %d X %d\nMatriz 2: %d X %d\n",rows,col,m2.rows,m2.col);
            delete(result);
            return NULL;
        }

        for(i=0;i<rows;i++)
        {   
            for(j=0;j<m2.col;j++)
            {
                result->value[i][j]=0;
                for(k=0;k<col;k++)
                {
                    result->value[i][j]+= value[i][k]*m2.value[k][j];
                }
            }
        }
        return result;




    }
    void gaussian_elimination()
    {
        int i,j,k,m;
        float scalar,abs;
        
        for(i=0,j=0;i<rows && j<col-1;i++) 
        {
            while(value[i][j]==0) //pega linha cujo valor de [i][j] nao seja 0
            {
                for(k=i;k<rows;k++)
                {
                    if(value[k][j]!=0)
                    {
                        switch_row(i,k);
                        break;
                    }            
                }
                if(k==rows)
                {
                    j++;
                }
            }
            if(!(j<col-1))
                break;
            
            for(k=0;k<rows;k++) //itera outras linhas alem da i, para zerar valores da coluna j
            {
                if(k!=i)
                {
                    scalar = value[k][j] / value[i][j];
                    // cout << "\n\t scalar = " << value[k][j] << " / " << value[i][j];
                    for(m=0;m<col;m++)
                    {
                        // cout << "\n\texpressao =\t " << value[k][m] << " -= " << value[i][m] << " * " << scalar
                        // << "\t ou " << value[k][m] << " - " << value[i][m] * scalar;
                        value[k][m] -= value[i][m] * scalar;

                        value[k][m] > 0 ? abs=value[k][m] : abs=-value[k][m]; //ajustes de precisao kkk kvtnc
                        abs<0.00001? value[k][m] = 0 : 0;
                    }
                }
            }
            abs=value[i][j];
            for(k=0;k<col;k++)
            {
                value[i][k] = value[i][k] / abs;
            }
            // cout <<"\n  \tlinha feita\n";
            // this->printa();
        }
    }


};

int main()
{
    int opt;

    printf("\n\t\t[MENU]\n\n"
            "[1] Eliminacao Gaussiana\n"
            "[2] Multiplicar duas Matrizes\n");
    cin >> opt;

    switch(opt)
    {
    case 1:
    {
        printf("\n\t[ELIMINACAO GAUSSIANA]\n");
      
        Matrix* matriz = new Matrix(0,0,1);
        cout << "\n\tMatriz lida:\n";
        matriz->printa();
        matriz->gaussian_elimination();
        cout << "\n\tMatriz reduzida:";
        matriz->printa();
        delete(matriz);
        break;
    }
    case 2:
        cout << "\n\tPrimeira Matriz\n";
        Matrix *m1 = new Matrix(0,0,1);
        
        cout << "\n\tSegunda Matriz\n";
        Matrix *m2 = new Matrix(0,0,1);

        Matrix *result = m1->mat_mult(*m2);
        result->printa();
        delete(m1); delete(m2); delete(result);
        break;
        
    }
    return 0;
}