package RevisaoP2.ex07;

public class Main {
    static void main(String[] args) {
        ServicoNotificacao servico = new ServicoNotificacao();

        Notificavel email = new Email();
        Notificavel sms = new SMS();
        Notificavel push = new PushNotification();

        Notificavel wpp = mensagem -> System.out.println("Whatsapp -> " + mensagem);

        try {
            String msg = "Mensagem teste.";

            servico.notificar(email, msg);
            servico.notificar(sms, msg);
            servico.notificar(push, msg);
            servico.notificar(wpp, msg);

        } catch (MensagemVaziaException e) {
            System.err.println(e.getMessage());
        }

        try {
            servico.notificar(email, "");

        } catch (MensagemVaziaException e) {
            System.out.println("Erro capturado -> " + e.getMessage());
        }
    }
}
