package ex03;

public class MedidaInvalidaException extends Exception {

    public MedidaInvalidaException() {
        super("Medida Invalida");
    }

    public MedidaInvalidaException(String msg) {
        super(msg);
    }
}
