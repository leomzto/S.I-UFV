package ex03;

public class Quadrado implements Calculavel {
    private double lado;

    Quadrado(double lado) {
        this.lado = lado;
    }

    @Override
    public double calcularArea() {
        return lado * lado;
    }
}
