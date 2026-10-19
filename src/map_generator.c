/*P Posic¸ao inicial do jogador ˜
 E  Inimigos (1 ou mais)
 Z Plataformas
 S Subida de escada
 D Descida de escada
 F Porta (Final da Fase)
 H Escada (Nenhum efeito apenas sprite visual)
*/


/*
Seed de geração de mapas aleatórios
1. gera número aleatório de Z, intervalo de [2,28], para linha [3]
2. todo Z deve estar obrigatoriamente colado [linha] [coluna+1]
3. 2 char S na linha+1 de Z, gera número de [coluna_S] aleatório para cada S, primeiro S, no intervalo [Z_min,Z_max], segundo S [min:>Posicao_S + 2, max: Z_max]
4. Gera aleatório para cada linha+1 na coluna_s, char H no intervalo de [1,3]
5. Gera D, 1 D sempre na linha_h + 1
6. if linha == 28 --> linha 28 coluna_aleatoria == S ---> linha 29 coluna_aleatoria == F
6. loop to 1.
*/

    // for(int linha = 0; linha < TAMANHO_MATRIZ; linha++)
    // {
    //     //Instancia a primeira linha, deve sempre conter F e D(1 ou 2);
    //     if(linha == 0)
    //     {
    //         //Posicao de F
    //         int rand_pos_F = random_num(29,1);
    //         mapMatriz[1][rand_pos_F] = 'F';

    //         //Posicao de D, pode instanciar no máximo 2 char D na linha 1
    //         for(int D = 0; D < random_num(2,1);D++)
    //             mapMatriz[1][rand_pos_F + random_num(29,1)] = 'D';
    //     }
    //     else
    //     {
    //         for(int coluna = 0; coluna < TAMANHO_MATRIZ; coluna++)
    //         {
        
    //             mapMatriz[linha][coluna] = ' ';

    //         }
    //     }