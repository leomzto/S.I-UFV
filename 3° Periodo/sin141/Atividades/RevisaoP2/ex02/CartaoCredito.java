package RevisaoP2.ex02;

public class CartaoCredito implements Pagamento {
    private String numeroCartao;

    public CartaoCredito(){
        this.numeroCartao = "";
    }
    public CartaoCredito(String numeroCartao){
        if(numeroCartao != null){
            this.numeroCartao = numeroCartao;
        }
        else{
            this.numeroCartao = "";
        }
    }
    public String getNumeroCartao() {
        return numeroCartao;
    }
    public void setNumeroCartao(String numeroCartao) {
        if(numeroCartao != null){
            this.numeroCartao = numeroCartao;
        }
        else{
            this.numeroCartao = "";
        }
    }
    @Override
    public void processar(double valor) {
        System.out.println("Processando valor: " + valor);
    }
    @Override
    public String getDescricao() {
        return "Pagado com Credito";
    }
}

