package atv03;

import java.util.Scanner;

public class ex03 {
    public static class MaisJovem {
        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);

            String nomeMaisJovem = "";
            int menorIdade = Integer.MAX_VALUE;

            for (int i = 0; i < 5; i++) {
                System.out.print("Nome: ");
                String nome = scanner.next();

                System.out.print("Idade: ");
                int idade = scanner.nextInt();

                if (idade < menorIdade) {
                    menorIdade = idade;
                    nomeMaisJovem = nome;
                }
            }

            System.out.println("Pessoa mais jovem: " + nomeMaisJovem);
            System.out.println(("Idade: " + menorIdade));

            scanner.close();
        }
    }
}
