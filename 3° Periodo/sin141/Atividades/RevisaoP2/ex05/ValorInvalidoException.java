package RevisaoP2.ex05;

public class ValorInvalidoException extends Exception {

    public ValorInvalidoException() {
        super("Valor invalido");
    }

    public ValorInvalidoException(String msg){
        super(msg);
    }
}
