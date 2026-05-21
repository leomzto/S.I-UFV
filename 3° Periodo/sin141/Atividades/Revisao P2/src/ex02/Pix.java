package ex02;

public class Pix implements Pagamento {
    private String chavePix;

    public Pix(){
        this.chavePix = "";
    }
    public Pix(String chavePix){
        if(chavePix != null){
            this.chavePix = chavePix;
        }
        else{
            this.chavePix = "";
        }
    }
    public String getChavePix() {
        return chavePix;
    }
    public void setChavePix(String chavePix){
        if(chavePix != null){
            this.chavePix = chavePix;
        }
        else{
            this.chavePix = "";
        }
    }
    @Override
    public void processar(double valor) {
        System.out.println("Processando valor: " + valor);
    }
    @Override
    public String getDescricao() {
        return "Pagado com Pix";
    }
}
