package RevisaoP2.ex04;

public class Pato extends Animal  implements Corredor, Nadador, Voador {

    public Pato() {
        super();
    }

    public Pato(String nome, int idade) {
        super(nome, idade);
    }

    @Override
    public void emitirSom() {
        System.out.println("Som de pato");
    }

    @Override
    public void voar() {
        System.out.println("Pato voando");
    }

    @Override
    public void nadar() {
        System.out.println("Pato nadando");
    }

    @Override
    public void correr() {
        System.out.println("Pato correndo");
    }
}