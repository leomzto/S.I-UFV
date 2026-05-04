import java.util.Scanner;

public class ex01 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite o primeiro numero: ");
        int n1 = scanner.nextInt();

        System.out.print("Digite o segundo numero: ");
        int n2 = scanner.nextInt();

        int soma = n1 + n2;
        System.out.println(n1 + " + " + n2 + " = " + soma);

        scanner.close();
    }

}
