package atv05.ex01;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Email email = new Email();

        email.mostrarAviso();

        Scanner scanner = new Scanner(System.in);
        System.out.print("Digite a mensagem: ");
        String msg = scanner.nextLine();

        if (Mensagem.validarMensagem(msg)) {
            email.enviar(msg);
        }
        else {
            System.out.println("Mensagem sem corpo");
        }


    }





}
