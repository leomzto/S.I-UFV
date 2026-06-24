package RevisaoP2.ex04;

public class Cachorro extends Animal implements Corredor {

    public Cachorro() {
        super();
    }

    public Cachorro(String nome, int idade) {
        super(nome, idade);
    }

    @Override
    public void emitirSom() {
        System.out.println("Som de cachorro");
    }

    @Override
    public void correr() {
        System.out.println("Cachorro correndo.");
    }
}
