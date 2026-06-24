package atv04.ex02;

public class Pix implements FormaPagamento {

    @Override
    public void pagar(double valor) {
        System.out.println("ex02.Pix enviado: " + valor);
    }
}
