

/* 

desisti po, é isso

*/
#include <iostream>
using namespace std;

typedef struct _base{

    char base='\0';
    _base *prev=0,*prox=0;
}BASE;


int tamstr(char *str);


int chec_subseq(char *seq1, char *seq2,char *resposta);
int checa_tras(char* seq1, char *seq2,int limite) //retorna 0 se eh subseq de tras pra frente ou o indice p inserir
{
    int i,j,ind=0;
    cout << "\nChecando #1 se "; for(i=0;i<=limite;i++) cout <<seq2[i];
    cout << " eh subseq de " << seq1 << '\n';

    for(i=tamstr(seq1)-1,j=limite; i>=0 && j>=0 ;i--) //checa de tras pra frente
    {
        if(seq1[i]==seq2[j])
        {
            j--;
            ind = i;
        }
    }
    if(j<0) 
        return -1;//se checou tdo e é subseq
    if(j==0 || (limite==0 && j==0)) 
        return ind; //se só falta inserir 1 (ou eh so uma letra e n tem ela), retorna o indice
    else
        return -10; 
}

int checa_frente(char* seq1, char *seq2,int limite) //retorna 0 se eh subseq ou o indice p inserir
{
    int i,j,ind=0;
    

    cout << "\nChecando #2 se "; for(i=0;i<=limite;i++) cout <<seq2[i];
    cout << " eh subseq de " << seq1 << '\n';


     for(i=0,j=0;i<tamstr(seq1) && j<=limite;i++)
    {
        if(seq1[i]==seq2[j])
        {
            j++;
            ind = i;
        }
    }
    if(j>limite) //se eh subseq
        return -1;
    if(j==limite)
        return ind+1;
    else 
        return -10;
}


int tamstr(char *str)
{
    int i=0;
    while(str[i]!='\0') i++;
    return i;
}
void insere(char c,int pos, char *str)
{
    cout << "\n\tDebug ##\n" << "\tInserindo " << c <<
    " na posicao " << pos << " na string:\n\t" << str <<'\n';

    int i;
    for(i=tamstr(str);i>=pos;i--)
    {
        str[i+1]=str[i];
    }
    str[pos]=c;

}

int main()
{
    int n_testes=0,i,ind;

    
    char seq1[101],seq2[101], result[4096][201],*maior,*menor;

   

    while(cin >> seq1 && seq1[0]!='#')
    {
        cin >> seq2;
        n_testes++;   
        
        if(chec_subseq(seq1,seq2,result[n_testes-1])>=0)
            continue;

        tamstr(seq1)>tamstr(seq2)? (maior = seq1) && (menor = seq2)  : ( maior = seq2) && (menor = seq1);
        
        for(i=0;i<201;i++)
            result[n_testes-1][i]=0;
        for(i=0;i<tamstr(maior);i++)
            result[n_testes-1][i]=maior[i];

        for(i=0;i<tamstr(menor);i++)
        {
            switch(ind=checa_tras(result[n_testes-1],menor,i)) //ve se precisa botar o primeiro
            {
            case -1:
                continue;
            case -10:
                break;
            
            default:
                insere(menor[0],ind,result[n_testes-1]);
                continue;
            }
            switch(ind=checa_frente(result[n_testes-1],menor,i)) //ve se precisa botar o ultimo
            {
            case -1:
                continue;
            case -10:
                break;
            default:
                insere(menor[i],ind,result[n_testes-1]);
            }
            
        }
        
    
    }
    for(i=0;i<n_testes;i++) //imprime respostas
    {
        cout << "Teste " << i+1 << "\n" << result[i] << "\n\n";
    }
    return 0;
}


int chec_subseq(char *seq1, char *seq2,char *resposta)  //checa se um eh subseq do outro ou igual
{
    int i,tam1, tam2,result,j;
    result=-1;

    tam1 = tamstr(seq1);
    
    tam2 = tamstr(seq2);

    // cout << "Debug checa_sub\ntam1 = " << tam1 << "\t tam 2 = "
    //     << tam2 << "\n";

    if(tam1==tam2){     //checando se sao iguais
        for(i=0;i<tam1;i++)
        {
            if (seq1[i] != seq2[i])
                break;
        }
        if(i==tam1)
            result = 0;     // sao iguais
    }

    if(result<0){           //checar se um é subseq do outro

        if(tam1>tam2)
        {
            //checar se seq2 ta na seq1
            for(j=0,i=0;i<tam1 && j<tam2;i++)
            {
                if(seq1[i]==seq2[j])
                    j++;
                
            }
            if(!(j<tam2))
                result = 1;
        }
        else
        {
            //checar se seq1 ta na seq2
            for(j=0,i=0;i<tam2 && j<tam1;i++)
            {
                if(seq2[i]==seq1[j])
                    j++;
                
            }
            if(!(j<tam1))
                result = 2;
        }
    }
  
    switch(result)
    {
    case -1:
        return result;

    case 0:
        for(i=0;i<tam1;i++)
            resposta[i] = seq1[i];
        return result;
    
    case 1:
        for(i=0;i<tam1;i++)
            resposta[i] = seq1[i];
        return result;

    case 2:
        for(i=0;i<tam2;i++)
            resposta[i] = seq2[i];
        return result;

    }
    return result;
}