package RevisaoP2.ex01;

public class Desenvolvedor extends Funcionario {
    private double horasExtra;

    public Desenvolvedor(){
        super();
        this.horasExtra = 0.0;
    }
    public Desenvolvedor(String nome, double salarioBase, double horasExtra) {
        super(nome, salarioBase);
        this.horasExtra = horasExtra;
    }
    public double getHorasExtra (){
        return horasExtra;
    }
    public void setHorasExtra(double horasExtra){
        if(horasExtra < 0){
            this.horasExtra = 0.0;
        }
        else {
            this.horasExtra = horasExtra;
        }
    }
    @Override
    public double calcularSalario(){
        return getSalario() + (int) 50 * horasExtra;
    }
}
