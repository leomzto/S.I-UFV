package ex02;

public class Main {
    public static void main(String[] args) {
        FormaPagamento pix = new Pix();
        FormaPagamento cartao = new CartaoCredito();

        pix.pagar(100.00);
        cartao.pagar(49.90);
    }
}
