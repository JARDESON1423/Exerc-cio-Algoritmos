#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 5

// Função para calcular a média de 3 notas
float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3.0;
}

int main() {
    char nomes[MAX_ALUNOS][50];
    float nota1[MAX_ALUNOS], nota2[MAX_ALUNOS], nota3[MAX_ALUNOS];
    float medias[MAX_ALUNOS];
    char situacoes[MAX_ALUNOS][10];
    int i;
    int indiceMaiorMedia = 0;

    printf("=== Cadastro de Alunos ===\n");

    for (i = 0; i < MAX_ALUNOS; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", nomes[i]);

        // Leitura e validação das notas
        do {
            printf("Nota 1 (0 a 10): ");
            scanf("%f", &nota1[i]);
        } while (nota1[i] < 0 || nota1[i] > 10);

        do {
            printf("Nota 2 (0 a 10): ");
            scanf("%f", &nota2[i]);
        } while (nota2[i] < 0 || nota2[i] > 10);

        do {
            printf("Nota 3 (0 a 10): ");
            scanf("%f", &nota3[i]);
        } while (nota3[i] < 0 || nota3[i] > 10);

        // Calcula a média
        medias[i] = calcularMedia(nota1[i], nota2[i], nota3[i]);

        // Define situação
        if (medias[i] >= 7.0)
            strcpy(situacoes[i], "Aprovado");
        else
            strcpy(situacoes[i], "Reprovado");

        // Verifica maior média
        if (medias[i] > medias[indiceMaiorMedia]) {
            indiceMaiorMedia = i;
        }
    }

    // Exibe resultados
    printf("\n=== Resultado Final ===\n");
    printf("%-20s %-6s %-6s %-6s %-6s %-10s\n", "Nome", "N1", "N2", "N3", "Média", "Situação");

    for (i = 0; i < MAX_ALUNOS; i++) {
        printf("%-20s %-6.1f %-6.1f %-6.1f %-6.1f %-10s\n",
               nomes[i], nota1[i], nota2[i], nota3[i], medias[i], situacoes[i]);
    }

    // Aluno com maior média
    printf("\nAluno com maior média: %s (%.2f)\n", nomes[indiceMaiorMedia], medias[indiceMaiorMedia]);

    return 0;
}
