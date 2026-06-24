package atv05.ex02;

public class Main {

    public static void main(String[] args) {

        Calculo soma = (int a, int b) -> a + b;
        Calculo subtracao = (int a, int b) -> a - b;
        Calculo multiplicacao = (int a, int b) -> a * b;

        System.out.println("Soma: " + soma.executar(10, 5));
        System.out.println("Subtração: " + subtracao.executar(10, 5));
        System.out.println("Multiplicaçao: " + multiplicacao.executar(5, 10));

    }
}
