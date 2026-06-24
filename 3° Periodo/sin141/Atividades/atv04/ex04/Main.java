package atv04.ex04;

public class Main {
    public static void main(String[] args) {
        Entrega[] entregas =
                {
                        new EntregaMoto(),
                        new EntregaCarro(),
                        new EntregaDrone()
                };

        ProcessadorEntrega processador = new ProcessadorEntrega();

        for(Entrega entrega : entregas) {
            processador.processar(entrega, 12);
        }
    }
}
