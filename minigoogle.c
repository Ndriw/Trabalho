#include "minigoogle.h"


struct lista{
												
	NODE *fim;															// o deque é a estrutura que irá guardar o tamanho,	
	NODE *inicio;														// o endereço do primeiro e o endereço do ultimo item da lista
	int tamanho;
	
};

struct node{
	
	ITEM *iteem;
	NODE *proximo;
	
};


char *readline(FILE *arq_entrada){                                      //função para ler ate a quebra de linha

    int cont = 0;
    char *string = NULL, c;

    do{
        c = fgetc(arq_entrada);
		string = (char*) realloc (string, sizeof(char) * (cont+1) );    //le o caractere e o salva enquanto este n for
		string[cont] = c;                                               //um fim de linha
		cont++;
        
    }while(c != '\n' && c != EOF);

    string[cont - 1] = '\0';                        					//adiciona um \0 no final da linha para indicar uma string

    return string;                      								//retorna a string
}




LISTA *criar_lista(){
	
	LISTA *listaa;
 
	listaa = (LISTA *) malloc(sizeof(LISTA));

	if(listaa != NULL) {
		listaa->inicio = NULL;
		listaa->fim = NULL;
		listaa->tamanho = 0;
	}
 
 return (listaa);
}





int inserir_final_lista(LISTA *listaa, ITEM *iteem){

	NODE *no;
		
	no = (NODE *) malloc(sizeof (NODE));
	
    if (listaa != NULL && iteem != NULL){
	
		if (listaa->inicio == NULL){
			no->iteem = iteem;
			listaa->inicio = no;
			no->proximo = NULL;
			listaa->fim = no;
			listaa->tamanho++;
		}
		else {
			listaa->fim->proximo = no;
			no->iteem = iteem;
			no->proximo = NULL;
			listaa->fim = no;
			listaa->tamanho++;
		}
		
		return 1;
	
	}
	
	
	return 0;
}






int vazio_lista(LISTA *listaa){
	
	if(listaa != NULL){
		
		if(listaa->inicio == NULL){
			return 1;
		}
	}
	
	return 0;
}






int tamanho_lista(LISTA *listaa){
	
	if(listaa != NULL){
		return listaa->tamanho;
	}
	
	return 0;
}





NODE *fim_lista(LISTA *listaa){
	
	if(listaa != NULL){
		return listaa->fim;
	}
	
	return NULL;
}







int retirar_item(LISTA *listaa, int codigo) {
	
	NODE *aux1, *aux2;
	
	aux1 = listaa->inicio;
	aux2 = NULL;
	
	if (listaa != NULL  && !vazio_lista(listaa) ){
		
		while(aux1 != NULL && (codigo_item(aux1->iteem)) != codigo) { 		
			aux2 = aux1; 													
			aux1 = aux1->proximo;
		}
		
		if(aux1 != NULL) {
		
			if(aux1 == listaa->inicio) { 									
				listaa->inicio = aux1->proximo;
				aux1->proximo = NULL;
				apagar_item( &(aux1->iteem) );
				listaa->tamanho--;
				free(aux1);
			}
		
			else {
				aux2->proximo = aux1->proximo;
				aux1->proximo = NULL;
				apagar_item( &(aux1->iteem) );
				listaa->tamanho--;
				free(aux1);
			}
			
			if(aux1 == listaa->fim){
				listaa->fim = aux2;
			}
			 
			return 1;
		}
	}
	
	return 0;
}







int inserir_posicao_lista(LISTA *listaa, ITEM *iteem){
	
	NODE *aux1, *aux2;
	NODE *no;
		
	no = (NODE *) malloc(sizeof (NODE));
	
	aux1 = listaa->inicio;
	aux2 = NULL;
	
    if (listaa != NULL && iteem != NULL && no != NULL){
	
		if( vazio_lista(listaa) ){
			no->iteem = iteem;
			listaa->inicio = no;
			no->proximo = NULL;
			listaa->fim = no;
			listaa->tamanho++;
		}else{
		
			while(aux1 != NULL && codigo_item(aux1->iteem) > codigo_item(iteem) ){
				aux2 = aux1;
				aux1 = aux1->proximo;
			}
			
			if(aux1 != NULL && codigo_item(aux1->iteem) == codigo_item(iteem) ){
				return 0;
			}else{
			
				if(aux2 == listaa->fim){
					no->iteem = iteem;
					listaa->fim->proximo = no;
					listaa->fim = no;
					no->proximo = NULL;
					listaa->tamanho++;
				}else{
			
					if(aux1 == listaa->inicio){
						no->iteem = iteem;
						no->proximo = aux1;
						listaa->inicio = no;
						listaa->tamanho++;	
					}else{
						no->iteem = iteem;
						no->proximo = aux1;
						aux2->proximo = no;
						listaa->tamanho++;
					}
					
				}
				
			}
		}
		
		
		return 1;
	
	}
	
	return 0;
}




void imprimir_lista(LISTA *listaa){
	
	NODE *aux;
	
	if(listaa != NULL){
		
		aux = listaa->inicio;
		
		while(aux != NULL){
			imprimir_item(aux->iteem);
			aux = aux->proximo;
		}
	
	}
	
	return;
}

int apagar_lista(LISTA **listaa){
	
	NODE *aux;
	
	if(listaa != NULL && *listaa != NULL){
	
		while( (*listaa)->inicio != NULL){
			
			aux = (*listaa)->inicio;
			(*listaa)->inicio = (*listaa)->inicio->proximo;
			aux->proximo = NULL;
			apagar_item(&(aux->iteem));
			free(aux);
			aux = NULL;
		}
	
		(*listaa)->fim = NULL;
	
		free(*listaa);
		*listaa = NULL;
		
		
		return 1;
	
	}
	
	
	return 0;
}

int inserir_palavra_chave(LISTA *listaa, int codigo, char *palavrachave){
	
	NODE *aux1;
	
	aux1 = listaa->inicio;
	
	if(listaa != NULL && palavrachave != NULL){
	
		while(aux1 != NULL && codigo_item(aux1->iteem) != codigo ){
			aux1 = aux1->proximo;
		}
		
		if(aux1 != NULL){
			
			adicionar_palavra_chave(aux1->iteem, palavrachave);
	
		}else{
			return 0;
		}
	
	
	}
	
	return 0;
}

int inserir_relevancia(LISTA *listaa, int codigo, int relevancia){
	
	NODE *aux;
	
	if(listaa != NULL){
		
		aux = listaa->inicio;
		
		while(aux != NULL && codigo_item(aux->iteem) != codigo ){
			aux = aux->proximo;
		}
		
		
		if(aux != NULL){
			
			mudar_relevancia(aux->iteem, relevancia);
			
		}else{
			return 0;
		}
		
		
	}
	
	
	return 0;
}

