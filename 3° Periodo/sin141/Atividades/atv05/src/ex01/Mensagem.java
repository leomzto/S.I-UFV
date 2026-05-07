package ex01;

public interface Mensagem {

    void enviar(String texto);

    default void mostrarAviso() {
        System.out.println("Preparando para enviar a mensagem...");
    }

    static boolean  validarMensagem(String texto) {
        return texto != null && !texto.isEmpty();
    }
}
