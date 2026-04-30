package ex01;

public class Main {
    public static void main(String[] args) {
        Notificavel email = new Email();
        Notificavel sms = new SMS();

        email.enviarMensagem("TESTE EMAIL");
        sms.enviarMensagem("TESTE SMS");
    }
}
