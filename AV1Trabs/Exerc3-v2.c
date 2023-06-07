#include <stdio.h>
#include <time.h>
#include <string.h>

struct Pet {
    int codigo;
    char nome[50];
    char tutor[50];
    char email[100];
    char dataVacina[11]; // formato dd/mm/aaaa
};

//Protótipos das funções
void gerarArquivoVacinasVencidas(const struct Pet pets[], int tamanho);


int main(int argc, char const *argv[])
{
    //Atriubuir valores para o vetor de struct
    struct Pet pets[4] = {
        {1, "Bolinha", "João", "teste@teste.com", "01/01/2020"},
        {2, "Peludo", "Maria", "teste@teste.com", "10/10/2019"},
        {3, "Pipoca", "José", "teste@teste.com", "01/01/2019"},
        {4, "Rosinha", "Joana", "teste@teste.com", "01/01/2023"}
    };

    gerarArquivoVacinasVencidas(pets, 4);
  return 0;
}


void gerarArquivoVacinasVencidas(const struct Pet pets[], int tamanho) {
    FILE *arquivo;
    arquivo = fopen("vacinas_vencidas.txt", "w");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    time_t dataAtual = time(NULL);
    struct tm tmDataVacina;
    

    //não lembro se pode usar time.h, mas acho que sim.
    for (int i = 1; i < tamanho; i++) {
        sscanf(pets[i].dataVacina, "%d/%d/%d", &tmDataVacina.tm_mday, &tmDataVacina.tm_mon, &tmDataVacina.tm_year);
        tmDataVacina.tm_mon--; // Ajuste do mês (0-11)
        tmDataVacina.tm_year -= 1900; // Ajuste do ano (ano atual - 1900)
        
        time_t dataVacina = mktime(&tmDataVacina);
        double diff = difftime(dataAtual, dataVacina);
        
        if (diff > 31536000) { // Mais de um ano em segundos (365 * 24 * 60 * 60)
            fprintf(arquivo, "Prezado %s, a vacina do pet %s venceu no dia %s.\nPodemos agendar a nova dose?\n", 
                    pets[i].tutor, pets[i].nome, pets[i].dataVacina);
        }
    }
    
    fclose(arquivo);
}
