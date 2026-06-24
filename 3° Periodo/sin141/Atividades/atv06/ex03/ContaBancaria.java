package atv06.ex03;

public class ContaBancaria {
    private double saldo;

    public ContaBancaria() {
        this.saldo = 0.0;
    }
    public ContaBancaria(double saldo) throws  IllegalArgumentException {
        if (saldo < 0) {
            throw new IllegalArgumentException("ERRO: Valor invalido.");
        }

        this.saldo = saldo;
    }

    public double getSaldo() { return saldo; }
    public void setSaldo(double saldo) throws  IllegalArgumentException {
        if (saldo < 0) {
            throw new IllegalArgumentException("ERRO: Valor invalido.");
        }
        this.saldo = saldo;
    }
    public void depositar(double valor) throws  IllegalArgumentException {
        if (valor < 0) {
            throw new IllegalArgumentException("ERRO: Valor invalido.");
        }
        this.saldo += valor;
    }
    public void sacar(double valor) throws SaldoInsuficienteException, IllegalArgumentException {
        if (valor <= 0) {
            throw new IllegalArgumentException("ERRO: Valor invalido.");
        }
        if (valor > this.saldo) {
            throw new SaldoInsuficienteException("ERRO: Saldo insuficiente.");
        }

        this.saldo -= valor;
    }
}
