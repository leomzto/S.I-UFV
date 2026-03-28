import java.util.Scanner;

public class ex04 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite um numero: ");
        int n = scanner.nextInt();

        if (n >= 0) {
            System.out.println("Positivo");
        }
        else {
            System.out.println("Negativo");
        }

        scanner.close();
    }
}
