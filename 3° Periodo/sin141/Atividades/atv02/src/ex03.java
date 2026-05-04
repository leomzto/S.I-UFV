import java.util.Scanner;

public class ex03 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite um numero: ");
        int n = scanner.nextInt();

        if (n % 2 == 0) {
            System.out.println("Par");
        }
        else {
            System.out.println("Impar");
        }

        scanner.close();
    }
}
