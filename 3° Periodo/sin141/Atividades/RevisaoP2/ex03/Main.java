package RevisaoP2.ex03;

public class Main {
    static void main(String[] args) {

        try {
            Forma[] formas = new Forma[3];

            formas[0] = new Circulo("Vermelho", 5, 5, 3.0);
            formas[1] = new Retangulo("Azul", 10, 20, 4.0, 5.0);
            formas[2] = new Triangulo("Verde", 0, 0, 6.0, 4.0);

            for (Forma f : formas) {
                f.exibirDados();
                System.out.println("Área: " + f.calcularArea());

                if (f instanceof Desenhavel) {
                    ((Desenhavel) f).desenhar();
                }
                System.out.println("---------------");
            }

            Forma errada = new Circulo("Rosa", 0, 0, -3.0);

        } catch (MedidaInvalidaException e) {
            System.out.println(e.getMessage());
        }
    }
}
