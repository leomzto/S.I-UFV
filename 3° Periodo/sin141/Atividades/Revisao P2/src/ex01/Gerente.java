package ex01;

public class Gerente extends Funcionario {

    private double bonus;

    public Gerente() {
        super();
        this.bonus = 0.0;
    }

    public Gerente(String nome, double salarioBase, double bonus) {
        super(nome, salarioBase);
        this.bonus = bonus;
    }
    public double getBonus() {
        return bonus;
    }
    public void setBonus(double bonus) {
        if(bonus < 0){
            bonus = 0.0;
        }
        else {
            this.bonus = bonus;
        }
    }
    @Override
    public double calcularSalario() {
        return getSalario() + bonus;
    }
}
