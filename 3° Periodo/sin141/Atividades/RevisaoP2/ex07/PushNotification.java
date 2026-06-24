package RevisaoP2.ex07;

public class PushNotification implements Notificavel {
    @Override
    public void enviar(String mensagem) {
        System.out.println("Push Notification -> " + mensagem);
    }
}