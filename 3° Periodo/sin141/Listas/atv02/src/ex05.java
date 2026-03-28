import java.util.Scanner;

public class ex05 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite sua altura (m): ");
        double a = scanner.nextDouble();

        System.out.print("Digite seu peso (kg): ");
        double p = scanner.nextDouble();

        double imc = p / (a * a);

        System.out.printf("IMC: %.2f%n", imc);

        if (imc < 18.5) {
            System.out.println("Magreza");
        } else if (imc >= 18.5 && imc <= 24.9) {
            System.out.println("Normal");
        } else if (imc >= 25 && imc <= 29.9) {
            System.out.println("Sobrepeso");
        } else if (imc >= 30 && imc <= 39.9) {
            System.out.println("Obesidade");
        } else {
            System.out.println("Obesidade grave");
        }

        scanner.close();
    }
}