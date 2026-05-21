package ex04;

public class Passaro extends Animal implements Voador {

    public Passaro() {
        super();
    }

    public Passaro(String nome, int idade) {
        super(nome, idade);
    }

    @Override
    public void emitirSom() {
        System.out.println("Som de passaro");
    }

    @Override
    public void voar() {
        System.out.println("Passaro voando");
    }
}
