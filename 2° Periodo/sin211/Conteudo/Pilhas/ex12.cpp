#include "pilha.hpp"
#include <cctype>

/*
A conversão de números inteiros, na base 10, para outras bases numéricas se dá
através de sucessivas divisões de um dado valor n pelo valor da base desejada. Faça
um programa que obtenha a conversão numérica, de acordo com a opção do usuário,
utilizando uma pilha:

    (a) Decimal para Binário
    (b) Decimal para Octal
    (c) Decimal para Hexadecimal
*/

void converter_base(char op, int num)
{
    if (num == 0)
    {
        cout << "0";
        return;
    }

    auto converter = [](int num, int base) -> string
    {
        Pilha<char> pilha;
        string digitos = "0123456789ABCDEF";
    
        while (num > 0)
        {
            int resto = num % base;
            pilha.push(digitos[resto]);
            num /= base;
        }
    
        string resultado;
        while (!pilha.is_empty())
        {
            resultado += pilha.top();
            pilha.pop();
        }
    
        return resultado;
    };

    op = tolower(op);
    switch (op)
    {
        case 'a':
            cout << converter(num, 2) << endl;
            break;
        case 'b':
            cout << converter(num, 8) << endl;
            break;
        case 'c':
            cout << converter(num, 16) << endl;
            break;
        default:
            cout << "Opcao invalida" << endl;
            break;
    }
}