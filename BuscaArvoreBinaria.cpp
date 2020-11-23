#include <stdio.h> // stdio.h: Biblioteca padrão de Entrada/Saida - Standard Input-Output Header - Cabeçalho Padrão de Entrada/Saída
#include <stdlib.h> // stclib.h: Biblioteca de Propósito Geral -  Ela possui funções envolvendo alocação de memória, controle de processos, conversões e outras
#include <locale.h>



// Declaração da Estrutura do Registro
struct content {

	int valor;
	
};



// Declaração da Estrutura da Árvore
struct No {
	
	int numero;
	struct content x;
	struct No *esquerda;
	struct No *direita;

};

typedef struct No No;



// Criar Árvore
void criarArvore(No **pRaiz) {
	
	*pRaiz = NULL;

}



// Inserir Elemento
void inserir(No **pRaiz, int numero, struct content x) {
	
	
	if(*pRaiz == NULL) {
		
		*pRaiz = (No *) malloc(sizeof(No));
		(*pRaiz)->esquerda = NULL;
		(*pRaiz)->direita = NULL;
		
		(*pRaiz)->numero = numero;
		(*pRaiz)->x = x;
		
	
	} else {
		
		
		if(numero < (*pRaiz)->numero) {
		
			inserir(&(*pRaiz)->esquerda, numero, x);
		
		} else {

			inserir(&(*pRaiz)->direita, numero, x);
		
		}
		
	
	}
	

}



// Teste Nó Maior Direita
No *MaiorDireita(No **no) {
	
	
	if((*no)->direita != NULL) {
	
		return MaiorDireita(&(*no)->direita);
		
	} else {
		
		No *aux = *no;
		
		if((*no)->esquerda != NULL) {
		
			*no = (*no)->esquerda;
			
		} else {
		
			*no = NULL;
			return aux;
		
		}
	
	}


}



// Teste Nó Maior Esquerda
No *MenorEsquerda(No **no) {
	
	
	if((*no)->esquerda != NULL) {
	
		return MenorEsquerda(&(*no)->esquerda);
		
	} else {
		
		No *aux = *no;
		
		if((*no)->direita != NULL) {
			
			*no = (*no)->direita;
			
		} else {
		
		*no = NULL;
		
		}
		
		return aux;
		
	}


}



// Remover Elemento
void remover(No **pRaiz, int numero) {
	
	
	if(*pRaiz == NULL) {
		
		printf("\nNúmero não existe na árvore!\n");
		
		return;
		
	}
	
	if(numero < (*pRaiz)->numero) {
	
		remover(&(*pRaiz)->esquerda, numero);
		
	} else if(numero > (*pRaiz)->numero) {
	
		remover(&(*pRaiz)->direita, numero);
	
	} else {
		
		No *pAux = *pRaiz;
		
		if (((*pRaiz)->esquerda == NULL) && ((*pRaiz)->direita == NULL)) {
			
			free(pAux);
			
			printf("\nRemovido com Sucesso! \n");
			
			(*pRaiz) = NULL;
		
		} else {
			
			if ((*pRaiz)->esquerda == NULL) {
				
				(*pRaiz) = (*pRaiz)->direita;
				
				pAux->direita = NULL;
				
				free(pAux); pAux = NULL;
				
				printf("\nRemovido com Sucesso! \n");
			
			} else {
				
				if ((*pRaiz)->direita == NULL) {
					
					(*pRaiz) = (*pRaiz)->esquerda;
					
					pAux->esquerda = NULL;
					
					free(pAux); pAux = NULL;
					
					printf("\nRemovido com Sucesso! \n");
				
				} else {
					
					pAux = MaiorDireita(&(*pRaiz)->esquerda);
					
					pAux->esquerda = (*pRaiz)->esquerda;
					
					pAux->direita = (*pRaiz)->direita;
					
					(*pRaiz)->esquerda = (*pRaiz)->direita = NULL;
					
					free((*pRaiz)); *pRaiz = pAux; pAux = NULL;
					
					printf("\nRemovido com Sucesso! \n");
	
				}
	
	
			}
	
	
		}
	
	
	}


}



// Busca em Profundidade Pré-Ordem
void exibirPreOrdem(No **pRaiz) {
	
	
	if((*pRaiz) != NULL) {
		
		printf("%i\n", (*pRaiz)->numero);
		
		exibirPreOrdem(&(*pRaiz)->esquerda);
		
		exibirPreOrdem(&(*pRaiz)->direita);
		
	}


}



// Busca em Profundidade Em Ordem
void exibirEmOrdem(No **pRaiz) {
	
	
	if((*pRaiz) != NULL) {
		
		exibirEmOrdem(&(*pRaiz)->esquerda);
		
		printf("%i\n", (*pRaiz)->numero);
		
		exibirEmOrdem(&(*pRaiz)->direita);
	
	}


}



// Busca em Profundidade Pós-Ordem
void exibirPosOrdem(No **pRaiz) {
	
	
	if((*pRaiz) != NULL) {
		
		exibirPosOrdem(&(*pRaiz)->esquerda);
		
		exibirPosOrdem(&(*pRaiz)->direita);
		
		printf("%i\n", (*pRaiz)->numero);
	
	}


}



// Verifica Quem é o Maior
int maior(int a, int b) {

	
	if(a > b) {
	
		return a;
	
	} else {
	
		return b;
		
	}

}



// Imprimir Árvore
int imprimir(No **pRaiz) {
	
	
	if((*pRaiz) != NULL) {
		
		
		if((*pRaiz) != NULL) {
		
			printf("\nPai %i\n",(*pRaiz)->numero);
		
		}
		
		if((*pRaiz)->esquerda != NULL) {
		
			printf("Esq: %i\t",(*pRaiz)->esquerda->numero);
		
		} else {
		
			printf("Esq: NULL\t");
			
		}
		
		if((*pRaiz)->direita != NULL) {
		
			printf("Dir: %i\t",(*pRaiz)->direita->numero);
		
		} else{
		
			printf("Dir: NULL\t");
			
		}
		
		if((*pRaiz)->esquerda != NULL) {
		
			imprimir(&(*pRaiz)->esquerda);
			
		}
		
		if((*pRaiz)->direita != NULL) {
		
			imprimir(&(*pRaiz)->direita);
			
		}
	
	
	} else {
	
		printf("A Árvore Está Vazia! \n");
		
	}
	
	
}





int main(){

    setlocale (LC_ALL, "Portuguese");

    // Inicio Variáveis
    struct content con;
	int c, op;
	No *pRaiz;
	criarArvore(&pRaiz);
	
	
	
	
	do{
		
		
		printf("\n\nEscolha uma Opção:\n");
		
		
		printf("\n(1) Incluir nó\n");
		printf("(2) Remover nó\n");
		printf("(3) Buscar Pré-Ordem\n");
		printf("(4) Buscar em Ordem\n");
		printf("(5) Buscar Pós-Ordem\n");
		printf("(6) Imprimir Árvore\n");
		printf("(0) Encerrar o Programa\n\n");
		printf(" ? ");
		scanf("%d", &op);
	
	
		system("cls");
		
		
		switch (op) {
			
			
			case 1: // Incluir nó
			
				printf("\nDigite um Valor: ");
				scanf("%d",&con);
				printf("\nDigite um Número (Referência na Árvore): ");
				scanf("%d",&c);
				inserir(&pRaiz,c, con);
				
				printf("\nInserido com Sucesso! \n");
			
			break;
			
			
			case 2: // Remover nó
			
				printf("\nDigite um Número: ");
				scanf("%d",&c);
				remover(&pRaiz,c);
				
			break;
			
			
			case 3: // Buscar Pré-Ordem
			
				exibirPreOrdem(&pRaiz);
			 	
			break;
			
			
			case 4: // Buscar em Ordem
			
				exibirEmOrdem(&pRaiz);
			
			break;
			
			
			case 5: // Buscar Pós-Ordem
			
				exibirPosOrdem(&pRaiz);
			
			break;
			
			
			case 6: // Imprimir Árvore
			
				imprimir(&pRaiz);
			
			break;
			
			
			case 0: // Encerrar o Programa
		
				
				system("cls");
			    printf("\n\nPrograma executado com sucesso!!\n\n");
	    		system("pause"); // Pausa o Programa Após Executar
	    		
				// op = 0;
			
				exit(0);
			
			
			default:
				
				printf("\nERRO: Opção Inexistente! \n\n");
		
		
		}
		
		
	} while ( op != 0 );

    return 0;

}
