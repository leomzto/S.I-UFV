package RevisaoP2.ex02;

public interface Pagamento {
    void processar(double valor);
    String getDescricao();
}
