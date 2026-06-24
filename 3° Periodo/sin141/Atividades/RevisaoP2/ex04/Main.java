package RevisaoP2.ex04;

public class Main {
    public static void main(String[] args) {

        Animal[] animais = new Animal[4];
        animais[0] = new Cachorro("Cachorro", 5);
        animais[1] = new Passaro("Loro", 2);
        animais[2] = new Peixe("Nemo", 1);
        animais[3] = new Pato("Donald", 4);

        System.out.println("--- 1. Apresentação e Sons ---");
        for (Animal animal : animais) {
            animal.apresentar();
            animal.emitirSom();
            System.out.println("----------------------------------------------");
        }

        System.out.println("\n--- 2. Teste de Comportamentos das Interfaces ---");
        for (Animal animal : animais) {

            if (animal instanceof Voador) {
                ((Voador) animal).voar();
            }

            if (animal instanceof Nadador) {
                ((Nadador) animal).nadar();
            }

            if (animal instanceof Corredor) {
                ((Corredor) animal).correr();
            }
            System.out.println("----------------------------------------------");
        }
    }
}