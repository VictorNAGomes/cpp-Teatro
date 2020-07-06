/*
	Função: Teatro
	Autor: Marcos Fajoli
	Autor: Victor Nathan
	Data de Inicio: 22/11/2019
	Data de Término: 28/11/2019
*/


#include <stdio.h>
#include <windows.h>
#include <locale.h>

char teatro[20][25];
int inicio = 1, opcao = 0, verMeiaInt = 0, processos = 1, lin = 0, col = 0, linhas = 0, colunas = 0, validar = 0, cpRs = 0, comprarMeiaInt = 0, disponivel = 0, vendaInteira = 0, vendaMeia = 0, reservaInteira = 0, reservaMeia = 0, totalUso = 0, lugaresVendidos = 0;
float ingresso = 0, valorIngressoTotal = 0, dinheiroArrecadado = 0;
bool podeIniciar = false;

void mostrar_mapa_inicial(){
	printf("\nMAPA DO TEATRO \n\nLEGENDA\n");
	printf("- D = Ingressos Disponíveis\n- V = Ingressos Inteiros Vendidos\n- v = Ingressos Meias Vendidos\n- I = Ingressos Inteiros Reservados\n- M = Ingressos Meias Reservados\n\n");
	printf("     01  02  03  04  05  06  07  08  09  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25\n");
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 25; j++){
			if(j == 0){
				printf("    _____");
			}else{
				printf("____");
			}	
		}
		printf("\n");
		if(i < 9){
			printf("0%i  ", i+1);
		}else{
			printf("%i  ", i+1);
		}
		for(int k = 0; k < 25; k++){
			printf("| %c ", teatro[i][k]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void mostrar_mapa_modificado(){
	printf("\nMAPA DO TEATRO - MODIFICADO\n\nLEGENDA\n");
	printf("- D = Ingressos Disponíveis\n- V = Ingressos Inteiros Vendidos\n- v = Ingressos Meias Vendidos\n- I = Ingressos Inteiros Reservados\n- M = Ingressos Meias Reservados\n\n");
	for(int c = 0; c < colunas; c++){
		if(c == 0){
			printf("     0%i  ", c+1);
		}
		else if(c < 9){
			printf("0%i  ", c+1);
		}else{
			printf("%i  ", c+1);
		}
	}
	printf("\n");
	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			if(j == 0){
				printf("    _____");
			}else{
				printf("____");
			}	
		}
		printf("\n");
		if(i < 9){
			printf("0%i  ", i+1);
		}else{
			printf("%i  ", i+1);
		}
		for(int k = 0; k < colunas; k++){
			printf("| %c ", teatro[i][k]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void zerar_mapa(){
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 25; j++){
			teatro[i][j] = 'D';
		}
	}
}

void reservar_comprar_lugar() {
	system("CLS");
	printf("\nRESERVA E COMPRA DE LUGARES\n");
	mostrar_mapa_modificado();
	validar = 0;
	while(validar != 1){
		printf("\nDigite a linha e coluna onde deseja comprar ou reservar, separadas por um espaço:");
		scanf("%i %i", &lin, &col);
		while( (lin < 1 or lin > linhas) and (col < 1 or col > colunas) ){
			printf("	Digite uma linha e coluna válidas: ");
			scanf("    %i %i", &lin, &col);
		}
		while(lin < 1 or lin > linhas){
			printf("	Digite uma linha válida: ");
			scanf("    %i", &lin);
		}
		while(col < 1 or col > colunas){
			printf("	Digite uma coluna válida: ");
			scanf("    %i", &col);
		}
		
		while(teatro[lin-1][col-1] == 'V' or teatro[lin-1][col-1] == 'v'){
			printf("\nPOSIÇÃO JÁ COMPRADA\n");
			printf("\nDigite novamente a linha e coluna onde deseja comprar ou reservar, separadas por um espaço:");
			scanf("%i %i", &lin, &col);
			while( (lin < 1 or lin > linhas) and (col < 0 or col > colunas) ){
				printf("	Digite uma linha e coluna válidas: ");
				scanf("    %i %i", &lin, &col);
			}
			while(lin < 1 or lin > linhas){
				printf("	Digite uma linha válida: ");
				scanf("    %i", &lin);
			}
			while(col < 1 or col > colunas){
				printf("	Digite uma coluna válida: ");
				scanf("    %i", &col);
			}
		}
		
		
		printf("\nVocê deseja comprar ou reservar o ingresso? (Digite 1 para comprar e 2 para reservar): ");
		scanf("%i", &cpRs);
		while(cpRs < 1 or cpRs > 2){
			printf("Insira uma opção válida: ");
			scanf("%i", &cpRs);
		}
		
		while(cpRs == 2 and teatro[lin-1][col-1] == 'I' or teatro[lin-1][col-1] == 'M' or teatro[lin-1][col-1] == 'V' or teatro[lin-1][col-1] == 'v'){
			printf("\nPOSIÇÃO JÁ RESERVADA\n");
			printf("\nDigite novamente a linha e coluna onde deseja reservar, separadas por um espaço:");
			scanf("%i %i", &lin, &col);
			while( (lin < 1 or lin > linhas) and (col < 1 or col > colunas) ){
				printf("	Digite uma linha e coluna válidas: ");
				scanf("    %i %i", &lin, &col);
			}
			while(lin < 1 or lin > linhas){
				printf("	Digite uma linha válida: ");
				scanf("    %i", &lin);
			}
			while(col < 1 or col > colunas){
				printf("	Digite uma coluna válida: ");
				scanf("    %i", &col);
			}
		}
		
		if(cpRs == 1){
			printf("\nVocê escolheu comprar. \n");
			system("pause");
		}else{
			printf("\nVocê escolheu reservar. \n");
			system("pause");
		}
		
		
		if(cpRs == 2){ //se for reserva
			printf("O lugar a ser reservado será uma inteira ou meia? (Ingressos \"meia\" pagam metade do preço) Digite 1 para inteira e 2 para meia: ");
			scanf("%i", &verMeiaInt);
			while(verMeiaInt < 1 or verMeiaInt > 2){
				printf("\nInsira um número válido: ");
				scanf("%i", &verMeiaInt);
			}
			
			if(verMeiaInt == 1){
				printf("\nVocê escolheu inteira. \n");
				system("pause");
			}else{
				printf("\nVocê escolheu meia. \n");
				system("pause");
			}
			
			printf("\nDeseja realmente validar a reserva? O local será comprado e o dinheiro somado (1 para sim e 2 para não): ");
		}else{
			printf("\nDeseja realmente validar a compra? (1 para sim e 2 para não): ");
		}
		
		
		scanf("%i", &validar);
		while(validar < 1 or validar > 2){
			printf("	Digite uma opção válida: " );
			scanf("%i", &validar);
		}
		
		if(validar == 1){
			if(cpRs == 1){
				if(teatro[lin-1][col-1] == 'D'){
					printf("\nInsira 1 para comprar uma meia e 2 para uma inteira: ");
					scanf("%i", &comprarMeiaInt);
					while(comprarMeiaInt < 1 or comprarMeiaInt > 2){
						printf("\nInsira uma opção válida: ");
						scanf("%i", &comprarMeiaInt);
					}
					
					if(comprarMeiaInt == 1){
						teatro[lin-1][col-1] = 'v';
						valorIngressoTotal += ingresso/2;
					}else{
						teatro[lin-1][col-1] = 'V';
						valorIngressoTotal += ingresso;
					}
				}else{
					if(teatro[lin-1][col-1] == 'M'){
						teatro[lin-1][col-1] = 'v';
						valorIngressoTotal += ingresso/2 * 0.40;
					}else{
						teatro[lin-1][col-1] = 'V';
						valorIngressoTotal += ingresso * 0.40;
					}
				}
			}else{
				if(verMeiaInt == 1){
					teatro[lin-1][col-1] = 'I';
					valorIngressoTotal += ingresso * 0.60;
				}else{
					teatro[lin-1][col-1] = 'M';
					valorIngressoTotal += ingresso/2 * 0.60;
				}
			}
			printf("\nSua venda/reserva foi validada com sucesso!\n");
			system("pause");
		}else{
			break;
		}
	}
}

void cancelar_lugar() {
	system("CLS");
	printf("\nCANCELAMENTO DE LUGARES\n");
	mostrar_mapa_modificado();
	validar = 1;
	while(validar == 1){
		printf("\nDigite a linha e coluna onde deseja cancelar, separadas por um espaço:");
		scanf("%i %i", &lin, &col);
		while( (lin < 1 or lin > linhas) and (col < 1 or col > colunas) ){
			printf("	Digite uma linha e coluna válidas: ");
			scanf("    %i %i", &lin, &col);
		}
		while(lin < 1 or lin > linhas){
			printf("	Digite uma linha válida: ");
			scanf("    %i", &lin);
		}
		while(col < 1 or col > colunas){
			printf("	Digite uma coluna válida: ");
			scanf("    %i", &col);
		}
		
		while(teatro[lin-1][col-1] == 'D'){
			printf("\nPOSIÇÃO JÁ DISPONIVEL\n");
			printf("\nDigite novamente a linha e coluna onde deseja CANCELAR, separadas por um espaço:");
			scanf("%i %i", &lin, &col);
			while( (lin < 1 or lin > linhas) and (col < 1 or col > colunas) ){
				printf("	Digite uma linha e coluna válidas: ");
				scanf("    %i %i", &lin, &col);
			}
			while(lin < 1 or lin > linhas){
				printf("	Digite uma linha válida: ");
				scanf("    %i", &lin);
			}
			while(col < 1 or col > colunas){
				printf("	Digite uma coluna válida: ");
				scanf("    %i", &col);
			}
		}
		
		printf("\nDeseja realmente validar o cancelamento? O local será disponibilizado e o dinheiro retirado (1 para sim e 2 para não): ");
		scanf("%i", &validar);
		while(validar < 1 or validar > 2){
			printf("	Digite uma opção válida: " );
			scanf("%i", &validar);
		}
		
		if(validar == 1){
			if(teatro[lin-1][col-1] == 'V'){
				teatro[lin-1][col-1] = 'D';
				valorIngressoTotal -= ingresso;
			}else if(teatro[lin-1][col-1] == 'v'){
				teatro[lin-1][col-1] = 'D';
				valorIngressoTotal -= ingresso/2;
			}else if(teatro[lin-1][col-1] == 'M'){
				teatro[lin-1][col-1] = 'D';
				valorIngressoTotal -= ingresso/2 * 0.6;
			}else{
				teatro[lin-1][col-1] = 'D';
				valorIngressoTotal -= ingresso * 0.6;
			}
			printf("\nSeu cancelamento foi validado com sucesso!\n");
			system("pause");
			break;
		}else{
			system("pause");
			break;
		}
	}
}

void verificar_parciais() {
	system("CLS");
	printf("\nVERIFICAÇÃO DE PARCIAIS\n");
	mostrar_mapa_modificado();
	disponivel = 0;
	vendaInteira = 0;
	vendaMeia = 0;
	reservaInteira = 0;
	reservaMeia = 0;
	totalUso = 0;
	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			if(teatro[i][j] == 'D'){
				disponivel += 1;
			}else{
				
				if(teatro[i][j] == 'V'){
					vendaInteira += 1;
				}else{
					
					if(teatro[i][j] == 'v'){
						vendaMeia += 1;
					}else{
						
						if(teatro[i][j] == 'I'){
							reservaInteira += 1;
						}else{
							
							reservaMeia += 1;
						}
					}
				}
			}
		}
	}
	printf("\nPARCIAIS DO TEATRO\n");
	printf("- Ingressos Disponíveis: %i", disponivel);
	printf("\n- Ingressos Inteiros Vendidos: %i", vendaInteira);
	printf("\n- Ingressos Meias Vendidos: %i", vendaMeia);
	printf("\n- Ingressos Inteiros Reservados: %i", reservaInteira);
	printf("\n- Ingressos Meias Reservados: %i\n", reservaMeia);
	printf("\n- Total de Dinheiro Arrecadado até o momento: %f\n", valorIngressoTotal);
	system("pause");
}

void verificar_espetaculo(){
	system("CLS");
	printf("\nVERIFICAÇÃO DE INICIALIZAÇÃO DO ESPETÁCULO\n\nOBS: o Espetáculo está apto para se inicializar quando mais de 60 por cento dos ingressos forem vendidos.\n");
	
	lugaresVendidos = 0;
	for(int i = 0; i < linhas; i++){
		for(int j = 0; j < colunas; j++){
			if(teatro[i][j] == 'V' or teatro[i][j] == 'v'){
				lugaresVendidos += 1;
			}
		}
	}
	
	printf("\nO total de lugares vendidos é %i.", lugaresVendidos);
	
	if(lugaresVendidos >= (linhas*colunas) * 0.6){
		podeIniciar = true;
		printf("\nO Espetáculo ESTÁ apto para ser realizado. \n");
	}else{
		podeIniciar = false;
		printf("\nO Espetáculo NÃO ESTÁ apto para ser realizado. \n");
	}
	system("pause");
}

void espetaculo() {
	printf("O espetáculo foi finalizado com arrecadação de %f, foi um sucesso!\n", valorIngressoTotal);
	processos = 0;
	system("pause");
}

int main() {
	while(inicio == 1){
		setlocale(LC_ALL, "");
		printf("Olá, começaremos agora o dia. \n");
		zerar_mapa();
		mostrar_mapa_inicial();
		printf("Por favor, digite o valor a ser cobrado pelo ingresso: ");
		scanf("%f", &ingresso);
		printf("Digite o número de linhas e colunas que deseja utilizar separadas por um espaço (Máximo linhas: 20; Máximo colunas: 25): ");
		scanf("%i %i", &linhas, &colunas);
		while( (linhas < 1 or linhas > 20) and (colunas < 0 or colunas > 25) ){
			printf("	Digite um número de linhas e colunas válidas: ");
			scanf("    %i %i", &linhas, &colunas);
		}
		while(linhas < 1 or linhas > 20){
			printf("	Digite um número de linhas válidas: ");
			scanf("    %i", &linhas);
		}
		while(colunas < 0 or colunas > 25){
			printf("	Digite um número de colunas válidas: ");
			scanf("    %i", &colunas);
		}
		
		processos = 1;
		while(processos == 1){
			for(int i = 0; i < linhas; i++){
				for(int j = 0; j < colunas; j++){
					if(teatro[i][j] == 'V' or teatro[i][j] == 'v'){
						lugaresVendidos += 1;
					}
				}
			}
			if(lugaresVendidos != linhas*colunas){
				system("CLS");
				mostrar_mapa_modificado();
				printf("Digite a opção desejada: \n\n1. Reservar ou comprar um lugar\n2. Cancelar a compra ou a reserva de um lugar\n3. Verificar estado e parciais do Teatro\n4. Verificação de inicio do espetáculo\n5. Iniciar o espetáculo \n\nR: ");
				scanf("%i", &opcao);
				while(opcao < 1 or opcao > 5){
					printf("Digite uma opção válida: ");
					scanf("%i", &opcao);
				}
				switch(opcao){
					case 1:
						reservar_comprar_lugar();
						break;
						
					case 2:
						cancelar_lugar();
						break;
						
					case 3:
						verificar_parciais();
						break;
			
					case 4:
						verificar_espetaculo();
						break;
						
					default:
						if(podeIniciar == true){
							espetaculo();
						}else{
							printf("\nO Espetáculo NÃO ESTÁ apto para ser realizado. Consulte a opção 4 para mais detalhes. \n");
							system("pause");
						}
						
						break;
				}
			}else{
				system("CLS");
				printf("O Teatro está lotado. Começaremos então o espetáculo. ");
				espetaculo();
			}
		}
		system("CLS");
		printf("Deseja recomeçar o dia? Se sim digite 1, se não, digite qualquer número: ");
		scanf("%i", &inicio);
	}
}
