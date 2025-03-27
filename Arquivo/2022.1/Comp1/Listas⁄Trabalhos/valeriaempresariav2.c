#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOME_ARQ "condominios.bin"

typedef struct _PREDIO{
    int andares, ApartamentosPorAndar, nPredio;
    struct _PREDIO *pPredio;

}PREDIO;

typedef struct _APTO{
  int status;  /*0 para vazio, 1 para alugado*/
}APTO;

typedef struct _CONDOMINIO{

    int nCond;
    char rua[50];
    PREDIO *condPredios;
    struct _CONDOMINIO *pCond;
} CONDOMINIO;

int valida_int(void);
void consultarPredio(CONDOMINIO* predios,int id);
void criarPredios(PREDIO **pheadPredio);
void criarCondominio(CONDOMINIO **pheadCondominios);
void demolirPredio(PREDIO **pheadPredio, int id);
void demolirCondominio(CONDOMINIO **pheadCondominio, int id);

void consultarCondominio(CONDOMINIO *head,int n_cond)
{
  CONDOMINIO *mostrando=head;
  PREDIO *predios;
  int n_predios=0,existe,opcao=-1;
  while(mostrando->pCond!=NULL) /*checa o condominio a ser exibido*/
  {
    if(mostrando->nCond==n_cond)
    {
      break;
    }
    else
    {
      mostrando = mostrando->pCond;
    }
  }



  /* mostrando condominio e menu*/


  while(opcao!=0)
  { existe=0;
    n_predios=0;
    /*pegando  o numero de predios*/
    predios = mostrando->condPredios;
    if(predios==NULL)
    {
      puts("\t[Nao ha predios neste condominio.]\n");
    }
    else
    {
      n_predios++;
      while(predios->pPredio!=NULL)
      {
        n_predios++;
        predios = predios->pPredio;
      }
    }
    printf("\n\n[*~*~*~*~*~*~*~*~] CONDOMINIO VAL %d [*~*~*~*~*~*~*~]\n",n_cond);
    printf("\n\n\tCondominio da Val %d\n"
          "\tEndereco: %s\n"
          "\t%d predios/blocos existentes.\n\n",n_cond,mostrando->rua,n_predios);


    if(n_predios>0)
    {
      predios = mostrando->condPredios;
      while(predios!=NULL)
      {
        printf("Predio %d -   %d apartamentos  /  %d andares   "
        "/ %d apartamentos por andar\n",predios->nPredio,
        predios->ApartamentosPorAndar*predios->andares,
        predios->andares,predios->ApartamentosPorAndar); /*se certificar de que existe o numero do predio na struct*/
        predios = predios->pPredio;
      }
    }

    printf("\t\n\n[Selecione a operacao desejada]\n"
          "[1] Criar predio\n"
          "[2] Consultar predio\n"
          "[3] Demolir predio\n"
          "[0] Voltar ao menu anterior\n\n");
    opcao=valida_int();


    switch(opcao)
    {
      case 1:
        criarPredios(&(mostrando->condPredios)); /*verificar argumentos*/
        break;

      case 2:
        if(mostrando->condPredios==NULL)
        {
          puts("Crie pelo menos um predio!\n");
          break;
        }
        else
        {
          puts("Selecione o numero do predio:\n");
          opcao=valida_int();
        }
        predios = mostrando->condPredios;
        while(predios!=NULL) /* Checando opcao escolhida */
        {
          if(opcao==predios->nPredio)
          {
            existe=1;
            consultarPredio(mostrando,opcao);
            break;
          }
          else
          {
            predios = predios->pPredio;
          }
        }
        if(!existe) puts("\t\n[O predio escolhido nao existe.]\n");
        break;

      case 3:
      if(mostrando->condPredios==NULL)
      {
        puts("Crie pelo menos um predio!\n");
        break;
      }
      else
      {
        puts("Selecione o numero do predio:\n");
        opcao=valida_int();
      }
      predios = mostrando->condPredios;
      while(predios!=NULL) /* Checando opcao escolhida */
      {
        if(opcao==predios->nPredio)
        {
          existe=1;
          demolirPredio(&mostrando->condPredios,opcao);
          break;
        }
        else
        {
          predios = predios->pPredio;
        }
      }
      if(!existe) puts("\t\n[O predio escolhido nao existe.]\n");
      break;
    }
  }
 }


void consultarPredio(CONDOMINIO* predios,int id)       /*verificar argumentos*/
{
  /*carregar o predio certo, comparando id passado como argumento com os nPredio;*/

  PREDIO *predio_atual;

  predio_atual = predios->condPredios;

  while(predio_atual!=NULL)
  {
    if(id==predio_atual->nPredio) break;
    else
    {
      predio_atual=predio_atual->pPredio;
    }
  }
  if(predio_atual==NULL)
  {
    puts("Predio nao encontrado.\n");
  }
  else
  {
    printf("\t\n[Condominio Val %d | Predio %d ] \n\n"
    "Este predio possui %d unidades\n"
    "Com %d apartamentos por andar\n"
    "E %d andares\n",predios->nCond,predio_atual->nPredio,
    predio_atual->ApartamentosPorAndar*predio_atual->andares,
    predio_atual->ApartamentosPorAndar,predio_atual->andares);
  }
  /*nao sei oq botar mais aqui. haverá opcoes para apartamentos??? */
  /* Nao foi pedido, então acho q n */

}

int valida_int(void)
{
	int valido,lixo,valor;
	valido=scanf("%d",&valor);
        while(valido==0)
        {
            while((lixo=getchar()) != EOF && lixo!= '\n');
            puts("\nInsira um valor válido: ");
            valido=scanf("%d",&valor);
        }
	while((lixo=getchar()) != EOF && lixo!= '\n');
	return valor;
}
int mostrarMenu(char **menu)
{
  int i;
  for(i=0;menu[i]!=NULL;i++)
  {
    printf("%s",menu[i]);
  }
  puts("Selecione a operacao:");

  return valida_int();
}

CONDOMINIO* carregaDados()
{
  FILE* pa;
  int n_predios=0,n_condos=0,i,k;
  CONDOMINIO *p_head,*cond,*ultimo_cond;
  PREDIO *predio,*ultimo_predio;


  if((pa = fopen(NOME_ARQ,"r"))==NULL)
  {
    puts("\n[Arquivo de condominios nao existente! Criando arquivo de condominios...]\n");
    if((pa=fopen(NOME_ARQ,"wb+"))==NULL)
    {
      puts("Erro criando arquivo.");
      return NULL;
    }
    else{
      puts("Arquivo criado!");
      return NULL;
    }
  }

  fread(&n_condos,sizeof(int),1,pa);

  if(n_condos==0)
  {
    return NULL;
  }
  /*lendo a head e seus predios*/
  if((p_head = (CONDOMINIO*)malloc(sizeof(CONDOMINIO)))==NULL)
  {
    puts("\nProblema na memoria.\n");
    return NULL;
  }
  fread(p_head,sizeof(CONDOMINIO),1,pa);
  ultimo_cond = p_head;
  fread(&n_predios,sizeof(int),1,pa);
  if(n_predios==0) p_head->condPredios=NULL;
  else
  {
    for(i=0;i<n_predios;i++)
    {
      if((predio = (PREDIO*)malloc(sizeof(PREDIO)))==NULL)
      {
        puts("\nProblema na memoria.\n");
        return NULL;
      }
      fread(predio,sizeof(PREDIO),1,pa);
      if(i==0) p_head->condPredios=predio;
      else{
        ultimo_predio->pPredio=predio;
      }
      ultimo_predio=predio;
    }

    ultimo_predio=NULL;
  }
  for(i=1/*ja lemos a head*/;i<n_condos;i++)
  {
    if((cond = (CONDOMINIO*)malloc(sizeof(CONDOMINIO)))==NULL)
    {
      puts("\nProblema na memoria.\n");
      return NULL;
    }
    fread(cond,sizeof(CONDOMINIO),1,pa);
    ultimo_cond->pCond=cond;
    ultimo_cond=cond;
    fread(&n_predios,sizeof(int),1,pa);

    if(n_predios==0)cond->condPredios = NULL;

    for(k=0;k<n_predios;k++)
    {
      if((predio = (PREDIO*)malloc(sizeof(PREDIO)))==NULL)
      {
        puts("\nProblema na memoria.\n");
        return NULL;
      }
      fread(predio,sizeof(PREDIO),1,pa);

      if(k==0)
      {
        cond->condPredios=predio;
        ultimo_predio=predio;

      }
      else{
        ultimo_predio->pPredio=predio;
      }
      ultimo_predio=predio;
    }
    ultimo_predio=NULL;

  }
  puts("\nDados carregados com sucesso!\n");
  fclose(pa);
  return p_head;
}

void salvaDados(CONDOMINIO* p_head)
{
  FILE* pa;
  int num_condos=0,*num_predios,i;
  CONDOMINIO *pcondo=p_head;
  PREDIO *predio;

  if(p_head==NULL)
  {
    if((pa = fopen(NOME_ARQ,"wb"))==NULL)
    {
      puts("\n[Erro abrindo arquivo.]\n");
      return;
    }
    return;
  }

  if((pa = fopen(NOME_ARQ,"rb+"))==NULL)
  {
    puts("\n[Erro abrindo arquivo.]\n");
    return;
  }

  /*pegar numero de condominios*/
  while(pcondo!=NULL)
  {
    num_condos++;
    pcondo = pcondo->pCond;
  }
  /*printf("num de condos:%d",num_condos); criando um vetor com o numero de condominios,
   onde sera salvo o numero de predios de cada condominio no "indice" de sua posicao na lista*/
  num_predios = (int*) calloc(num_condos,sizeof(int));
  if(num_predios==NULL)
  {
    puts("Erro de memoria.\n");
    return;
  }
  for(i=0;i<num_condos;i++)
  {
    num_predios[i]=0;
  }

  /*pegar o numero de predio para cada condominio, e salvar de acordo com indice*/
  pcondo=p_head;
  for(i=0;i<num_condos;i++)
  {
    predio=pcondo->condPredios;
    while(predio!=NULL)
    {
      num_predios[i]++;
      predio=predio->pPredio;
    }
    pcondo=pcondo->pCond;
  }
  /* TESTE for(i=0;i<num_condos;i++)
  {
    printf("\nO condominio %d tem %d predios\n",i+1,num_predios[i]);
  }   */

  /*salvar int num_condos
  depois o condo 0
  depois int num_predios[0]
  depois os blocos de predios
  depois outro cond
  repetir ate o ultimo condo*/
  pcondo=p_head;
  fwrite(&num_condos,sizeof(int),1,pa);
  for(i=0;i<num_condos;i++)
  {
    fwrite(pcondo,sizeof(CONDOMINIO),1,pa);/*grava o condominio*/
    fwrite(&num_predios[i],sizeof(int),1,pa);/*grava numero de predios*/
    predio=pcondo->condPredios;
    while(predio!=NULL)
    {
      fwrite(predio,sizeof(PREDIO),1,pa);
      predio=predio->pPredio;
    }
    pcondo=pcondo->pCond;
  }

  fclose(pa);
  return;



}

int main(void){
    CONDOMINIO *pheadCondominios = NULL, *mostrando;
    int opcao=-1,n_cond,existe=0;

    char *menu_1[] =
    { /*menu inicial: mostrar depois da exibicao dos condominios*/
      "\t[SELECIONE A OPERACAO]\n",
      "[1] Criar Condominio\n",
      "[2] Consultar Condominio\n",
      "[3] Demolir condominio\n",
      "[0] Salvar dados & Encerrar Programa.\n",
      NULL
    };
    pheadCondominios = carregaDados();


    puts( "\n\n\n __   __    _                  _           __     _        \n"
          " \\ \\ / /_ _| |  __ ___ _ _  __| |___ _ __ /_/_ _ (_)___ ___\n"
          "  \\ V / _` | | / _/ _ \\ ' \\/ _` / _ \\ '  \\| | ' \\| / _ (_-<\n"
          "   \\_/\\__,_|_| \\__\\___/_||_\\__,_\\___/_|_|_|_|_||_|_\\___/__/\n");




    /*pegando numero de condominios pra mostrar no menu*/
    n_cond=0;
    mostrando=pheadCondominios;

    while(1)
    {
      if(mostrando==NULL) break;
      else
      {
        n_cond++;
        mostrando=mostrando->pCond;
      }
    }

    /*mostrando condominios*/

    if(pheadCondominios==NULL)
    {
      puts("                        [ATENCAO!]\n"
        "[Nao ha condominios atualmente, por favor crie pelo menos um.]\n");
    }
    else
    {
        printf("\t[%d condominios encontrados.]\n",n_cond);
    }


    while(opcao!=0) /*Acabou que o primeiro menu ficou na main mesmo, mals ai se parece desorganizado */
    {
      opcao = mostrarMenu(menu_1);

      switch(opcao)
      {
        case 1:
          puts("\n\n[*~*~*~*~*~*~*~*~] CRIACAO DE CONDOMINIOS [*~*~*~*~*~*~*~]\n");
          criarCondominio(&pheadCondominios);
          puts("\n\n[*~*~*~*~*~*~*~*~] FIM DA CRIACAO [*~*~*~*~*~*~*~]\n");
          break;

        case 2:
          existe=0;
          if(pheadCondominios==NULL)
          {
            puts("\n\t\t[ATENCAO!]\n[Nao ha condominios. Crie pelo menos um condominio!]\n\n");
            break;
          }
          else
          {
            puts("\n\n[*~*~*~*~*~*~*~*~] CONDOMINIOS EXISTENTES [*~*~*~*~*~*~*~]\n");
            mostrando = pheadCondominios;
            while(mostrando!=NULL)
            {
              printf("\n\tCondominio Val %d\n",mostrando->nCond);
              mostrando = mostrando->pCond;
            }
            puts("\nSelecione o numero do condominio:\n");
            opcao=valida_int();
            /*checa se o cond existe*/
            mostrando = pheadCondominios;
            while(mostrando!=NULL)
            {
              if(mostrando->nCond==opcao)
              {
                consultarCondominio(pheadCondominios,opcao);
                existe=1;
                break;
              }
              else
              {
                mostrando=mostrando->pCond;
              }
            }
            if(!existe) puts("\n\t\t[O condominio escolhido nao existe.]\n");
            opcao=-1; /*pra nao fechar o programa*/

          }
          break;

        case 3:
          puts("\n\n[*~*~*~*~*~*~*~*~] DELETAR CONDOMINIO [*~*~*~*~*~*~*~]\n");
          existe=0;
          if(pheadCondominios==NULL)
          {
            puts("\n\t\t[ATENCAO!]\n[Nao ha condominios. Crie pelo menos um condominio!]\n\n");
            break;
          }
          else
          {
            mostrando = pheadCondominios;
            while(mostrando!=NULL)
            {
              printf("\n\tCondominio Val %d\n",mostrando->nCond);
              mostrando = mostrando->pCond;
            }
            puts("\nSelecione o numero do condominio:\n");
            opcao=valida_int();
            /*checa se o cond existe*/
            mostrando = pheadCondominios;
            while(mostrando!=NULL)
            {
              if(mostrando->nCond==opcao)
              {
                demolirCondominio(&pheadCondominios,opcao);
                existe=1;
                puts("\n\t[Condominio deletado com sucesso!]\n\n");
                break;
              }
              else
              {
                mostrando=mostrando->pCond;
              }
            }
            if(!existe) puts("\n\t\t[O condominio escolhido nao existe.]\n");
            opcao=-1; /*pra nao fechar o programa*/

          }
          break;
      }
    }


    salvaDados(pheadCondominios);
    return 0;
}

void criarPredios(PREDIO **pheadPredio){
    PREDIO *novoPredio, *pproxPredio, *panteriorPredio;
    char c;

    novoPredio = (PREDIO*) malloc(sizeof(PREDIO));

    printf("Insira a quantidade de andares do predio:\n");
    scanf("%d", &novoPredio->andares);

    printf("Insira a quantidade de apartamentos por andar:\n");
    scanf("%d", &novoPredio->ApartamentosPorAndar);

    novoPredio->nPredio = 1; /*Primeiro id dos prédios */


    /*Verifica se a lista está vazia e cria uma cabeça */
    if(*pheadPredio == NULL){
        *pheadPredio = novoPredio;
        novoPredio->pPredio = NULL;
    }

    else{
        pproxPredio = *pheadPredio;

        /*Percorre a lista até o final ou até encontrar um "buraco" nos id's dos prédios */
        while((pproxPredio != NULL) && (pproxPredio->nPredio == novoPredio->nPredio)){
            panteriorPredio = pproxPredio;
            pproxPredio = pproxPredio->pPredio;
            novoPredio->nPredio++; /* Incrementa o id do predio por laço*/
        }

        /*Teoricamente era pra acontecer o mesmo erro aqui, to só prevenindo isso*/
        if(pproxPredio == *pheadPredio){
          novoPredio->pPredio = (*pheadPredio)->pPredio;
          *pheadPredio = novoPredio;
        }

        panteriorPredio->pPredio = novoPredio;
        novoPredio->pPredio = pproxPredio;
    }


    printf("Deseja criar outro predio? S/N\n");
    while(1){
        c = getc(stdin);
        if(c == 'S'){
            criarPredios(pheadPredio);
            return;
        }
        else if(c == 'N'){
            return;
        }
    }


}

void criarCondominio(CONDOMINIO **pheadCondominios){
    CONDOMINIO *pproxCondominio, *panteriorCondominio, *novoCondominio;
    char c;


    novoCondominio = (CONDOMINIO*) malloc(sizeof(CONDOMINIO));

    printf("Insira a rua do novo condominio:\n");
    fgets(novoCondominio->rua, 50, stdin);
    novoCondominio->rua[strlen(novoCondominio->rua)-1] = '\0';  /*Manipulação para retirar \n da string */


    novoCondominio->nCond = 1; /* Primeiro id dos condomínios */

    if(*pheadCondominios == NULL){
        *pheadCondominios = novoCondominio;
        novoCondominio->pCond = NULL;
    }
    else{
        pproxCondominio  = *pheadCondominios;

        /*Percorre a lista até o final ou até encontrar um "buraco" nos id's dos condomínios */
        while((pproxCondominio != NULL) && (pproxCondominio->nCond == novoCondominio->nCond)){
            panteriorCondominio = pproxCondominio;
            pproxCondominio = pproxCondominio->pCond;
            novoCondominio->nCond++;
        }
        if(pproxCondominio  == *pheadCondominios)
        {
            novoCondominio->pCond = *pheadCondominios;
            *pheadCondominios = novoCondominio;
            
        }
        else
        {
        panteriorCondominio->pCond = novoCondominio; 
        novoCondominio->pCond = pproxCondominio;
        }
    }


    novoCondominio->condPredios = NULL;
    printf("Deseja criar predios no seu novo condominio? S/N\n");
    while(1){
        c = getc(stdin);
        if(c== 'S'|| c=='s' ){
            criarPredios(&novoCondominio->condPredios);
            return;
        }
        else if(c == 'N'||c=='n'){
            return;
        }
    }

}

void demolirPredio(PREDIO **pheadPredio, int id){
    PREDIO *pproxPred, *panteriorPred, *deleta;


    /*Verificação de lista vazia */
    if(*pheadPredio == NULL){
      printf("Nao existem predios nesse condominio.\n");
      return;
    }

  /*Caso de Exclusão da cabeça da lista*/
  if((*pheadPredio)->nPredio == id){
    /*variável pproxPred é usado como ponteiro auxiliar para liberar a memória no final da operação */
    pproxPred = *pheadPredio;
    /*Checando se a cabeça é o unico elemento */
    if((*pheadPredio)->pPredio == NULL)
    {
      free(*pheadPredio);
      *pheadPredio = NULL;
      return;
    }
    else
    {
    *pheadPredio = (*pheadPredio)->pPredio;
    }

    free(pproxPred);
    /*mudando numero dos outros predios*/
    pproxPred = *pheadPredio;
    while(pproxPred!=NULL)
    {
      pproxPred->nPredio--;
      pproxPred=pproxPred->pPredio;
    }
    return;
  }

  /*Percorrer a lista até encontrar o final ou até encontrar o predio que deve ser excluído */
  pproxPred = *pheadPredio;
  while((pproxPred != NULL) && (pproxPred->nPredio != id))
  {
    panteriorPred = pproxPred;
    pproxPred = pproxPred->pPredio;
  }
  deleta = pproxPred;

  if(pproxPred == NULL){
    printf("Nao existe predio com esse identificador.\n");
    return;
  }

  /*ligando p_anterior ao p prox,isolando o q vai ser apagado*/
  panteriorPred->pPredio = deleta->pPredio;
    while(pproxPred->pPredio!=NULL)
    {
      /*mudando numero dos predios seguintes ao deletado (diminuindo 1) */
      (pproxPred->pPredio)->nPredio--;
      pproxPred = pproxPred->pPredio;
    }
    free(deleta);

  return;
}

void demolirCondominio(CONDOMINIO **pheadCondominio, int id){
  CONDOMINIO *pproxCond, *panteriorCond,*deleta=NULL;
  PREDIO *pPred, *panteriorPred;


  

  /*Verificação de lista vazia */
    if(*pheadCondominio == NULL){
      printf("Nao existem condominios.\n");
      return;
    }
  /*Caso de Exclusão da cabeça da lista */
  if((*pheadCondominio)->nCond == id){
    /*variável pproxCond é usado como ponteiro auxiliar para liberar a memória no final da operação 
    mudança: usei o "deleta" pra isso */
    deleta = *pheadCondominio;

    *pheadCondominio = (*pheadCondominio)->pCond;
    pPred = deleta->condPredios;
  }

  if(deleta==NULL)
  {
    pproxCond = *pheadCondominio;
    while((pproxCond != NULL) && (pproxCond->nCond != id)){
        panteriorCond = pproxCond;
        pproxCond = pproxCond->pCond;
      }
    deleta=pproxCond;
    panteriorCond->pCond = deleta->pCond;
  }
  

  if(deleta == NULL){
    printf("Nao existe condominio com esse identificador.\n");
      return;
    }


  /* Percorrer e deletar os predios nesse condomínio*/
    pPred = deleta->condPredios;
    while(pPred != NULL){
      panteriorPred = pPred;
      pPred = pPred->pPredio;
      free(panteriorPred);
    }

  free(deleta);

  return;
}
