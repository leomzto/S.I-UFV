package ex07;

public class SMS implements Notificavel {
    @Override
    public void enviar(String mensagem) {
        System.out.println("SMS enviado -> " + mensagem);
    }
}