package ex03;

public abstract class Forma {
    private String cor;
    private int x;
    private int y;

    public Forma() {
        this.cor = "";
        this.x = 0;
        this.y = 0;
    }

    public Forma(String cor, int x, int y) {
        this.cor = cor;
        this.x = x;
        this.y = y;
    }

    public String getCor() { return cor; }
    public void setCor(String cor) { this.cor = cor; }
    public int getX() { return x; }
    public void setX(int x) { this.x = x; }
    public int getY() { return y; }
    public void setY(int y) { this.y = y; }

    public void exibirDados() {
        System.out.println("Cor: " + cor + " | Posição: (" + x + ", " + y + ")");
    }

    public abstract double calcularArea();
}

