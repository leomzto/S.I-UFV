package atv02;

import java.util.Scanner;

public class ex02 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite um numero par: ");
        int n = scanner.nextInt() + 2;

        if (n % 2 != 0) {
            System.out.println("Numero invalido, precisa ser par.");
        }
        System.out.println("Proximo par: " + n);

        scanner.close();
    }
}
