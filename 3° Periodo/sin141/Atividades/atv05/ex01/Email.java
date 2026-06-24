package atv05.ex01;

public class Email implements Mensagem{

    @Override
    public void enviar(String texto) {
        System.out.println("Email enviado: " + texto);
    }
}

