public class Fracao {

    private int numerador;
    private int denominador;

    public Fracao ()
    {
        numerador = 0;
        denominador = 1;
    }

    public Fracao (int numerador, int denominador) {
        if (denominador == 0) { this.denominador = 1;}

        else { this.denominador = denominador; }

        this.numerador = numerador;

        simplificar();
    }

    public void setFracao(int numerador, int denominador) {
        this.numerador = numerador;
        this.denominador = denominador;
    }

    public int getNumerador(){
        return numerador;
    }

    public int getDenominador() {
        return denominador;
    }

    public void imprimirFracao() {
        System.out.println(this.numerador + "/" + this.denominador);
    }

    public void imprimirDecimal() {
        System.out.println((double)this.numerador/this.denominador);
    }

    public int mdc(int a, int b) {
        return b == 0 ? a : mdc(b, a % b);
    }

    public void simplificar() {
        int mdc = mdc(this.numerador, this.denominador);

        this.numerador /= mdc;
        this.denominador /= mdc;
    }

    public Fracao somar(Fracao f) {
        int n = this.numerador * f.denominador + this.denominador * f.numerador;
        int d = f.denominador * this.denominador;

        return new Fracao (n, d);
    }

    public Fracao subtrair(Fracao f) {
        int n = this.numerador * f.denominador - this.denominador * f.numerador;
        int d = f.denominador * this.denominador;

        return new Fracao(n, d);
    }

    public Fracao multiplicar(Fracao f){
        int n = this.numerador * f.numerador;
        int d = this.denominador * f.denominador;

        return new Fracao(n, d);

    }

    public Fracao dividir(Fracao f){
        int n = this.numerador * f.denominador;
        int d = this.denominador * f.numerador;

        return new Fracao(n, d);

    }


}

void main() {

    Fracao f1 = new Fracao();
    f1.imprimirFracao();

    f1.setFracao(1, 2);
    f1.imprimirFracao();


}
