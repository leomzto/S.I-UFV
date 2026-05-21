package ex01;

public class Main {
    static void main(String[] args) {
        int aValido = 10;
        int bValido = 2;

        int bInvalido = 0;

        System.out.println(dividir(aValido, bValido));
        System.out.println(dividir(aValido, bInvalido));
    }

    public static int dividir(int a, int b) {
        try {
            return a / b;
        } catch (ArithmeticException e) {
            System.err.println("Erro: nao e possivel dividir por zero -> " + e.getMessage());
            return 0;
        }
    }
}
