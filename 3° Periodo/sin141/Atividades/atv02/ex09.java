/*
9. Utilize seus conhecimentos para criar um cenário para representar uma pessoa,
um menino e uma menina, respondendo as seguintes questões:
a. Quais são as características de pessoa, menino e menina?
b. Quais são as ações de uma pessoa?
c. Como ficaria a implementação deste cenário em Java?
*/

/*
a) Características
Pessoa: nome, idade, altura, peso
Menino: tudo de Pessoa + gostaDeFutebol (boolean)
Menina: tudo de Pessoa + gostaDeDancar (boolean)
b) Ações
Pessoa: falar(), comer(), dormir()
Menino: jogarFutebol()
Menina: dancar()
*/

// c)
package atv02;


class Pessoa {
    String nome;
    int idade;
    double altura;
    double peso;

    void falar() {
        System.out.println(nome + " está falando");
    }

    void comer() {
        System.out.println(nome + " está comendo");
    }

    void dormir() {
        System.out.println(nome + " está dormindo");
    }
}

class Menino extends Pessoa {
    boolean gostaDeFutebol;

    void jogarFutebol() {
        if (gostaDeFutebol) {
            System.out.println(nome + " está jogando futebol");
        } else {
            System.out.println(nome + " não gosta de futebol");
        }
    }
}

class Menina extends Pessoa {
    boolean gostaDeDancar;

    void dancar() {
        if (gostaDeDancar) {
            System.out.println(nome + " está dançando");
        } else {
            System.out.println(nome + " não gosta de dançar");
        }
    }
}

public class ex09 {
    public static void main(String[] args) {

        Menino menino = new Menino();
        menino.nome = "João";
        menino.idade = 10;
        menino.gostaDeFutebol = true;

        Menina menina = new Menina();
        menina.nome = "Maria";
        menina.idade = 9;
        menina.gostaDeDancar = true;

        menino.falar();
        menino.jogarFutebol();

        menina.falar();
        menina.dancar();
    }
}