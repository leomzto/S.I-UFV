package atv04.ex03;


public class Circulo implements Calculavel {
    double raio;

    Circulo(double raio) {
        this.raio = raio;
    }

    @Override
    public double calcularArea() {
        return Math.PI * Math.pow(raio, 2);
    }
}
