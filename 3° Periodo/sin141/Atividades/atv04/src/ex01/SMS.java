package ex01;

public class SMS implements Notificavel {

    @Override
    public void enviarMensagem(String mensagem) {
        System.out.println("ex01.SMS enviado: " + mensagem);
    }
}
