package atv02;

import java.util.Scanner;

public class ex06 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Distancia percorrida (km): ");
        int d = scanner.nextInt();

        System.out.print("Tempo gasto (h): ");
        int t = scanner.nextInt();

        int v = d/t;

        System.out.println("Velocidade = " + v);

        scanner.close();
    }
}
