package ex02;

public class Boleto implements Pagamento {
    private String codBarras;

    public Boleto(){
        this.codBarras = "";
    }
    public Boleto(String codBarras){
        this.codBarras = codBarras;
    }
    public String getCodBarras() {
        return codBarras;
    }
    public void setCodBarras(String codBarras) {
        if(codBarras != null){
            this.codBarras = codBarras;
        }
        else{
            this.codBarras = "";
        }
    }
    @Override
    public void processar(double valor) {
        System.out.println("Processando valor: " + valor);
    }
    @Override
    public String getDescricao() {
        return "Pagado com Boleto";
    }
}
