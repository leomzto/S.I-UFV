public class FormaBasica {
    private int x, y, cor, espessuraContorno, tipoContorno;

    public FormaBasica() {
        x = y = 0;
        cor = espessuraContorno = tipoContorno = 1;
    }

    public FormaBasica(int x, int y, int cor, int espessuraContorno, int tipoContorno) {
        setCor(cor);
        setX(x);
        setY(y);
        setEspessuraContorno(espessuraContorno);
        setTipoContorno(tipoContorno);
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public void setCor(int cor) {
        if (cor < 1 || cor > 5) this.cor = 1;
        else this.cor = cor;
    }

    public void setEspessuraContorno(int espessuraContorno) {
        if (espessuraContorno < 1 || espessuraContorno > 5) this.espessuraContorno = 1;
        else this.espessuraContorno = espessuraContorno;
    }

    public void setTipoContorno(int tipoContorno) {
        if (tipoContorno < 1 || tipoContorno > 2) this.tipoContorno = 1;
        else this.tipoContorno = tipoContorno;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getTipoContorno() {
        return tipoContorno;
    }

    public int getCor() {
        return cor;
    }

    public int getEspessuraContorno() {
        return espessuraContorno;
    }

    public void imprime() {

    }

}

public class Circulo extends FormaBasica {
    private double raio;

    public Circulo() {
        super();
        raio = 0.0;
    }

    public Circulo(int x, int y, int cor, int espessuraContorno, int tipoContorno, double raio) {
        super(x, y, cor, espessuraContorno, tipoContorno);

        setRaio(raio);
    }

    public void setRaio(double raio) {
        this.raio = raio;
    }

    public double getRaio() {
        return raio;
    }

    public double area() {
        return Math.PI * Math.pow(raio, 2);
    }
}

public class Retangulo extends FormaBasica {
    private int altura, largura;

    public Retangulo() {
        super();
        altura = largura = 0;
    }

    public Retangulo(int x, int y, int cor, int espessuraContorno, int tipoContorno, int altura, int largura) {
        super(x, y, cor, espessuraContorno, tipoContorno);

        setAltura(altura);
        setLargura(largura);
    }

    public int getAltura() {
        return altura;
    }

    public int getLargura() {
        return largura;
    }

    public void setAltura(int altura) {
        this.altura = altura;
    }

    public void setLargura(int largura) {
        this.largura = largura;
    }

    public int area() {
        return altura * largura;
    }
}

void main() {

}
