package ex01;

public abstract class Funcionario {
    private String nome;
    private double salarioBase;

    public Funcionario(){
        this.nome = "";
        this.salarioBase = 0.0;
    }
    public Funcionario(String nome, double salarioBase){
        this.nome = nome;
        if(salarioBase < 0){
            this.salarioBase = 0;
        }
        else {
            this.salarioBase = salarioBase;
        }
    }
    public String getNome (){
        return nome;
    }
    public void setNome(String nome){
        this.nome = nome;
    }
    public double getSalario (){
        return salarioBase;
    }
    public void setSalarioBase(double salarioBase){
        if(salarioBase < 0){
            this.salarioBase = 0;
        }
        else{
            this.salarioBase = salarioBase;
        }
    }
    public void exibirDados(){
        System.out.println("Nome: " + nome);
        System.out.println("Salario: " + calcularSalario());
    }
    public abstract double calcularSalario();
}