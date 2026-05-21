package ex07;

public class ServicoNotificacao {

    public void notificar(Notificavel meio, String mensagem) throws MensagemVaziaException {
        if (mensagem == null || mensagem.trim().isEmpty()) {
            throw new MensagemVaziaException("Erro: Não é possível enviar uma mensagem vazia.");
        }

        meio.enviar(mensagem);
    }
}
