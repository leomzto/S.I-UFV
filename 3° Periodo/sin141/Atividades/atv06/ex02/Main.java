package atv06.ex02;

import java.util.Scanner;

public class Main {
    static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite sua idade: ");
        String entrada = scanner.nextLine();

        try {
            int idade = Integer.parseInt(entrada);

            if (idade < 0) {
                throw new IllegalArgumentException("Idade nao pode ser negativa");
            }

            System.out.println("Idade cadastrada com sucesso: " + idade);

        } catch (NumberFormatException e) {
            System.out.println("A idade informada não é um numero interido valido.");
        } catch (IllegalArgumentException e) {
            System.out.println("Erro de validacao: " + e.getMessage());
        } finally {
            scanner.close();

        }


    }
}
