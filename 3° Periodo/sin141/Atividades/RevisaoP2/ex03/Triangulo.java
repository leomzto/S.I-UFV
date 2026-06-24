package RevisaoP2.ex03;

public class Triangulo extends Forma implements Desenhavel {

    private double base, altura;

    public Triangulo() {
        super();
        this.base = 0.0;
        this.altura = 0.0;
    }

    public Triangulo(String cor, int x, int y, double base, double altura) throws MedidaInvalidaException {
        super(cor, x, y);
        if (base <= 0 || altura <= 0) {
            throw new MedidaInvalidaException("A base e a altura do triângulo devem ser maiores que zero.");
        }
        this.base = base;
        this.altura = altura;
    }

    public double getBase() { return base; }
    public double getAltura() {  return altura; }

    public void setBase(double base) throws MedidaInvalidaException {
        if (base <= 0) throw new MedidaInvalidaException("A base deve ser maior que zero.");
        this.base = base;
    }
    public void setAltura(double altura) throws MedidaInvalidaException {
        if (altura <= 0) throw new MedidaInvalidaException("A altura deve ser maior que zero.");
        this.altura = altura;
    }

    @Override
    public double calcularArea() {
        return (base * altura) / 2;
    }
    @Override
    public void desenhar() {
        System.out.println("Desenhando um Triângulo com base " + base + " e altura " + altura);
    }
}
