package ex03;

public class Retangulo extends Forma implements Desenhavel {

    private double altura, largura;

    public Retangulo() {
        super();
        this.altura = 0.0;
        this.largura = 0.0;
    }

    public Retangulo(String cor, int x, int y, double largura, double altura) throws MedidaInvalidaException {
        super(cor, x, y);
        if (largura <= 0 || altura <= 0) {
            throw new MedidaInvalidaException("A largura e a altura do retângulo devem ser maiores que zero.");
        }
        this.largura = largura;
        this.altura = altura;
    }

    public double getAltura() {return altura; }
    public double getLargura() { return largura; }

    public void setLargura(double largura) throws MedidaInvalidaException {
        if (largura <= 0) throw new MedidaInvalidaException("A largura deve ser maior que zero.");
        this.largura = largura;
    }
    public void setAltura(double altura) throws MedidaInvalidaException {
        if (altura <= 0) throw new MedidaInvalidaException("A altura deve ser maior que zero.");
        this.altura = altura;
    }

    @Override
    public double calcularArea() {
        return largura * altura;
    }
    @Override
    public void desenhar() {
        System.out.println("Desenhando um Retângulo de " + largura + "x" + altura);
    }
}
