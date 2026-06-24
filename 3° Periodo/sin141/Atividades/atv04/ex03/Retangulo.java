package atv04.ex03;


public class Retangulo implements  Calculavel {
    private double base, altura;

    Retangulo(double base, double altura) {
        this.base = base;
        this.altura = altura;
    }

    @Override
    public double calcularArea() {
        return base * altura;
    }
}
