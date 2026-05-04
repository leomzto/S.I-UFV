import java.util.Scanner;

public class ex07 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] notas = new int[3];
        for (int i = 0; i < 3; i++) {
            System.out.printf("Digite o %d° numero:", i+1);
            notas[i] = scanner.nextInt();
        }

        int soma = 0;
        for (int nota : notas) {
            soma += nota;
        }

        if (soma >= 60) {
            System.out.println("Aprovado");
        }
        else {
            System.out.println("Reprovado");
        }

        scanner.close();
    }
}
