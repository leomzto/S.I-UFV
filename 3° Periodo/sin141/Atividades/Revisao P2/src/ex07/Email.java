package ex07;

public class Email implements Notificavel {
    @Override
    public void enviar(String mensagem) {
        System.out.println("E-mail enviado -> " + mensagem);
    }
}
