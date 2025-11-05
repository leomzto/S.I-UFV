/*
Dadas as operações de pilha inserir (I) e remover (R), escreva a configuração final
da pilha após as seguintes operações:
I(10), I(20), R, I(30), I(45), I(21), R, R.
*/

// I(10) ----- Pilha -> [10]
// I(20) ----- Pilha -> [10, 20]
// R ----- Pilha -> [10]
// I(30) ----- Pilha -> [10, 30]
// I(45) ----- Pilha -> [10, 30, 45]
// I(21) ----- Pilha -> [10, 30, 45, 21]
// R ----- Pilha -> [10, 30, 45]
// R ----- Pilha -> [10, 30]