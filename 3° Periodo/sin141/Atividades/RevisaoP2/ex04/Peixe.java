package RevisaoP2.ex04;

public class Peixe extends Animal implements Nadador {

    public Peixe() {
        super();
    }

    public Peixe(String nome, int idade) {
        super(nome, idade);
    }

    @Override
    public void emitirSom() {
        System.out.println("Som de peixe");
    }

    @Override
    public void nadar() {
        System.out.println("Peixe nadando");
    }
}
