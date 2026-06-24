package atv02;

import java.util.Scanner;

public class ex08 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Quantidade de notas: ");
        int qtd = scanner.nextInt();

        int[] notas = new int[qtd];
        for (int i = 0; i < qtd; i++) {
            System.out.printf("Digite o %d° numero:", i+1);
            notas[i] = scanner.nextInt();
        }

        int soma = 0;
        for (int nota : notas) {
            soma += nota;
        }

        double media = (double) soma/ qtd;
        System.out.printf("Media: %.2f%n", media);
        if (media >= 60) {
            System.out.println("Aprovado");
        }
        else {
            System.out.println("Reprovado");
        }

        scanner.close();
    }
}
