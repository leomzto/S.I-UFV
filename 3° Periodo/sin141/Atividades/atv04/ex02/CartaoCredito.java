package atv04.ex02;

public class CartaoCredito implements FormaPagamento {

    @Override
    public void pagar(double valor) {
        System.out.println("Cartao passado no valor: " + valor);
    }
}
