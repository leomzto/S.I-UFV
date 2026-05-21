package ex02;

public class ProcessadorPagamento {
    public void executarPagamento(Pagamento pagamento, double valor) {
        System.out.println(pagamento.getDescricao());
        pagamento.processar(valor);
    }
}
