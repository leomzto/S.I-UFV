package atv06.ex03;

public class SaldoInsuficienteException extends Exception {

    public SaldoInsuficienteException() {
        super("Saldo insuficiente");
    }

    public SaldoInsuficienteException(String message) {
        super(message);
    }
}
