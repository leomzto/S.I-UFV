import java.util.Scanner;

public class ex02 {

    public static class Menu {
        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            int opc;

            do {
                System.out.println("1 - Tabuada");
                System.out.println("2 - Sequencia");
                System.out.println("3 - Sair");
                opc = scanner.nextInt();

                switch(opc) {
                    case 1:
                        int num;
                        do {
                            System.out.print("Digite um numero (1 a 10): ");
                            num = scanner.nextInt();
                        } while (num < 1 || num > 10);

                        for (int i = 1; i <=10; i++) {
                            System.out.println(num + " x " + i + " = " + (num * i));
                        }
                        break;

                    case 2:
                        for (int i = 1; i <= 10; i++) {
                            System.out.print(i + " ");
                        }
                        System.out.println();
                        break;
                }
            } while (opc != 3);

            scanner.close();
        }
    }
}
