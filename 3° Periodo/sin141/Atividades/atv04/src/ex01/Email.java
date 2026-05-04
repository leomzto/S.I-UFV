package ex01;

public class Email implements Notificavel {

    @Override
    public void enviarMensagem(String mensagem) {
        System.out.println("ex01.Email enviado: " + mensagem);
    }
}
