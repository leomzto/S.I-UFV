package atv04.ex03;


public class Main {
    public static void main(String[] args) {
        Calculavel[] formas =
                {
                        new Quadrado(4),
                        new Retangulo(3, 5),
                        new Circulo(2)
                };

        for(Calculavel forma : formas) {
            System.out.println("Area: " + forma.calcularArea());
        }
    }
}
