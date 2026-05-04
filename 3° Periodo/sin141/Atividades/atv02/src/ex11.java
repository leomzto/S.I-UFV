class Animal {
    String nome;
    String especie;
    int idade;
    double peso;

    void emitirSom() {
        System.out.println(nome + " esta fazendo um som");
    }
}

public class ex11 {
    public static void main(String[] args) {

        Animal cachorro = new Animal();
        cachorro.nome = "Rex";
        cachorro.especie = "Cachorro";
        cachorro.idade = 5;
        cachorro.peso = 20.5;

        Animal gato = new Animal();
        gato.nome = "Mia";
        gato.especie = "Gato";
        gato.idade = 3;
        gato.peso = 4.2;

        Animal passaro = new Animal();
        passaro.nome = "Piu";
        passaro.especie = "Pássaro";
        passaro.idade = 1;
        passaro.peso = 0.3;

        Animal peixe = new Animal();
        peixe.nome = "Nemo";
        peixe.especie = "Peixe";
        peixe.idade = 2;
        peixe.peso = 0.5;

        Animal cavalo = new Animal();
        cavalo.nome = "Trovão";
        cavalo.especie = "Cavalo";
        cavalo.idade = 7;
        cavalo.peso = 400.0;

        cachorro.emitirSom();
        gato.emitirSom();
        passaro.emitirSom();
        peixe.emitirSom();
        cavalo.emitirSom();
    }
}