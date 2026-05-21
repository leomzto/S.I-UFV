package ex02;

public class Main {
    public static void main(String[] args) {
        ProcessadorPagamento processador = new ProcessadorPagamento();
        processador.executarPagamento(new CartaoCredito("1234"), 200.0);
        processador.executarPagamento(new Boleto("999888777"), 150.0);
        processador.executarPagamento(new Pix("email@teste.com"), 75.0);
    }
}
