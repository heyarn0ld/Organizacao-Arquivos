
	/*
	Nome:Eduardo Kiyoshi Kamikabeya     NUSP: 9778536
	Nome:   NUSP:
	Nome:   NUSP:
	Nome:    NUSP:

	Tamanho dos campos:
        Numero USP = 7, nome Docente = 30, sobrenome Docente = 30, departamento = 10, ano = 4
    Nao tive a possibilidade de verificar se os campos inseridos pelo usuario ultrapassam esse limite.

	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define idSize 8
#define tituloSize 20
#define producaoSize 20
#define anoSize 5
#define temporadaSize 3
#define generoSize 20

typedef struct 	serie{
	char idSerie[idSize];
	char tituloSerie[tituloSize];
	char producao[producaoSize];// Nome do pais que produziu a serie
	char anoLancamento[anoSize];
	char temporada[temporadaSize];
	char generoSerie[generoSize];

	char descSerie[200];
}Serie;

//Procura string valida, retirando o lixo
void cortaString(char *c, int n){
    int i, pos;
    for(i = 0; i < n;i++){
        if(c[i] == '\n'){
            pos = i;
            i = n;
        }
    }
    c[pos] = '\0';
}

void write(char registro[82], int valor){
    FILE *fw = fopen( "dados.txt", "ab");
    fwrite(&valor, sizeof(int), 1, fw);
    fclose(fw);
}

void print(Serie series[100], int nRegistros){
    int j;
    for(j = 0; j < nRegistros; j++){
        printf("%s\n", series[j].tituloSerie);
        printf("%s\n", series[j].descSerie);
        printf("%s\n", series[j].producao);
        printf("%s\n", series[j].anoLancamento);
        printf("%s\n", series[j].temporada);
        printf("%s\n", series[j].generoSerie);
    }
}
// Puxa o arquivo de texto com as series para o vetor de Series
Serie *read(int *nRegistros){
    Serie series[100];
    Serie *s = series;
    char buffer[200];

    FILE *fr;

    int i = 0, j = 0, k;

    fr = fopen( "01.txt", "r");
    while(fgets(buffer, 200, fr) != NULL){
        if(i == 4){
            i = 0;
            j++;
            //+1 por causa do 0
            (*nRegistros) = j + 1;
        }
        cortaString(buffer, 200);

        switch(i){
            case 0:
                strcpy(series[j].tituloSerie, buffer);
                break;
            case 1:
                k=0;
                while(buffer[k] != '\0'){
                    series[j].descSerie[k] = buffer[k];
                    k++;
                }
                series[j].descSerie[k] = '\0';
                printf("%s\n", series[j].descSerie);
                //strcpy(series[j].descSerie, buffer);
                break;
            case 2:
                strcpy(series[j].producao, buffer);
                break;
            case 3:
                for(k = 0; k < 4;k++){
                    series[j].anoLancamento[k] = buffer[k];
                }
                series[j].anoLancamento[4] = '\0';
                series[j].temporada[0] = buffer[5];
                series[j].temporada[1] = '\0';
                k=7;
                while(buffer[k] != '\0'){
                        series[j].generoSerie[k-6] = buffer[k];
                        k++;
                }
                series[j].generoSerie[k] = '\0';
                break;
        }
        i++;

    }
    fclose(fr);
    return s;
}
Serie *copiaSerie(Serie s){
    Serie *ps;
    Serie serie;
    ps = &serie;
    strcpy(serie.tituloSerie, s.tituloSerie);
    strcpy(serie.descSerie, s.descSerie);
    strcpy(serie.generoSerie, s.generoSerie);
    strcpy(serie.anoLancamento, s.anoLancamento);
    strcpy(serie.producao, s.producao);
    strcpy(serie.temporada, s.temporada);
    return ps;
}
//Pega os dados da memoria principal e torna aleatoria a ordem dos registros
Serie *gerarRegistros(Serie *series, int nRegistros){
    int i,randomNumber, k;
    Serie *s;
    Serie auxVetorSerie[nRegistros];
    s = auxVetorSerie;
    int ocupado[nRegistros];

    for(i = 0; i < nRegistros; i++){
        ocupado[i] = 0;
    }

    for(i = 0; i < nRegistros; i++){

        randomNumber = rand() % nRegistros;
        if(ocupado[randomNumber] == 0){
            //Registro nao repetido
            ocupado[randomNumber] = 1;

            //auxVetorSerie[randomNumber] = *copiaSerie(series[i]);


            strcpy(auxVetorSerie[randomNumber].tituloSerie, s[i].tituloSerie);
            strcpy(auxVetorSerie[randomNumber].descSerie, s[i].descSerie);
            strcpy(auxVetorSerie[randomNumber].generoSerie, s[i].generoSerie);
            strcpy(auxVetorSerie[randomNumber].anoLancamento, s[i].anoLancamento);
            strcpy(auxVetorSerie[randomNumber].producao, s[i].producao);
            strcpy(auxVetorSerie[randomNumber].temporada, s[i].temporada);
        }else{
            i--;
        }
    }
    return s;
}

mostrarRegistros(){}
//Busca sequencial
buscarRegistro(char chavePrimaria[8], Serie series[100]){

    int i, j;
}

Serie menu(){
    int opcao;

	do{
        printf("Selecione a opcao desejada: ");
        printf("\t(0) Geracao de 100 registros do arquivo de dados\n");
        printf("\t(1) Mostrar todos os registros\n");
        printf("\t(2) Buscar Registro por Chave Primaria\n");
        printf("\t(3) Sair\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 0:
                //gerarRegistros();
                break;
            case 1:
                //mostrarRegistros();
                break;
            case 2:
                //buscarRegistros();
                break;
        }
	}while(opcao != 3);
    /*
        Buscar por chave principal - sequencial
        Mostrar tds os registros
        geracao automatica de 100 registros do arquivo de dados
    */
}
int main(){

    char registro[82];
    Serie *s;
    Serie *rs;
    int nRegistros;
	//write(registro, 5);
    s = read(&nRegistros);
    //rs = gerarRegistros(s, nRegistros);

    //printf("\n%d\n", nRegistros);
    print(s, nRegistros);

    while(1);
	return 0;
}
