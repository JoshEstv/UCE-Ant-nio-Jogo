#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char pergunta[256];
    char opcoes[4][256];
    char respostaCorreta;
} Pergunta;

char fazerPergunta(Pergunta p) {
    char respostaUsuario;
    printf("%s\n", p.pergunta);
    for (int i = 0; i < 4; i++) {
        printf("%c: %s\n", 'A' + i, p.opcoes[i]);
    }
    printf("Sua resposta (A, B, C ou D): ");
    scanf(" %c", &respostaUsuario);
    return respostaUsuario;
}

int main() {
    Pergunta perguntas[] = {
        {
            "Qual e a capital da Franca?",
            {"Paris", "Londres", "Berlim", "Madri"},
            'A'
        },
        {
            "Qual e o maior planeta do sistema solar?",
            {"Terra", "Marte", "Jupiter", "Saturno"},
            'C'
        },
        {
            "Quem escreveu 'Dom Quixote'?",
            {"Miguel de Cervantes", "William Shakespeare", "Dante Alighieri", "Leo Tolstoy"},
            'A'
        },
        {
            "Qual e o elemento quimico com simbolo O?",
            {"Oxigenio", "Ouro", "Osmium", "Osmio"},
            'A'
        }
    };

    int numPerguntas = sizeof(perguntas) / sizeof(perguntas[0]);
    int premio = 0;
    int valoresPremios[] = {1000, 5000, 10000, 50000};
    char respostaUsuario;

    for (int i = 0; i < numPerguntas; i++) {
        printf("\nPergunta %d valendo R$ %d\n", i + 1, valoresPremios[i]);
        respostaUsuario = fazerPergunta(perguntas[i]);
        if (respostaUsuario == perguntas[i].respostaCorreta) {
            printf("Correto! Voce ganhou R$ %d\n", valoresPremios[i]);
            premio += valoresPremios[i];
        } else {
            printf("Errado! A resposta correta era %c\n", perguntas[i].respostaCorreta);
            printf("Voce ganhou um total de R$ %d\n", premio);
            break;
        }
    }

    if (premio == valoresPremios[numPerguntas - 1]) {
        printf("Parabens! Voce ganhou o premio maximo de R$ %d\n", premio);
    }

    return 0;
}
