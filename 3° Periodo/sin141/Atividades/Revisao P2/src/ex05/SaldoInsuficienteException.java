package ex05;

public class SaldoInsuficienteException extends Exception {

    public SaldoInsuficienteException(){
        super("Saldo insuficiente");
    }

    public SaldoInsuficienteException(String msg){
        super(msg);
    }
}
