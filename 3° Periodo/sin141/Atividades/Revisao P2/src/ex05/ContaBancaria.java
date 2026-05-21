package ex05;

public class ContaBancaria {
    private double saldo;

    public ContaBancaria() {
        this.saldo = 0.0;
    }

    public ContaBancaria(double valor) throws ValorInvalidoException {
        if (valor <= 0) {
            throw new ValorInvalidoException("O valor a ser depositado deve ser maior que 0");
        }
        this.saldo = valor;
    }

    public double getSaldo() { return saldo; }
    public void setSaldo(double saldo) throws ValorInvalidoException {
        if (saldo <= 0) {
            throw new ValorInvalidoException("O valor a ser depositado deve ser maior que 0");
        }
        this.saldo = saldo;
    }

    public void depositar(double valor) throws ValorInvalidoException {
        if (valor <= 0) {
            throw new ValorInvalidoException("O valor a ser depositado deve ser maior que 0");
        }
        this.saldo += valor;
    }

    public void sacar(double valor) throws SaldoInsuficienteException, ValorInvalidoException {
        if (valor <= 0) {
            throw new ValorInvalidoException("O valor do saque deve ser maior que 0");
        }
        if (valor > this.saldo) {
            throw new SaldoInsuficienteException("Erro: Saldo insuficiente");
        }
        this.saldo -= valor;
    }

    public void exibirSaldo(){
        System.out.println("Saldo atual: " + this.saldo);
    }
}
