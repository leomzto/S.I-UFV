package ex01;

public class Estagiario extends Funcionario {
    private double auxTransporte;

    public Estagiario() {
        super();
        this.auxTransporte = 0.0;
    }
    public Estagiario(String nome, double salarioBase, double auxTransporte) {
        super(nome, salarioBase);
        this.auxTransporte = auxTransporte;
    }
    public double getAuxTransporte() {
        return auxTransporte;
    }
    public void setAuxTransporte(double auxTransporte) {
        if(auxTransporte<0){
            this.auxTransporte = 0.0;
        }
        else{
            this.auxTransporte = auxTransporte;
        }
    }
    @Override
    public double calcularSalario() {
        return getSalario() + auxTransporte;
    }
}
