package ex03;

public class Circulo extends Forma implements Desenhavel {

    private double raio;

    public Circulo() {
        super();
        this.raio = 0.0;
    }

    public Circulo(String cor, int x, int y, double raio) throws MedidaInvalidaException {
        super(cor, x, y);
        if (raio <= 0) {
            throw new MedidaInvalidaException("O raio do círculo deve ser maior que zero.");
        }
        this.raio = raio;
    }

    public double getRaio() { return raio; }

    public void setRaio(double raio) throws MedidaInvalidaException {
        if (raio <= 0) {
            throw new MedidaInvalidaException("O raio do círculo deve ser maior que zero.");
        }
        this.raio = raio;
    }

    @Override
    public double calcularArea() {
        return Math.PI * Math.pow(raio, 2);
    }
    @Override
    public void desenhar() {
        System.out.println("Desenhando um Círculo com raio " + raio);
    }
}
