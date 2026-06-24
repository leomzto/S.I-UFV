public class Circulo {

    private int x, y, cor, espessuraContono, tipoContorno;
    private double raio;

    public Circulo () {
        x = y = 0;
        raio = 0.0;
        cor = espessuraContono = tipoContorno = 1;
    }

    public Circulo (int x, int y, int cor, int espessuraContono, int tipoContorno, double raio) {
        setPos(x, y);
        setCor(cor);
        setContorno(espessuraContono, tipoContorno);
        setRaio(raio);
    }

    public void setPos(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void setCor(int cor) {
        if (cor < 1 || cor > 5) this.cor = 1;
        else this.cor = cor;
    }

    public void setContorno(int espessuraContono, int tipoContorno) {
        if (espessuraContono < 1 || espessuraContono > 5) this.espessuraContono = 1;
        else this.espessuraContono = espessuraContono;

        if (tipoContorno < 1 || tipoContorno > 2) this.tipoContorno = 1;
        else this.tipoContorno = tipoContorno;
    }

    public void setRaio(double raio) {
        if (raio < 0) this.raio = 0;
        else this.raio = raio;
    }

    public double getRaio() {
        return raio;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getCor() {
        return cor;
    }

    public int getEspessuraContono() {
        return espessuraContono;
    }

    public int getTipoContorno() {
        return tipoContorno;
    }

    public double area(){
        return Math.PI * Math.pow(raio, 2);
    }

    public void imprime() {
        System.out.println("Pos x: " + x + "\nPos y: " + y);
        System.out.println("Cor: " + cor);
        System.out.println("Espessura Contorno: " + espessuraContono + "\nTipo Contorno: " + tipoContorno);
        System.out.println("Raio: " + raio);
        System.out.println("Area: " + area());
    }

}

void main() {
    Circulo c = new Circulo();

    c.setPos(5, 10);
    c.setCor(3);
    c.setContorno(4, 2);
    c.setRaio(4);

    c.imprime();
}